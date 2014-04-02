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
#include "AbstractBuilder.h"
#include "LiteralObj.h"
#include "Operand.h"

class ConcreteBuilder: public AbstractBuilder
{
private:
    stack <Node*> m_exprtree;
public:
    ConcreteBuilder(){};
    virtual void addParent();
    virtual void addOperand(string s);
    virtual void addLiteralObj(string s);
};

#endif /* defined(__CSE335_Proj04__ConcreteBuilder__) */
