//
//  AbstractBuilder.h
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj04__AbstractBuilder__
#define __CSE335_Proj04__AbstractBuilder__

#include <string>
#include <stack>

class LogicExpr;

class AbstractBuilder
{
public:
    virtual void addTrue() = 0;
    virtual void addFalse() = 0;
    virtual void addVariable(char c) = 0;
    virtual void addBoolExpr(char c) = 0;
    virtual void completeBuild() = 0;
    virtual LogicExpr* getLogicExpr() = 0;
    virtual ~AbstractBuilder() {};
protected:
    std::stack<char> m_operands;
    std::stack<LogicExpr*> m_logicExpressions;
};

#endif /* defined(__CSE335_Proj04__AbstractBuilder__) */
