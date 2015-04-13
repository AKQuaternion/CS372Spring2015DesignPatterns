//
//  Command.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/13/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Command__
#define __CS372_2015_Design_Patterns__Command__

#include <iostream>
using std::cout;
using std::endl;
#include <initializer_list>
using std::initializer_list;
#include <vector>
using std::vector;
#include <functional>
using std::function;

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class HelloCommand : public Command
{
public:
    virtual void execute() override
    {
        cout << "Hello!" << endl;
        }
        };

class QuitCommand : public Command
{
public:
virtual void execute() override
    {
        exit(0);
    }
};

class MusicCommand : public Command
{
public:
    virtual void execute() override
    {
        cout << "Playing music..." << endl;
    }
};

class AnyCommand : public Command
{
public:
    AnyCommand(function<void ()> f):_f(f)
    {}
    
    virtual void execute() override
    {
        _f();
    }
private:
    function< void ()> _f;
};
        
class MacroCommand : public Command
{
public:
    MacroCommand(initializer_list<std::shared_ptr<Command>> commands):_commands(commands)
    {}
    
    virtual void execute() override
    {
        for(auto c:_commands) c->execute();
    }
    
private:
    vector<std::shared_ptr<Command>> _commands;
};
        
class Switchable
{
public:
    virtual ~Switchable() = default;
    virtual void on() = 0;
    virtual void off() = 0;
};

class Fan
{
public:
    void start()
    {
        cout << "Fan is on." << endl;
    }
    void stop()
    {
        cout << "Fan is off." << endl;
    }
};

class SwitchableFan : public Switchable
{
public:
    virtual void on() override
    {
        _f.start();
    }
    virtual void off() override
    {
        _f.stop();
    }
private:
    Fan _f;
};

class TV : public Switchable
{
public:
    virtual void on() override
    {
        cout << "TV is on." << endl;
    }
    virtual void off() override
    {
        cout << "TV is off." << endl;
    }
};

class Light : public Switchable
{
public:
    virtual void on() override
    {
        cout << "Light is on." << endl;
    }
    virtual void off() override
    {
        cout << "Light is off." << endl;
    }
};

class SwitchableCommand : public Command
{
public:
    virtual ~SwitchableCommand() = default;
    SwitchableCommand(Switchable *device):_device(device),_on(false)
    {}
    virtual void execute() override
    {
        if(_on)
            _device->off();
        else
            _device->on();
        _on = !_on;
    }

private:
    Switchable *_device;
    bool _on;
};

#endif /* defined(__CS372_2015_Design_Patterns__Command__) */
