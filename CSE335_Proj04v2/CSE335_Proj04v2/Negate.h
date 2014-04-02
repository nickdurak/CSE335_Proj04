/******************************************************
 FILE: Negate.h
 
 ABSTRACT:
 Provides declaration for Negate.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__Negate__
#define __CSE335_Proj03__Negate__

#include <iostream>
#include "LogicExpr.h"

class LogicExprVisitor;

class Negate: public LogicExpr
{
private:
    LogicExpr* m_exprPtr;
    
public:
    Negate(LogicExpr* expr): m_exprPtr(expr) {};
    Negate(const Negate& other);
    Negate& operator= (const Negate& other);
    virtual ~Negate() {delete m_exprPtr;};
    LogicExpr* getExpr() const;
    
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Negate__) */
