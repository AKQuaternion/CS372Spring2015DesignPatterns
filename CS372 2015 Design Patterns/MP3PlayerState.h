//
//  MP3PlayerState.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/22/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__MP3PlayerState__
#define __CS372_2015_Design_Patterns__MP3PlayerState__
#include <memory>

class MP3Player;

class MP3PlayerState
{
public:
    virtual ~MP3PlayerState() = default;
    virtual void nextButton(MP3Player *)=0;
    virtual void sourceButton(MP3Player *)=0;
protected:
    void setPlayerState(MP3Player *p, std::shared_ptr<MP3PlayerState> s);
    void playRadio(MP3Player *p);
    void stopRadio(MP3Player *p);
    void nextRadioStation(MP3Player *p);
    void playMp3(MP3Player *p);
    void stopMp3(MP3Player *p);
    void nextMp3(MP3Player *p);
    
private:

};

#endif /* defined(__CS372_2015_Design_Patterns__MP3PlayerState__) */
