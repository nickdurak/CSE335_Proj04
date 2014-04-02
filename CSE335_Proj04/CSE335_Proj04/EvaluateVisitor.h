/******************************************************
 FILE: EvaluateVisitor.h
 
 ABSTRACT:
 Provides declaration for EvaluateVisitor.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__EvaluateVisitor__
#define __CSE335_Proj03__EvaluateVisitor__

#include <iostream>
#include <stack>
#include "LogicExprVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

class EvaluateVisitor: public LogicExprVisitor
{
private:
    std::stack<bool> m_myStack;
public:
    bool getValue();
    
    virtual void visitLiteral(Literal* lit);
    virtual void visitNegate(Negate* neg);
    virtual void visitVariable(Variable* var);
    virtual void visitAnd(And* a);
    virtual void visitOr(Or* o);
    virtual void visitImplication(Implication* impl);
    virtual void visitEquivalence(Equivalence* equiv);
    
};

#endif /* defined(__CSE335_Proj03__EvaluateVisitor__) */
