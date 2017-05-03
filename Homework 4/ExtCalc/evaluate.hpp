#ifndef EVALUATE_HPP
#define EVALUATE_HPP

#include "prelude.hpp"
#include "visitor.hpp"
#include "ast.hpp"

struct eval_visitor : expr_visitor
{   
    // Literal Expressions
    
    void visit(const int_expr *);
    void visit(const bool_expr *);
    
    // Conditional Expression

    void visit(const if_then_else_expr *);

    // Unary Expressions
    
    void visit(const pos_expr *);
    void visit(const neg_expr *); 
    void visit(const not_expr *);
    
    // Binary Expressions
    
    void visit(const add_expr *);
    void visit(const sub_expr *);
    void visit(const multi_expr *);
    void visit(const div_expr *); 
    void visit(const modulus_expr *);
    void visit(const AND_expr *);
    void visit(const OR_expr *);
    void visit(const greaterthan_expr *);
    void visit(const lessthan_expr *);
    void visit(const greaterthanequal_expr *);
    void visit(const lessthanequal_expr *);
    void visit(const equalequal_expr *);
    void visit(const notequal_expr *);

    int int_value;
    bool bool_value;
};

int int_evaluate(expr * ast);
bool bool_evaluate(expr * ast);

#endif
