/******************************************************
 FILE: Or.cpp
 
 ABSTRACT:
 Provides implementation of the Or.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include "Or.h"
#include "LogicExprVisitor.h"

Or::Or(const Or& other): BoolExpr(other) {}

Or & Or::operator= (const Or& other)
{
    return *this;
}

void Or::accept(LogicExprVisitor *v)
{
    v->visitOr(this);
}