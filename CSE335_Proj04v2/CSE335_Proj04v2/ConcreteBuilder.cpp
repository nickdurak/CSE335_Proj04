//
//  ConcreteBuilder.cpp
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "ConcreteBuilder.h"
#include <stack>
#include <string>

using namespace std;

std::stack<Node*> ConcreteBuilder::get_exprtree()
{
    return m_exprtree;
}


void ConcreteBuilder::addParent(Node *l, Node *r)
{
    get_exprtree().pop();
    
}


