//
//  Composite.cpp
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/3/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include "Composite.h"
#include "Visitor.h"

int Folder::accept(Visitor *v) 
{
    return v->visit(this);
}

int File::accept(Visitor *v)
{
    return v->visit(this);
}