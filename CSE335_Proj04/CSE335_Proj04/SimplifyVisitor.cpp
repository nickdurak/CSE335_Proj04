/******************************************************
 FILE: SimplifyVisitor.cpp
 
 ABSTRACT:
 Provides implementation of the SimplifyVisitor.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include <iostream>
#include "SimplifyVisitor.h"
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
 Returns a string containing the simplified expression
 */
string SimplifyVisitor::getValue()
{
    if (m_myStack.size() == 0)
    {
        return "Please simplify expression first.";
    }
    string result = m_myStack.top();
    m_myStack.pop();
    return result;
}

bool SimplifyVisitor::stringToBool(std::string const& s)
{
    return (s != "0");
}

string SimplifyVisitor::boolToString(bool const& b)
{
    if (b == 0) return "0";
    return "1";
}

void SimplifyVisitor::visitLiteral(Literal* lit)
{
    if (lit->getValue())
    {
        m_myStack.push("1");
        return;
    }
    m_myStack.push("0");
}

void SimplifyVisitor::visitVariable(Variable* var)
{
    if (var->getAssigned())
    {
        if (var->getValue())
        {
            m_myStack.push("1");
            return;
        }
        m_myStack.push("0");
        return;
    }
    m_myStack.push(var->getName());
}

void SimplifyVisitor::visitNegate(Negate* neg)
{
    neg->getExpr()->accept(this);
    
    string val = m_myStack.top();
    m_myStack.pop();
    
    if ((val == "0") || (val == "1"))
    {
        bool v = stringToBool(val);
        
        m_myStack.push(boolToString(!v));
        return;
    }
    
    if (!(val[0] == '~'))
    {
        m_myStack.push("~" + val);
        return;
    }
    string newVal;
    for (int i = 1; i < val.size(); ++i)
    {
        newVal += val[i];
    }
    m_myStack.push(newVal);
    return;
}

void SimplifyVisitor::visitAnd(And* a)
{
    a->getRightExpr()->accept(this);
    a->getLeftExpr()->accept(this);
    
    string lval = m_myStack.top();
    m_myStack.pop();
    string rval = m_myStack.top();
    m_myStack.pop();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myStack.push(boolToString(l && r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myStack.push("0");
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push("0");
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myStack.push(lval);
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push(rval);
        return;
    }
    m_myStack.push("(" + lval + " & " + rval + ")");
}

void SimplifyVisitor::visitOr(Or* o)
{
    o->getRightExpr()->accept(this);
    o->getLeftExpr()->accept(this);

    string lval = m_myStack.top();
    m_myStack.pop();
    string rval = m_myStack.top();
    m_myStack.pop();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myStack.push(boolToString(l || r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myStack.push(lval);
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push(rval);
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myStack.push("1");
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push("1");
        return;
    }
    m_myStack.push("(" + lval + " | " + rval + ")");
}

void SimplifyVisitor::visitImplication(Implication* impl)
{
    impl->getRightExpr()->accept(this);
    impl->getLeftExpr()->accept(this);

    string lval = m_myStack.top();
    m_myStack.pop();
    string rval = m_myStack.top();
    m_myStack.pop();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myStack.push(boolToString(!l || r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myStack.push("~" + lval);
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push("1");
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myStack.push("1");
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push(rval);
        return;
    }
    m_myStack.push("(" + lval + " > " + rval + ")");
}

void SimplifyVisitor::visitEquivalence(Equivalence* equiv)
{
    equiv->getRightExpr()->accept(this);
    equiv->getLeftExpr()->accept(this);
    
    string lval = m_myStack.top();
    m_myStack.pop();
    string rval = m_myStack.top();
    m_myStack.pop();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myStack.push(boolToString(l == r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myStack.push("~" + lval);
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push("~" + rval);
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myStack.push(lval);
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myStack.push(rval);
        return;
    }
    m_myStack.push("(" + lval + " = " + rval + ")");
}
