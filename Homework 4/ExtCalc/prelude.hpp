#ifndef PRELUDE_HPP
#define PRELUDE_HPP

#include <cassert>
#include <stdexcept>
#include <typeinfo>
#include <iostream>


// Visitors
struct type_visitor;
struct expr_visitor;

// Types
struct type;
struct bool_type;
struct int_type;
struct ref_type;
struct func_type;

// expr decl
struct expr;

// Literal Expressions

struct int_expr;
struct bool_expr;
struct ref_expr;

// Conditional Expression

struct if_then_else_expr;

// Unary Expressions

struct unary_expr; // initial unary expression decl
struct pos_expr; 
struct neg_expr; 
struct not_expr;

// Binary Expressions

struct binary_expr; // initial binary expression decl
struct add_expr; 
struct sub_expr; 
struct multi_expr; 
struct div_expr; 
struct modulus_expr; 
struct AND_expr;
struct OR_expr; 
struct greaterthan_expr; 
struct lessthan_expr; 
struct greaterthanequal_expr;
struct lessthanequal_expr; 
struct equalequal_expr; 
struct notequal_expr;

#endif
