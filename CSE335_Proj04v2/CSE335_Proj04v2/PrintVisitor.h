/******************************************************
 FILE: PrintVisitor.h
 
 ABSTRACT:
 Provides declaration for PrintVisitor.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__PrintVisitor__
#define __CSE335_Proj03__PrintVisitor__

#include <iostream>
#include "LogicExprVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

class PrintVisitor: public LogicExprVisitor
{
public:
    virtual void visitLiteral(Literal* lit);
    virtual void visitNegate(Negate* neg);
    virtual void visitVariable(Variable* var);
    virtual void visitAnd(And* a);
    virtual void visitOr(Or* o);
    virtual void visitImplication(Implication* impl);
    virtual void visitEquivalence(Equivalence* equiv);
    
};

#endif /* defined(__CSE335_Proj03__PrintVisitor__) */
