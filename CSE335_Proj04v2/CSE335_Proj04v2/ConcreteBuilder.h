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

class ConcreteBuilder: public AbstractBuilder
{
public:
    ConcreteBuilder(){};
    virtual void addTrue();
    virtual void addFalse();
    virtual void addVariable(char c);
    virtual void addBoolExpr(char c);
    virtual void completeBuild();
    virtual bool validExpr();
    virtual LogicExpr* getLogicExpr();
    virtual ~ConcreteBuilder();
};

#endif /* defined(__CSE335_Proj04__ConcreteBuilder__) */
