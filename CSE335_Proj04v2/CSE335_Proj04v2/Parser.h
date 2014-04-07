//
//  Parser.h
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj04__Parser__
#define __CSE335_Proj04__Parser__

#include <iostream>
#include <stack>

#include "ConcreteBuilder.h"

class LogicExpr;

class Parser
{
private:
    AbstractBuilder* b;
    
public:
    Parser() {};
    void setBuilder(AbstractBuilder* builder);
    bool parse(std::string input);
    LogicExpr* getParsed();
    virtual ~Parser() {};
};

#endif /* defined(__CSE335_Proj04__Parser__) */
