//
//  main.cpp
//  CSE335_Proj04
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

using namespace std;

int main(int argc, const char * argv[])
{
    Variable* w = new Variable("w");
    Variable* x1 = new Variable("x");
    Variable* y1 = new Variable("y");
    Variable* z1 = new Variable("z");
    Variable* x2 = new Variable("x");
    Variable* y2 = new Variable("y");
    Variable* z2 = new Variable("z");
    
    LogicExpr* ex1 = new And(new Literal(true), new Literal(false));
    LogicExpr* ex2 = new Or(new Literal(true), new Literal(false));
    LogicExpr* ex3 = new Implication(new And(new Literal(true), new Literal(false)), new Or(new Literal(true), new Literal(false)));
    LogicExpr* ex4 = new Equivalence(new Negate(new Or(new Literal(true), new Literal(false))), new Literal(true));
    LogicExpr* ex5 = new Equivalence(new Implication(new And(x1, new Literal(true)), new Or(new Literal(false), y1) ), z1);
    LogicExpr* ex6 = new Equivalence(new Implication(new And(new Or(x2, y2), z2), new Or(new Negate(w), new Literal(false))), new Literal(true));
    
    EvaluateVisitor ev;
    PrintVisitor pv;
    SimplifyVisitor sv;
    
    cout.setf(ios::boolalpha);
    
    cout << "TEST SET ONE\n"
    << "____________\n";
    ex1->accept(&pv);
    ex1->accept(&ev);
    cout << " Evaluates to " << ev.getValue() << ".\n";
    ex2->accept(&pv);
    ex2->accept(&ev);
    cout << " Evaluates to " << ev.getValue() << ".\n";
    ex3->accept(&pv);
    ex3->accept(&ev);
    cout << " Evaluates to " << ev.getValue() << ".\n";
    ex4->accept(&pv);
    ex4->accept(&ev);
    cout << " Evaluates to " << ev.getValue() << ".\n";
    
    
    cout << "\nTEST SET TWO\n"
    << "____________\n";
    ex5->accept(&pv);
    cout << "\nsimplified version:  ";
    ex5->accept(&sv);
    cout << sv.getValue() << endl;
    bool tmp = 0;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter the value of x: ";
        cin >> tmp;
        x1->assign(tmp);
        cout << "Enter the value of y: ";
        cin >> tmp;
        y1->assign(tmp);
        cout << "Enter the value of z: ";
        cin >> tmp;
        z1->assign(tmp);
        
        cout << "Evaluation Result\n";
        ex5->accept(&pv);
        ex5->accept(&ev);
        cout << " evaluates to " << ev.getValue() << ".\n\n";
    }
    
    ex6->accept(&pv);
    cout << "\nsimplified version:  ";
    ex6->accept(&sv);
    cout << sv.getValue() << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter the value of x: ";
        cin >> tmp;
        x2->assign(tmp);
        cout << "Enter the value of y: ";
        cin >> tmp;
        y2->assign(tmp);
        cout << "Enter the value of z: ";
        cin >> tmp;
        z2->assign(tmp);
        cout << "Enter the value of w: ";
        cin >> tmp;
        w->assign(tmp);
        
        cout << "Evaluation Result\n";
        ex6->accept(&pv);
        ex6->accept(&ev);
        cout << " evaluates to " << ev.getValue() << ".\n\n";
    }
    
    delete ex1;
    delete ex2;
    delete ex3;
    delete ex4;
    delete ex5;
    delete ex6;
}


