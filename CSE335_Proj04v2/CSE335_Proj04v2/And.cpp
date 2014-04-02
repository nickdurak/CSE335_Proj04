/******************************************************
 FILE: And.cpp
 
 ABSTRACT:
 Provides implementation of the And.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include "And.h"
#include "LogicExprVisitor.h"

/*
 copy constructor
 */
And::And(const And& other): BoolExpr(other) {}

/*
 assignment operator
 */
And & And::operator= (const And& other)
{
    return *this;
}


void And::accept(LogicExprVisitor *v)
{
    v->visitAnd(this);
}