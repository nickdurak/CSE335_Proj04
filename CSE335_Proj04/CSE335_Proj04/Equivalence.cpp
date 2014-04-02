/******************************************************
 FILE: Equivalence.cpp
 
 ABSTRACT:
 Provides implementation of the Equivalence.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include "Equivalence.h"
#include "LogicExprVisitor.h"

void Equivalence::accept(LogicExprVisitor *v)
{
    v->visitEquivalence(this);
}