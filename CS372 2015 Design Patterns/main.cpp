//
//  main.cpp
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 3/25/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;

#include "Strategy.h"
#include "Subject.h"
#include "Observer.h"
#include "Armor.h"
#include "Expression.h"

void testStrategy()
{
    unique_ptr<Monster> bob = std::make_unique<Zombie>();
    
    cout << bob->className() << endl;
    bob->move();
    
    unique_ptr<Monster> bill = std::make_unique<Orc>();
    
    cout << bill->className() << endl;
    bill->move();
    
    unique_ptr<Monster> chester = std::make_unique<Mimic>();
    
    cout << chester->className() << endl;
    chester->move();
}

void demoObserver()
{
    Subject sub;
    auto obs1 = make_shared<BarGraphObserver>();
    auto obs2 = make_shared<PrintObserver>();
    auto obs3 = make_shared<AlarmObserver>();
    
    sub.registerObserver(obs1);
    sub.registerObserver(obs2);
    sub.registerObserver(obs3);
    
    sub.updateObservers(5);
    sub.unregisterObserver(obs1);
    sub.updateObservers(100);
}

void demoDecorator()
{
    unique_ptr<Armor> plate = make_unique<PlateArmor>();
    unique_ptr<Armor> leather = make_unique<LeatherArmor>();
    unique_ptr<Armor> none = make_unique<NoArmor>();
    unique_ptr<Armor> magicPlate = make_unique<MagicDecorator>(make_unique<MagicDecorator>(make_unique<PlateArmor>()));
    
    cout << plate->description() << " has value " << plate->armorValue() << endl;
    cout << leather->description() << " has value " << leather->armorValue() << endl;
    cout << none->description() << " has value " << none->armorValue() << endl;
    cout << magicPlate->description() << " has value " << magicPlate->armorValue() << endl;
}

void show(const unique_ptr<Expr> &e)
{
    cout << e->toString() << " = " << e->evaluate() << endl;
}

int main(int argc, const char * argv[]) {

    unique_ptr<Expr> n1 = make_unique<Number>(5);
    unique_ptr<Expr> n2 = make_unique<Number>(3);
    unique_ptr<Expr> n3 = make_unique<Number>(6);
    unique_ptr<Expr> f1 = make_unique<Factor>(n1);
    unique_ptr<Expr> f2 = make_unique<Factor>(n2);
    unique_ptr<Expr> f3 = make_unique<Factor>(n3);
    unique_ptr<Expr> t1 = make_unique<Term>(f1);
    unique_ptr<Expr> t2 = make_unique<Term>(f2);
    unique_ptr<Expr> t3 = make_unique<ProductTerm>(t2,f3);
    unique_ptr<Expr> e1 = make_unique<Expr>(t1);
    unique_ptr<Expr> e2 = make_unique<SumExpr>(e1,t3);

    show(e2);
}
