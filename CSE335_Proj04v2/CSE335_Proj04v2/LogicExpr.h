/******************************************************
 FILE: LogicExpr.h
 
 ABSTRACT:
 Provides declaration for LogicExpr.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__LogicExpr__
#define __CSE335_Proj03__LogicExpr__

#include <iostream>

class LogicExprVisitor;

class LogicExpr
{
public:
    virtual void accept(LogicExprVisitor*) = 0;
    virtual ~LogicExpr() {};
};

#endif /* defined(__CSE335_Proj03__LogicExpr__) */
