/******************************************************
 FILE: EvaluateVisitor.cpp
 
 ABSTRACT:
 Provides implementation of the EvaluateVisitor.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include <iostream>
#include <stack>
#include "EvaluateVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

using namespace std;

/*
 return the evaluted result
 */
bool EvaluateVisitor::getValue()
{
    if (m_myStack.size() == 0)
    {
        return false;
    }
    bool result = m_myStack.top();
    m_myStack.pop();
    return result;
}

void EvaluateVisitor::visitLiteral(Literal* lit)
{
    m_myStack.push(lit->getValue());
}

void EvaluateVisitor::visitVariable(Variable* var)
{
    if (var->getAssigned())
    {
        m_myStack.push(var->getValue());
        return;
    }
    bool assign;
    cout << "\tPlease assign a value (0 or 1) to " << var->getName() << ": ";
    cin >> assign;
    cin.ignore();
    var->assign(assign);
    m_myStack.push(var->getValue());
}

void EvaluateVisitor::visitNegate(Negate* neg)
{
    neg->getExpr()->accept(this);
    
    bool val = m_myStack.top();
    
    m_myStack.pop();
    m_myStack.push(!val);
}

void EvaluateVisitor::visitAnd(And* a)
{
    a->getLeftExpr()->accept(this);
    a->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(lval && rval);
}

void EvaluateVisitor::visitOr(Or* o)
{
    o->getLeftExpr()->accept(this);
    o->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(lval || rval);
}

void EvaluateVisitor::visitImplication(Implication* impl)
{
    impl->getLeftExpr()->accept(this);
    impl->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(!lval || rval);
}

void EvaluateVisitor::visitEquivalence(Equivalence* equiv)
{
    equiv->getLeftExpr()->accept(this);
    equiv->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(lval == rval);
}