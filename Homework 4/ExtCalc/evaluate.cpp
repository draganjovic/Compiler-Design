#include "evaluate.hpp"
#include "ast.hpp"

using namespace std;

// Reference Types

 void eval_visitor::visit(const ref_expr *)
 {
     ref_value = e->value();
 }

// Function Types

 void eval_visitor::visit(const func_expr *)
 {
     func_value = e->value();
 }

// Literal Expressions

void eval_visitor::visit(const int_expr * e)
{
    int_value = e->value();
}

void eval_visitor::visit(const bool_expr * e)
{
    bool_value = e->value();
}

// Conditional Expression
void eval_visitor::visit(const if_then_else_expr * e)
{
    int_value = int_evaluate(e->first), int_evaluate(e->second) : int_evaluate(e->third);
}

// Unary Expressions

void eval_visitor::visit(const pos_expr * e)
{
    int_value = int_evaluate(e->only);
}

void eval_visitor::visit(const neg_expr * e)
{
    int_value = -1 * int_evaluate(e->only);
}

void eval_visitor::visit(const not_expr * e)
{
    bool_value = !bool_evaluate(e->only);
}

// Binary Expressions

void eval_visitor::visit(const add_expr * e)
{
    int_value = int_evaluate(e->first) + int_evaluate(e->second);
}

void eval_visitor::visit(const sub_expr * e)
{
    int_value = int_evaluate(e->first) - int_evaluate(e->second);
}

void eval_visitor::visit(const multi_expr * e)
{
    int_value = int_evaluate(e->first) * int_evaluate(e->second);
}

void eval_visitor::visit(const div_expr * e)
{
    int_value = int_evaluate(e->first) / int_evaluate(e->second);
}

void eval_visitor::visit(const modulus_expr * e)
{
    int_value = int_evaluate(e->first) % int_evaluate(e->second);
}

void eval_visitor::visit(const AND_expr * e)
{
    bool_value = bool_evaluate(e->first) && bool_evaluate(e->second);
}

void eval_visitor::visit(const OR_expr * e)
{
    bool_value = bool_evaluate(e->first) || bool_evaluate(e->second);
}

void eval_visitor::visit(const greaterthan_expr * e)
{
    bool_value = int_evaluate(e->first) > int_evaluate(e->second);
}

void eval_visitor::visit(const lessthan_expr * e)
{
    bool_value = int_evaluate(e->first) < int_evaluate(e->second);
}

void eval_visitor::visit(const greaterthanequal_expr * e)
{
    bool_value = int_evaluate(e->first) >= int_evaluate(e->second);
}

void eval_visitor::visit(const lessthanequal_expr * e)
{
    bool_value = int_evaluate(e->first) <= int_evaluate(e->second);
}

void eval_visitor::visit(const equalequal_expr * e)
{
    bool_value = bool_evaluate(e->first) == bool_evaluate(e->second);
}

void eval_visitor::visit(const notequal_expr * e)
{
    bool_value = bool_evaluate(e->first) == bool_evaluate(e->second);
}

// Int & Bool 
int int_evaluate(expr * ast)
{
    eval_visitor v;
    ast->accept(v);
    return v.int_value;
}

bool bool_evaluate(expr * ast)
{
    eval_visitor v;
    ast->accept(v);
    return v.bool_value;
}

// Reference Types

int ref_evaluate(expr * ast)
{
    eval_visitor v;
    ast->accept(v);
    returm v.ref_value;
}

// Function Types

int func_evaluate(expr * ast)
{
    eval_visitor v;
    ast->accept(v);
    returm v.ref_value;
}
