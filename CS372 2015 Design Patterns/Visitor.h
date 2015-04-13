//
//  Visitor.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/8/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Visitor__
#define __CS372_2015_Design_Patterns__Visitor__

class Folder;
class File;

class Visitor
{
public:
    ~Visitor() = default;
    virtual int visit(Folder *f)=0;
    virtual int visit(File *f)=0;
private:
};

class SizeVisitor : public Visitor
{
    int visit(Folder *f) override;
    int visit(File *f) override;
};

class PrintVisitor : public Visitor
{
    int visit(Folder *f) override;
    int visit(File *f) override;
private:
    void tab();
    int _depth=0;
};

#endif /* defined(__CS372_2015_Design_Patterns__Visitor__) */
