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

class AbstractBuilder
{
public:
    virtual void addParent(Node* l, Node* r) = 0;
    virtual void addBoolObj(std::string s ) = 0;
    virtual void addOperand(std::string s) = 0;
};

#endif /* defined(__CSE335_Proj04__AbstractBuilder__) */
