//
//  Visitor.cpp
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/8/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include "Visitor.h"
#include "Composite.h"
#include <iostream>
using std::cout;
using std::endl;

int SizeVisitor::visit(Folder *f)
{
const auto & children = f->getChildren();
int total=0;
for(const auto & child : children)
    total += child->accept(this);
return total;
}

int SizeVisitor::visit(File *f)
{
    return f->size();
}

int PrintVisitor::visit(Folder *f)
{
    tab();
    cout << f->name() << endl;
    ++_depth;
    const auto & children = f->getChildren();
    for(const auto & child : children)
        {
//        cout << _depth << endl;
        child->accept(this);
        }
    --_depth;
    return 0;
}

int PrintVisitor::visit(File *f)
{
    tab();
    cout << f->name() << endl;
    return 0;
}

void PrintVisitor::tab()
{
    for(int i=0;i<_depth;++i)
        cout << "    ";
}
