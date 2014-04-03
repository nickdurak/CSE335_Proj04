//
//  BoolObj.h
//  CSE335_Proj04v2
//
//  Created by Nick Durak on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj04v2__BoolObj__
#define __CSE335_Proj04v2__BoolObj__

#include <iostream>

#include "Node.h"

class BoolObj : public Node
{
public:
    BoolObj(std::string value) : Node(value){};
};

#endif /* defined(__CSE335_Proj04v2__BoolObj__) */
