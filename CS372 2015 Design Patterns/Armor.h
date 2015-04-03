//
//  Armor.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 3/30/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Armor__
#define __CS372_2015_Design_Patterns__Armor__
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;

class Armor
{
public:
    virtual ~Armor() = default;
    virtual int armorValue() = 0;
    virtual string description() = 0;

private:
};

class PlateArmor : public Armor
{
public:
    virtual int armorValue() override
    {
        return 10;
    }
    
    virtual string description() override
    {
        return "Plate Mail";
    }

private:
    
};

class LeatherArmor : public Armor
{
public:
    virtual int armorValue() override
    {
        return 3;
    }
    
    virtual string description() override
    {
        return "Leather";
    }
    
private:
    
};

class NoArmor : public Armor
{
public:
    virtual int armorValue() override
    {
        return 0;
    }
    
    virtual string description() override
    {
        return "None";
    }
    
private:
    
};

class ArmorDecorator : public Armor
{
public:
    ArmorDecorator(unique_ptr<Armor> decorated):_myArmor(std::move(decorated))
    {}
    virtual int armorValue() override = 0;
    virtual string description() override = 0;
    const unique_ptr<Armor> & getMyArmor()
    {return _myArmor;}
    
private:
    unique_ptr<Armor> _myArmor;
};

class MagicDecorator : public ArmorDecorator
{
public:
//using ArmorDecorator::ArmorDecorator;

    MagicDecorator(unique_ptr<Armor> decorated):ArmorDecorator(std::move(decorated))
    {}
    
    virtual int armorValue()
    {
        return getMyArmor()->armorValue() + 2;
    }
    
    virtual string description()
    {
        return "Magic " + getMyArmor()->description();
    }

private:
};
#endif /* defined(__CS372_2015_Design_Patterns__Armor__) */
