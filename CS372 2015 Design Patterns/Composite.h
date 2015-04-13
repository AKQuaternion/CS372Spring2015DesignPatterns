//
//  Composite.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/3/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Composite__
#define __CS372_2015_Design_Patterns__Composite__
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::unique_ptr;

class Visitor;

class Composite
{
public:
    virtual ~Composite() = default;
    virtual int size() = 0;
    virtual string name() = 0;
    virtual int accept(Visitor *) = 0;
};

class File : public Composite
{
public:
    File(string name, int size):_name(name),_size(size)
    {}
    virtual int size() override
        {
        return _size;
        }
    
    virtual string name() override
        {
        return _name;
        }
    int accept(Visitor *) override;
private:
    string _name;
    int _size;
};

class Folder : public Composite
{
public:
    Folder(string name):_name(name)
    {}
    virtual int size() override
    {
        int total = 0;
        for(auto &i : _items)
            total += i->size();
        return total;
    }
    
    virtual string name() override
    {
        return _name;
    }
    
    void add(unique_ptr<Composite> c)
    {
        _items.push_back(move(c));
    }

    int accept(Visitor *v) override;
    
    const vector<unique_ptr<Composite>> & getChildren()
    {
        return _items;
    }
    
private:
    string _name;
    vector<unique_ptr<Composite>> _items;
};

#endif /* defined(__CS372_2015_Design_Patterns__Composite__) */
