/******************************************************
  FILE: Literal.h
 
  ABSTRACT:
  Provides declaration for Literal.
 
  AUTHOR:
  Nick Durak
  Barend Ungrodt
 
  CREATION DATE:
  11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__Literal__
#define __CSE335_Proj03__Literal__

#include <iostream>
#include "LogicExpr.h"

class LogicExprVisitor;

class Literal: public LogicExpr
{
private:
    bool m_value;
    
public:
    Literal(bool val = true): m_value(val) {};
    bool getValue() const;
    
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Literal__) */
