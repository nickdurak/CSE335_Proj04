/******************************************************
 FILE: BoolExpr.cpp
 
 ABSTRACT:
 Provides implementation of the BoolExpr.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

#include "BoolExpr.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

/*
 copy constructor
 */
BoolExpr::BoolExpr(const BoolExpr& other)
{
    m_leftPtr = other.m_leftPtr;
    m_rightPtr = other.m_rightPtr;
}

/*
 assignment operator
 */
BoolExpr& BoolExpr::operator= (const BoolExpr& other)
{
    if (this == &other)
    {
        return *this;
    }
    *m_rightPtr = *other.m_rightPtr;
    *m_leftPtr = *other.m_leftPtr;
    return *this;
}

/*
 return left pointer
 */
LogicExpr* BoolExpr::getLeftExpr() const
{
    return m_leftPtr;
}

/*
 return right pointer
 */
LogicExpr* BoolExpr::getRightExpr() const
{
    return m_rightPtr;
}

/*
 destructor
 */
BoolExpr::~BoolExpr()
{
    if (m_leftPtr != NULL)
    {
        delete m_leftPtr;
    }
    if (m_rightPtr != NULL)
    {
        delete m_rightPtr;
    }
}

