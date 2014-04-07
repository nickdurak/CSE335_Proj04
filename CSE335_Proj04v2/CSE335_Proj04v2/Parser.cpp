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
#include "AbstractBuilder.h"
#include "ConcreteBuilder.h"
#include "Parser.h"

using namespace std;

void Parser::setBuilder(AbstractBuilder *builder)
{
    b = builder;
}

bool Parser::parse(string input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '~' || input[i] == '=' || input[i] == '&' || input[i] == '|' || input[i] == '>')
        {
            b->addBoolExpr(input[i]);
        }
        
        else
        {
            int j = i;
            if (input[i] == 't')
            {
                if (i < input.size() - 1)
                {
                    if (input[i + 1] == 'r')
                    {
                        b->addTrue();
                        i += 3;
                    }
                }
            }
            else if (input[i] == 'f')
            {
                if (i < input.size() - 1)
                {
                    if (input[i + 1] == 'a')
                    {
                        b->addFalse();
                        i += 4;
                    }
                }
            }
            if (j == i && input[i] != ' ')
            {
                b->addVariable(input[i]);
            }
        }
    }
    b->completeBuild();
    if (b->validExpr())
    {
        return true;
    }
    return false;
}

LogicExpr* Parser::getParsed()
{
    return b->getLogicExpr();
}