//
//  AbstractBuilder.h
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj04__AbstractBuilder__
#define __CSE335_Proj04__AbstractBuilder__

#include "Node.h"
#include <string>

class LogicExpr;

class AbstractBuilder
{
public:
    //virtual void addBoolExpr(LogicExpr* l, LogicExpr* r) = 0;
    //virtual void addNegate(LogicExpr* expr) = 0;
    virtual void addTrue() = 0;
    virtual void addFalse() = 0;
    //virtual void addLiteral(std::string s) = 0;
    virtual void addVariable(char c) = 0;
    virtual void addBoolExpr(char c) = 0;
};

#endif /* defined(__CSE335_Proj04__AbstractBuilder__) */
