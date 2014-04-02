/******************************************************
 FILE: Implication.cpp
 
 ABSTRACT:
 Provides implementation of the Implication.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include "Implication.h"
#include "LogicExprVisitor.h"

Implication::Implication(const Implication& other): BoolExpr(other) {}

Implication & Implication::operator= (const Implication& other)
{
    return *this;
}


void Implication::accept(LogicExprVisitor *v)
{
    v->visitImplication(this);
}