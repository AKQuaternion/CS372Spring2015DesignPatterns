//
//  MP3PlayerStateDerivedClasses.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/22/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__MP3PlayerStateDerivedClasses__
#define __CS372_2015_Design_Patterns__MP3PlayerStateDerivedClasses__

#include "MP3Player.h"
#include "MP3PlayerState.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class StandbyState : public MP3PlayerState
{
public:
    StandbyState() = default;
    ~StandbyState() = default;
    virtual void nextButton(MP3Player *player) override;
    virtual void sourceButton(MP3Player *player) override;
};

class PlaylistState : public MP3PlayerState
{
public:
    virtual void nextButton(MP3Player *player) override;
    virtual void sourceButton(MP3Player *player) override;
};

class RadioState : public MP3PlayerState
{
public:
    virtual void nextButton(MP3Player *player) override;
    virtual void sourceButton(MP3Player *player) override;
};



#endif /* defined(__CS372_2015_Design_Patterns__MP3PlayerStateDerivedClasses__) */
