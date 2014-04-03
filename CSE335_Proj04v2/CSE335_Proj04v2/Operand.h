//
//  Operand.h
//  CSE335_Proj04v2
//
//  Created by Nick Durak on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj04v2__Operand__
#define __CSE335_Proj04v2__Operand__

#include <iostream>

#include "Node.h"

class Operand : public Node
{
public:
    Operand(std::string value) : Node(value){};
};

#endif /* defined(__CSE335_Proj04v2__Operand__) */
