//
//  Parser.cpp
//  CSE335_Proj04
//
//  Created by Barend Ungrodt on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <string>
#include <stack>
#include "LogicExpr.h"
#include "Parser.h"

using namespace std;

LogicExpr* Parser::getParsed()
{
    if(m_logicExpressions.empty())
    {
        LogicExpr* top = m_logicExpressions.back();
        m_logicExpressions.pop();
        return top;
    }
}
