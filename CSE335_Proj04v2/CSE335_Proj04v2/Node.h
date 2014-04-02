//
//  Node.h
//  CSE335_Proj04
//
//  Created by Nick Durak on 4/2/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef CSE335_Proj04_Node_h
#define CSE335_Proj04_Node_h

class Node{
private:
    std::string m_value;
    Node* m_left;
    Node* m_right;
    bool m_isParent;
    
public:
    Node(std::string value) : m_value(value), _isParent(false){};
    virtual std::string getValue() {return m_value;};
    virtual void setParent() {m_isParent = true;};
    virtual bool getIsParent() {return m_isParent;};
    virtual void setLeft(Node* l) {m_left = l;};
    virtual void setRight(Node* r) {m_right = r;};
    virtual Node* getLeft() {return m_left;};
    virtual Node* getRight() {return m_right;};
};



#endif
