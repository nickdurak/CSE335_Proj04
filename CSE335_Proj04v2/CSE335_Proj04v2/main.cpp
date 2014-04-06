//
//  main.cpp
//  CSE335_Proj04v2
//
//  Created by Nick Durak on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//


#include <iostream>
#include <string>
#include "LogicExprVisitor.h"
#include "PrintVisitor.h"
#include "SimplifyVisitor.h"
#include "EvaluateVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"
#include "Parser.h"
#include "AbstractBuilder.h"
#include "ConcreteBuilder.h"

using namespace std;

int main(int argc, const char * argv[])
{
    string input;
    EvaluateVisitor ev;
    PrintVisitor pv;
    SimplifyVisitor sv;
    Parser p;
    
    cout.setf(ios::boolalpha);
    
    while (input != "END" && input != "end")
    {
        cout << "Enter a logical expresion without parenthisis:\n";
        getline(cin, input);
        cout << "\nOriginal input string: " << input;
        if (p.parse(input))
        {
            LogicExpr* tmp = p.getParsed();
            cout << "\nPrint (original form): ";
            tmp->accept(&pv);
            cout << "\nPrint (simplified form): ";
            tmp->accept(&sv);
            cout << sv.getValue();
            cout << "\nPrint (evaluated form): ";
            tmp->accept(&ev);
            cout << "\nthe equation evaluates to " << ev.getValue() << ".\n";
            delete tmp;
        }
        else
            cout << "\nThe input string does not contain a valid boolean expression\n\n";
    }
}
