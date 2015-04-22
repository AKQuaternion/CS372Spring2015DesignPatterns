//
//  MP3Player.cpp
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/22/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include "MP3Player.h"

void MP3Player::setState(std::shared_ptr<MP3PlayerState> s)
{
    _state = s;
}
