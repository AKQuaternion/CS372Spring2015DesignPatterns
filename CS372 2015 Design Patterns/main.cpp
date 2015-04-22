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
using std::cin;

#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;
using std::move;

#include "Strategy.h"
#include "Subject.h"
#include "Observer.h"
#include "Armor.h"
#include "Expression.h"
#include "Composite.h"
#include "Visitor.h"
#include "Tree.h"
#include "Command.h"
#include "MP3Player.h"

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
    Context c;
    c["x"] = 5.6;
    cout << e->toString() << " = " << e->evaluate(c) << endl;
    c["x"] = 10000;
    cout << e->toString() << " = " << e->evaluate(c) << endl;
}

void testExpressions()
{
    
    unique_ptr<Number> n1 = make_unique<Number>(5);
    unique_ptr<Number> n2 = make_unique<Number>(3);
    unique_ptr<Number> n3 = make_unique<Number>(6);
    unique_ptr<Term> t3 = make_unique<ProductTerm>(move(n2),move(n3));
    unique_ptr<Expr> e1 = make_unique<SumExpr>(move(n1),move(t3));

    show(e1);

    unique_ptr<Expr> e2 = make_unique<SumExpr> (move(e1),make_unique<Variable>("x"));
    
    show(e2);
 
}

void testComposite()
{
    unique_ptr<Composite> f1 = make_unique<File>("Foo.txt",13);
    unique_ptr<Composite> f2 = make_unique<File>("Bar.txt",100);
    unique_ptr<Composite> f3 = make_unique<File>("Foo",1000);
    unique_ptr<Composite> f4 = make_unique<File>("Bar",10000);
    unique_ptr<Folder> folder = make_unique<Folder>("Text Files");
    unique_ptr<Folder> folder2 = make_unique<Folder>("All");

    folder->add(move(f1));
    folder->add(move(f2));
    folder2->add(move(folder));
    folder2->add(move(f3));
    folder2->add(move(f4));

    cout << folder2->name() << " has size " << folder2->size() << endl;

    SizeVisitor sv;
    cout << folder2->accept(&sv) << endl;
    
    PrintVisitor pv;
    folder2->accept(&pv);
}

void testNullObject()
{
    Node *root = new FullNode(1,new FullNode(2, new NullNode(),new NullNode()),
                                new FullNode(3, new FullNode(4,new NullNode(),new NullNode()),
                                                new FullNode(5,new NullNode(),new NullNode())));

    cout << root->size() << endl;
    delete root;
}

void testCommand()
{
    Light l1;
    TV t1;
    SwitchableFan f1;
    
    vector<shared_ptr<Command>> remote;
    
    remote.emplace_back(make_shared<HelloCommand>());
    remote.emplace_back(make_shared<MusicCommand>());
    remote.emplace_back(make_shared<SwitchableCommand>(&l1));
    remote.emplace_back(make_shared<SwitchableCommand>(&t1));
    remote.emplace_back(make_shared<SwitchableCommand>(&f1));
    remote.emplace_back(make_shared<MacroCommand>(std::initializer_list<shared_ptr<Command>>{remote[1],remote[2],remote[3]}));
    remote.emplace_back(make_shared<AnyCommand>(demoDecorator));
    remote.emplace_back(make_shared<AnyCommand>([](){cout << "Goodbye" << endl;}));
    remote.emplace_back(make_shared<QuitCommand>());
    
    while(1) {
        cout << "Press a button: ";
        int button;
        cin >> button;
        remote[button]->execute();
    }
}

void testMP3Player()
{
MP3Player m;

    m.pushSourceButton();
    m.pushNextButton();
    m.pushSourceButton();
    m.pushNextButton();

    m.pushSourceButton();
    m.pushNextButton();
}

int main(int argc, const char * argv[]) {
testMP3Player();
}
