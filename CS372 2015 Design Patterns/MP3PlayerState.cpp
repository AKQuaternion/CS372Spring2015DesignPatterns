//
//  MP3PlayerState.cpp
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/22/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include "MP3PlayerState.h"
#include "MP3Player.h"

void MP3PlayerState::setPlayerState(MP3Player *p, std::shared_ptr<MP3PlayerState> s)
{
    p->setState(s);
}

void MP3PlayerState::playRadio(MP3Player *p)
{
    p->playRadio();
}

void MP3PlayerState::stopRadio(MP3Player *p)    {
    p->stopRadio();
}

void MP3PlayerState::nextRadioStation(MP3Player *p)    {
    p->nextRadioStation();
}

void MP3PlayerState::playMp3(MP3Player *p)    {
    p->playMp3();
}

void MP3PlayerState::stopMp3(MP3Player *p)    {
    p->stopMp3();
}

void MP3PlayerState::nextMp3(MP3Player *p)    {
    p->nextMp3();
}
