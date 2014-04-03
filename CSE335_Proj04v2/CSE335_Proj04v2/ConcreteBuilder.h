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
#include "BoolObj.h"
#include "Operand.h"

class ConcreteBuilder: public AbstractBuilder
{
private:
    std::stack <Node*> m_exprtree;
public:
    std::stack<Node*> get_exprtree();
    ConcreteBuilder(){};
    virtual void addParent();
    virtual void addOperand(std::string s);
    virtual void addBoolObj(std::string s);
};

#endif /* defined(__CSE335_Proj04__ConcreteBuilder__) */
