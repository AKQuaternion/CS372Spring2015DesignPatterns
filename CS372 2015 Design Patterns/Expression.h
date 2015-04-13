//
//  Expression.h
//  CS372 2015 Design Patterns
//
//  Created by Chris Hartman on 4/1/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#ifndef __CS372_2015_Design_Patterns__Expression__
#define __CS372_2015_Design_Patterns__Expression__
#include <memory>
using std::unique_ptr;
using std::move;
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <map>
using Context = std::map<string,double>;
#include <exception>

// E -> E + T | E - T | T
// T -> T * F | T / F | F
// F -> ( E ) | number | identifier


class Expr
{
public:
    virtual ~Expr() = default;
    virtual double evaluate(const Context &c) = 0;
    virtual string toString() = 0;
};

class Term : public Expr
{
};

class Factor : public Term
{
};

class SumExpr : public Expr
{
public:
    SumExpr(unique_ptr<Expr> e, unique_ptr<Term> t):_e(move(e)),_t(move(t))
    {}
    virtual double evaluate(const Context &c) override
    {
        return _e->evaluate(c) + _t->evaluate(c);
    }
    
    virtual string toString() override
    {
        return _e->toString() + " + " + _t->toString();
    }
private:
    unique_ptr<Expr> _e;
    unique_ptr<Term> _t;
};

class DifferenceExpr : public Expr
{
public:
    DifferenceExpr(unique_ptr<Expr> e, unique_ptr<Term> t):_e(move(e)),_t(move(t))
    {}
    virtual double evaluate(const Context &c) override
    {
        return _e->evaluate(c) - _t->evaluate(c);
    }
    
    virtual string toString() override
    {
        return _e->toString() + " - " + _t->toString();
    }
private:
    unique_ptr<Expr> _e;
    unique_ptr<Term> _t;
};

class ProductTerm : public Term
{
public:
    ProductTerm(unique_ptr<Term> t, unique_ptr<Factor> f):_t(move(t)),_f(move(f))
    {}
    
    virtual double evaluate(const Context &c) override
    {
        return _t->evaluate(c) * _f->evaluate(c);
    }
    
    virtual string toString() override
    {
        return _t->toString() + " * " + _f->toString();
    }
private:
    unique_ptr<Term> _t;
    unique_ptr<Factor> _f;
};

class DividendTerm : public Term
{
public:
    DividendTerm(unique_ptr<Term> t, unique_ptr<Factor> f):_t(move(t)),_f(move(f))
    {}
    
    virtual double evaluate(const Context &c) override
    {
        return _t->evaluate(c) / _f->evaluate(c);
    }
    
    virtual string toString() override
    {
        return _t->toString() + " / " + _f->toString();
    }
private:
    unique_ptr<Term> _t;
    unique_ptr<Factor> _f;
};


class ParenthesizedExpr : public Factor
{
public:
    ParenthesizedExpr(unique_ptr<Expr> e):_e(move(e))
    {}
    
    virtual double evaluate(const Context &c) override
    {
        return _e->evaluate(c);
    }
    
    virtual string toString() override
    {
        return "(" + _e->toString() + ")";
    }
private:
    unique_ptr<Expr> _e;
};

class Number : public Factor
{
public:
    Number(double d):_d(d)
    {}
    
    virtual double evaluate(const Context &c) override
    {
        return _d;
    }
    
    virtual string toString() override
    {
        ostringstream output;
        output << _d;
        return output.str();
    }
    
private:
    double _d;
};

class Variable : public Factor
{
public:
    Variable(string name):_name(name)
    {}
    
    virtual double evaluate(const Context &c) override
    {
        auto location = c.find(_name);
        if(location != c.end())
            return location->second;
        else
            throw std::runtime_error("Variable class: undefined variable.");
    }
    
    virtual string toString() override
    {
        ostringstream output;
        output << _name;
        return output.str();
    }
    
private:
    string _name;
};

#endif /* defined(__CS372_2015_Design_Patterns__Expression__) */
    


