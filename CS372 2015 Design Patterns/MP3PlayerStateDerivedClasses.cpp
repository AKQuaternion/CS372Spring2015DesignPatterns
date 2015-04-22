//
//  MP3PlayerStateDerivedClasses.cpp
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/22/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include "MP3Player.h"
#include "MP3PlayerState.h"
#include "MP3PlayerStateDerivedClasses.h"

void StandbyState::nextButton(MP3Player *player)
{
}

void StandbyState::sourceButton(MP3Player *player)
{
    setPlayerState(player, make_shared<RadioState>());
    playRadio(player);
}

void PlaylistState::nextButton(MP3Player *player)
{
    nextMp3(player);
}

void PlaylistState::sourceButton(MP3Player *player)
{
    setPlayerState(player, make_shared<StandbyState>());
    stopMp3(player);
}

void RadioState::nextButton(MP3Player *player)
{
    nextRadioStation(player);
}

void RadioState::sourceButton(MP3Player *player)
{
    setPlayerState(player, make_shared<PlaylistState>());
    stopRadio(player);
    playMp3(player);
}
