/******************************************************
 FILE: Or.h
 
 ABSTRACT:
 Provides declaration for Or.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__Or__
#define __CSE335_Proj03__Or__

#include <iostream>
#include "BoolExpr.h"

class LogicExprVisitor;

class Or: public BoolExpr
{
public:
    Or(LogicExpr* left, LogicExpr* right): BoolExpr(left, right) {};
    Or(const Or& other);
    Or& operator= (const Or& other);
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Or__) */
