//
//  ConcreteBuilder.h
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj04__ConcreteBuilder__
#define __CSE335_Proj04__ConcreteBuilder__

#include <stack>
#include <string>
#include "AbstractBuilder.h"
#include "LogicExpr.h"
//#include "BoolObj.h"
//#include "Operand.h"

class ConcreteBuilder: public AbstractBuilder
{
private:
    std::stack<char> m_operands;
    std::stack<LogicExpr*> m_logicExpressions;
public:
    ConcreteBuilder(){};
    virtual void addTrue();
    virtual void addFalse();
    virtual void addVariable(char c);
    virtual void addBoolExpr(char c);
    void completeBuild();
    bool validExpr();
    LogicExpr* getLogicExpr();
};

#endif /* defined(__CSE335_Proj04__ConcreteBuilder__) */
