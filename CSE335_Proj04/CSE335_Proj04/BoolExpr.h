/******************************************************
 FILE: BoolExpr.h
 
 ABSTRACT:
 Provides declaration for BoolExpr.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__BoolExpr__
#define __CSE335_Proj03__BoolExpr__

#include <iostream>
#include "LogicExpr.h"

class LogicExprVisitor;

class BoolExpr: public LogicExpr
{
private:
    LogicExpr* m_leftPtr;
    LogicExpr* m_rightPtr;
    
public:
    BoolExpr(LogicExpr* left, LogicExpr* right): m_leftPtr(left), m_rightPtr(right) {};
    BoolExpr(const BoolExpr& other);
    BoolExpr& operator= (const BoolExpr& other);
    virtual ~BoolExpr();
    
    LogicExpr* getLeftExpr() const;
    LogicExpr* getRightExpr() const;
};

#endif /* defined(__CSE335_Proj03__BoolExpr__) */
