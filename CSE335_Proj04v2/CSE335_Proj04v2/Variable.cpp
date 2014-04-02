/******************************************************
 FILE: Variable.cpp
 
 ABSTRACT:
 Provides implementation of the Variable.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include <string>
#include "Variable.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

using namespace std;

/*
 return value stored in Variable
 */
bool Variable::getValue() const
{
    return m_value;
}

/*
 return true if variable has been assigned
 */
bool Variable::getAssigned() const
{
    return m_assigned;
}

/*
 return the name of the variable
 */
string Variable::getName() const
{
    return m_name;
}

/*
 Assign a value to the variable
 */
void Variable::assign(bool val)
{
    m_value = val;
    m_assigned = true;
}

/*
 hook for visitor patern
 */
void Variable::accept(LogicExprVisitor* v)
{
    v->visitVariable(this);
}