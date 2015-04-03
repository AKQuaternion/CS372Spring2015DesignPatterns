//
//  Subject.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 3/27/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Subject__
#define __CS372_2015_Design_Patterns__Subject__
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include "Observer.h"

class Subject
{
public:
   void registerObserver(const shared_ptr<Observer> &obs)
   {
       _observers.push_back(obs);
   }
   
   void unregisterObserver(const shared_ptr<Observer> &obs)
   {
       _observers.erase(remove(_observers.begin(),_observers.end(),obs),_observers.end());
   }

   void updateObservers(int num)
   {
       for(auto observer:_observers)
           observer->update(num);
   }
   
private:
   vector<shared_ptr<Observer>> _observers;
};
#endif /* defined(__CS372_2015_Design_Patterns__Subject__) */
