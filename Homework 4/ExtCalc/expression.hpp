#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "prelude.hpp"
#include "visitor.hpp"


struct expr
{
    virtual ~expr() {}
    virtual void accept(expr_visitor&) = 0;
};

// Reference Types

struct ref_expr : expr
{
public:
    ref_expr(ref value) : value_(value) {}
    
    ref value() const { return value_; }
    void accept(expr_visitor & v) { v.visit(this); }

private:
    ref value_;
};
    
// Literal Expressions

struct int_expr : expr
{
public:
    int_expr(int value) : value_(value) {}
    
    int value() const { return value_; }
    void accept(expr_visitor & v) { v.visit(this); }

private:
    int value_;
};

struct bool_expr : expr
{
public:
    bool_expr(bool value) : value_(value) {}

    bool value() const { return value_; }
    void accept(expr_visitor & v) { v.visit(this); }

private:
    bool value_;
};

// Conditional Expression

struct if_then_else_expr : expr
{
    virtual ~if_then_else_expr()
    {}
    if_then_else_expr(expr * e1, expr * e2, expr * e3) : expr(e1, e2, e3) {}
    
    void accept(expr_visitor & v)
    { v.visit(this); }
};

// Unary Expressions

struct unary_expr : expr
{
    virtual ~unary_expr() 
    {}
    unary_expr(expr * e)
    : only(e) 
    {}
    expr * only;
};

struct pos_expr : unary_expr
{
    pos_expr(expr * e)
    : unary_expr(e) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct neg_expr : unary_expr
{
    neg_expr(expr * e)
    : unary_expr(e) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct not_expr : unary_expr
{
    not_expr(expr * e)
    : unary_expr(e) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

// Binary Expressions

struct binary_expr : expr
{
    binary_expr(expr * e1, expr * e2)
    : first(e1), second(e2) {}

    expr * first;
    expr * second;
};

struct add_expr : binary_expr
{
    add_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct sub_expr : binary_expr
{
    sub_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct multi_expr : binary_expr
{
    multi_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct div_expr : binary_expr
{
    div_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct modulus_expr : binary_expr
{
    modulus_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct AND_expr : binary_expr
{
    and_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct OR_expr : binary_expr
{
    or_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct greaterthan_expr : binary_expr
{
    greatherthan_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct lessthan_expr : binary_expr
{
    lessthan_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct greaterthanequal_expr : binary_expr
{
    greaterthanequal_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct lessthanequal_expr : binary_expr
{
    lessthanequal_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct equalequal_expr : binary_expr
{
    equalequal_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}
    
    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct notequal_expr : binary_expr
{
    notequal_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2) {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

#endif
