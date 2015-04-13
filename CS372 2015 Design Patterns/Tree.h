//
//  Tree.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/10/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Tree__
#define __CS372_2015_Design_Patterns__Tree__

class Node
{
public:
    virtual Node * getLeft() =0;
    virtual Node * getRight()=0;
    virtual ~Node()=default;

    virtual int size()=0;
};

class FullNode : public Node
{
public:
    FullNode(int data, Node *left, Node *right):_data(data),_left(left),_right(right)
    {}
    Node * getLeft()
    {
        return _left;
    }
    Node * getRight()
    {
        return _right;
    }
    ~FullNode()
    {
        delete _right;
        delete _left;
    }
    int size()
    {
    return 1 + _left->size() + _right->size();
    }

private:
    Node *_left;
    Node *_right;
    int _data;
};

class NullNode : public Node
{
public:
    virtual int size() override
    {
    return 0;
    }
    
    virtual Node * getLeft() override
    {
        return this;
    }

    virtual Node * getRight() override
    {
        return this;
    }
};
#endif /* defined(__CS372_2015_Design_Patterns__Tree__) */
