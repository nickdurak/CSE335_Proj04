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
class LogicExpr;

class Parser
{
private:
    std::stack<std::string> m_operands;
    std::stack<LogicExpr*> m_logicExpressions;
    std::string m_input;
    
public:
    Parser(std::string s): m_input(s){};
    virtual void parse();
    LogicExpr* getParsed();
    
};

#endif /* defined(__CSE335_Proj04__Parser__) */
