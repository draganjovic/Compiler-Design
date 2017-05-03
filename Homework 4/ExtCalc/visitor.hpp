#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "prelude.hpp"
#include <string>


struct expr_visitor;
struct type_visitor;

struct expr_visitor
{
    // Literal Expressions
    
    virtual void visit(const int_expr *) {}
    virtual void visit(const bool_expr *) {} 
    
    // Unary Expressions
    
    virtual void visit(const pos_expr *) {}
    virtual void visit(const neg_expr *) {}
    virtual void visit(const not_expr *) {} 

    // Binary Expressions
    
    virtual void visit(const add_expr *) {}
    virtual void visit(const sub_expr *) {}
    virtual void visit(const multi_expr *) {} 
    virtual void visit(const div_expr *) {}
    virtual void visit(const modulus_expr *) {}
    virtual void visit(const AND_expr *) {}
    virtual void visit(const OR_expr *) {}
    virtual void visit(const greaterthan_expr *) {}
    virtual void visit(const lessthan_expr *) {}
    virtual void visit(const greaterthanequal_expr *) {}
    virtual void visit(const lessthanequal_expr *) {}
    virtual void visit(const equalequal_expr *) {}
    virtual void visit(const notequal_expr *) {}
};

// Type Visitor

struct type_visitor
{
    virtual void visit( const bool_type * ) {};
    virtual void visit( const int_type * ) {};
};

#endif
