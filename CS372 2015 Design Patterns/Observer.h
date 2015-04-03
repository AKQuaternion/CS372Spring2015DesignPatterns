//
//  Observer.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 3/27/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Observer__
#define __CS372_2015_Design_Patterns__Observer__
#include <iostream>
using std::cout;
using std::endl;

class Observer
{
public:
    virtual void update(int) = 0;
    virtual ~Observer() = default;

private:
};

class BarGraphObserver : public Observer
{
public:
    void update(int x) override
    {
        for(int i=0;i<x;++i)
            cout << "*";
        cout << endl;
    }
};

class PrintObserver : public Observer
{
public:
    void update(int x) override
    {
        cout << x << endl;
    }
};

class AlarmObserver : public Observer
{
public:
    void update(int x) override
    {
        if (x>50) cout << "ALARM!!!!" << endl;
    }
};


#endif /* defined(__CS372_2015_Design_Patterns__Observer__) */
