#ifndef UTIL_HPP
#define UTIL_HPP

#include "visitor.hpp"
#include "expression.hpp"
#include "type.hpp"
//Get expression types as strings

struct expr_type_visitor : expr_visitor
{
    // Reference Types
    
    void visit(const ref_expr *) { the_type = "ref_expr"; }
    
    // Literal Expressions
    
    void visit(const int_expr *) { the_type = "int_expr"; } 
    void visit(const bool_expr *) { the_type = "bool_expr"; }
    
    // Conditional Expression

    void visit(const if_then_else_expr *) { the_type = "if_then_else_expr"; }
    
    // Unary Expressions
    
    void visit(const pos_expr *) { the_type = "pos_expr"; } 
    void visit(const neg_expr *) { the_type = "neg_expr"; } 
    void visit(const not_expr *) { the_type = "not_expr"; } 

    // Binary Expressions
    
    void visit(const add_expr *) { the_type = "add_expr"; } 
    void visit(const sub_expr *) { the_type = "sub_expr"; } 
    void visit(const multi_expr *) { the_type = "multi_expr"; } 
    void visit(const div_expr *) { the_type = "div_expr"; } 
    void visit(const modulus_expr *) { the_type = "modulus_expr"; } 
    void visit(const AND_expr *) { the_type = "AND_expr"; } 
    void visit(const OR_expr *) { the_type = "OR_expr"; } 
    void visit(const greaterthan_expr *) { the_type = "greaterthan_expr"; } 
    void visit(const lessthan_expr *) { the_type = "lessthan_expr"; } 
    void visit(const greaterthanequal_expr *) { the_type = "greaterthanequal_expr"; } 
    void visit(const lessthanequal_expr *) { the_type = "lessthanequal_expr"; } 
    void visit(const equalequal_expr *) { the_type = "equalequal_expr"; } 
    void visit(const notequal_expr *) { the_type = "notequal_expr"; } 

    std::string the_type;
};

std::string get_expr_type(expr* e);

// Get type types as strings

struct type_type_visitor : type_visitor
{
    void visit( const bool_type * ) { the_type = "bool"; }
    void visit( const int_type * )  { the_type = "int"; }
    void visit( const ref_type * ) { the_type = "reference"; }
    std::string the_type;
};

std::string get_type_type(type * t);

#endif
