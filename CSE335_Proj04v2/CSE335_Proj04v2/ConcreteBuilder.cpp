//
//  ConcreteBuilder.cpp
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <stack>
#include <string>
#include "ConcreteBuilder.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

using namespace std;

void ConcreteBuilder::addBoolExpr(char c)
{
    if(!m_operands.empty())
    {
        if(m_operands.top() == '~')
        {
            if (c == '=' || c == '>' || c == '&' || c == '|')
            {
                m_operands.pop();
                LogicExpr* expr = m_logicExpressions.top();
                m_logicExpressions.pop();
                m_logicExpressions.push(new Negate(expr));
            }
        }
        else if(m_operands.top() == '=')
        {
            if (c == '>' || c == '&' || c == '|')
            {
                m_operands.pop();
                LogicExpr* right = m_logicExpressions.top();
                m_logicExpressions.pop();
                LogicExpr* left = m_logicExpressions.top();
                m_logicExpressions.pop();
                m_logicExpressions.push(new Equivalence(left, right));
            }
        }
        else if(m_operands.top() == '>')
        {
            if (c == '&' || c == '|')
            {
                m_operands.pop();
                LogicExpr* right = m_logicExpressions.top();
                m_logicExpressions.pop();
                LogicExpr* left = m_logicExpressions.top();
                m_logicExpressions.pop();
                m_logicExpressions.push(new Implication(left, right));
            }
        }
        else if(m_operands.top() == '&')
        {
            if (c == '|')
            {
                m_operands.pop();
                LogicExpr* right = m_logicExpressions.top();
                m_logicExpressions.pop();
                LogicExpr* left = m_logicExpressions.top();
                m_logicExpressions.pop();
                m_logicExpressions.push(new And(left, right));
            }
        }
    }
    m_operands.push(c);
}

void ConcreteBuilder::addTrue()
{
    m_logicExpressions.push(new Literal(true));
}

void ConcreteBuilder::addFalse()
{
    m_logicExpressions.push(new Literal(false));
}

void ConcreteBuilder::addVariable(char c)
{
    string tmp = "";
    tmp += c;
    m_logicExpressions.push(new Variable(tmp));
}

void ConcreteBuilder::completeBuild()
{
    while (!m_operands.empty())
    {
        if(m_operands.top() == '~')
        {
            m_operands.pop();
            LogicExpr* expr = m_logicExpressions.top();
            m_logicExpressions.pop();
            m_logicExpressions.push(new Negate(expr));
        }
        else if(m_operands.top() == '=')
        {
            m_operands.pop();
            LogicExpr* right = m_logicExpressions.top();
            m_logicExpressions.pop();
            LogicExpr* left = m_logicExpressions.top();
            m_logicExpressions.pop();
            m_logicExpressions.push(new Equivalence(left, right));
        }
        else if(m_operands.top() == '>')
        {
            m_operands.pop();
            LogicExpr* right = m_logicExpressions.top();
            m_logicExpressions.pop();
            LogicExpr* left = m_logicExpressions.top();
            m_logicExpressions.pop();
            m_logicExpressions.push(new Implication(left, right));
        }
        else if(m_operands.top() == '&')
        {
            m_operands.pop();
            LogicExpr* right = m_logicExpressions.top();
            m_logicExpressions.pop();
            LogicExpr* left = m_logicExpressions.top();
            m_logicExpressions.pop();
            m_logicExpressions.push(new And(left, right));
        }
        else
        {
            m_operands.pop();
            LogicExpr* right = m_logicExpressions.top();
            m_logicExpressions.pop();
            LogicExpr* left = m_logicExpressions.top();
            m_logicExpressions.pop();
            m_logicExpressions.push(new Or(left, right));
        }
    }
}


bool ConcreteBuilder::validExpr()
{
    if(m_logicExpressions.size() == 1 && m_operands.size() == 0)
        return true;
    return false;
}


LogicExpr* ConcreteBuilder::getLogicExpr()
{
    if(!m_logicExpressions.empty())
    {
        LogicExpr* top = m_logicExpressions.top();
        m_logicExpressions.pop();
        return top;
    }
    else return nullptr;
}

ConcreteBuilder::~ConcreteBuilder()
{
    while (!m_logicExpressions.empty())
    {
        LogicExpr* top = m_logicExpressions.top();
        m_logicExpressions.pop();
        delete top;
    }
    while (!m_operands.empty())
    {
        m_operands.pop();
    }
}


