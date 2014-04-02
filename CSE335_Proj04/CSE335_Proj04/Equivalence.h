/******************************************************
 FILE: Equivalence.h
 
 ABSTRACT:
 Provides declaration for Equivalence.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__Equivalence__
#define __CSE335_Proj03__Equivalence__

#include <iostream>
#include "BoolExpr.h"

class LogicExprVisitor;

class Equivalence: public BoolExpr
{
public:
    Equivalence(LogicExpr* left, LogicExpr* right): BoolExpr(left, right) {};
    Equivalence(const Equivalence& other);
    Equivalence& operator= (const Equivalence& other);
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Equivalence__) */
