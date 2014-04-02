/******************************************************
 FILE: And.h
 
 ABSTRACT:
 Provides declaration for And.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__And__
#define __CSE335_Proj03__And__

#include <iostream>
#include "BoolExpr.h"

class LogicExprVisitor;

class And: public BoolExpr
{
public:
    And(LogicExpr* left, LogicExpr* right): BoolExpr(left, right) {};
    And(const And& other);
    And& operator= (const And& other);
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__And__) */
