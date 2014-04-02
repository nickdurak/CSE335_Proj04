/******************************************************
 FILE: Implication.h
 
 ABSTRACT:
 Provides declaration for Implication.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__Implication__
#define __CSE335_Proj03__Implication__

#include <iostream>
#include "BoolExpr.h"

class LogicExprVisitImplication;

class Implication: public BoolExpr
{
public:
    Implication(LogicExpr* left, LogicExpr* right): BoolExpr(left, right) {};
    Implication(const Implication& other);
    Implication& operator= (const Implication& other);
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Implication__) */
