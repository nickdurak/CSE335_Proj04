/******************************************************
 FILE: LogicExprVisitor.h
 
 ABSTRACT:
 Provides declaration for LogicExprVisitor.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#ifndef __CSE335_Proj03__LogicExprVisitor__
#define __CSE335_Proj03__LogicExprVisitor__

#include <iostream>

class Literal;
class Variable;
class Negate;
class And;
class Or;
class Implication;
class Equivalence;

class LogicExprVisitor
{
public:
    virtual void visitLiteral(Literal*) = 0;
    virtual void visitVariable(Variable*) = 0;
    virtual void visitNegate(Negate*) = 0;
    virtual void visitAnd(And*) = 0;
    virtual void visitOr(Or*) = 0;
    virtual void visitImplication(Implication*) = 0;
    virtual void visitEquivalence(Equivalence*) = 0;
    virtual ~LogicExprVisitor() {};
};

#endif /* defined(__CSE335_Proj03__LogicExprVisitor__) */
