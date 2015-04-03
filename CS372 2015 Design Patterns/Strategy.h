//
//  Strategy.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 3/27/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Strategy__
#define __CS372_2015_Design_Patterns__Strategy__

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;

class MoveBehavior {
public:
    virtual ~MoveBehavior() = default;
    virtual void move() = 0;
};

class NormalMoveBehavior : public MoveBehavior
{
    void move() override
    {
        cout << " moves normally." << endl;
    }
};

class DoesntMoveBehavior : public MoveBehavior
{
    void move() override
    {
        cout << " doesn't move." << endl;
    }
};

class Monster
{
public:
    virtual ~Monster() = default;
    virtual string className() = 0;
    void move()
    {
        _moveBehavior->move();
    }
protected:
    void setMoveBehavior(unique_ptr<MoveBehavior> myMB)
    {
        _moveBehavior = std::move(myMB);
    }
private:
    unique_ptr<MoveBehavior> _moveBehavior;
};

class Zombie : public Monster
{
public:
    Zombie()
    {
        setMoveBehavior(make_unique<NormalMoveBehavior>());
    }
    
    virtual string className() override
    {
        return "Zombie";
    }
    
};

class Orc : public Monster
{
public:
    Orc()
    {
        setMoveBehavior(make_unique<NormalMoveBehavior>());
    }
    
    virtual string className() override
    {
        return "Orc";
    }
};

class Mimic : public Monster
{
public:
    Mimic()
    {
        setMoveBehavior(make_unique<DoesntMoveBehavior>());
    }
    
    virtual string className() override
    {
        return "Mimic";
    }
};

#endif /* defined(__CS372_2015_Design_Patterns__Strategy__) */
