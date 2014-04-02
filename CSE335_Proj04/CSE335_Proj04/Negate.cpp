/******************************************************
 FILE: Negate.cpp
 
 ABSTRACT:
 Provides implementation of the Negate.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include "Negate.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

Negate::Negate(const Negate& other)
{
    m_exprPtr = other.m_exprPtr;
}

Negate& Negate::operator= (const Negate& other)
{
    if (this == &other)
    {
        return *this;
    }
    *m_exprPtr = *other.m_exprPtr;
    return *this;
}

LogicExpr* Negate::getExpr() const
{
    return m_exprPtr;
}

void Negate::accept(LogicExprVisitor* v)
{
    v->visitNegate(this);
}