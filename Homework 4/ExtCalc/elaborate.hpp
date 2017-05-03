#ifndef ELABORATE_HPP
#define ELABORATE_HPP

#include <string>
#include <vector>

#include "prelude.hpp"
#include "visitor.hpp"
#include "ast.hpp"


struct elaboration_visitor : expr_visitor
{
    elaboration_visitor() : the_type(nullptr) {}
    
    // Literal Expressions
    
    void visit(const int_expr *);
    void visit(const bool_expr *);

    // Unary Expressions
    
    void visit(const pos_expr *);
    void visit(const neg_expr *);
    void visit(const not_expr *);

    // Binary Expressions
    
    void visit(const add_expr * e) { on_binary("+", "int", e); }
    void visit(const sub_expr * e) { on_binary("-", "int", e); }
    void visit(const multi_expr * e) { on_binary("*", "int", e); }
    void visit(const div_expr * e) { on_binary("/", "int", e); }
    void visit(const mod_expr * e) { on_binary("%", "int", e); }
    void visit(const AND_expr * e) { on_binary("&&", "bool", e); }
    void visit(const OR_expr * e) { on_binary("||", "bool", e); }
    void visit(const greaterthan_expr * e) { on_binary(">", "bool", e); }
    void visit(const lessthan_expr * e) { on_binary("<", "bool", e); }
    void visit(const greaterthanequal_expr * e) { on_binary(">=", "bool", e); }
    void visit(const lessthanequal_expr * e) { on_binary("<=", "bool", e); }
    void visit(const equalequal_expr * e) { on_binary("==", "bool", e); }
    void visit(const notequal_expr * e) { on_binary("!=", "bool", e); }

    void on_binary(std::string op, std::string typ, const binary_expr * b);

    std::string error_message(std::string message);

    type * the_type;
    std::vector<std::string> errors;
};

type * elaborate(expr * ast);

#endif
