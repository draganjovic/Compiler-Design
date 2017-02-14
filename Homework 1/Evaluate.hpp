#include "ast.hpp"
#include "value.hpp"
#include <cassert>

Value eval(Expr* e) {
  struct V : Expr::Visitor {
    Value val;

    void visit(bool_expr* e) {
      val.kind = Types::boolean_type; // bool_type from enum in value.hpp
      val.data.b = e->value;  // "bool value" from ast.hpp
    }
    void visit(int_expr* e) {
      val.kind = Types::integer_type; // int_type from enum in value.hpp
      val.data.i = e->literal; // "int literal" from ast.hpp
    }
    void visit(and_expr* e) {
      val.kind = Types::boolean_type;
      val.data.b = eval(e->e1).data.b & eval(e->e2).data.b;
    }
    void visit(or_expr* e) {
      val.kind = Types::boolean_type;
      val.data.b = eval(e->e1).data.b | eval(e->e2).data.b;
    }
    void visit(xor_expr* e) {
      val.kind = Types::boolean_type;
      val.data.b = eval(e->e1).data.b ^ eval(e->e2).data.b;
    }
    void visit(not_expr* e) {
      val.kind = Types::boolean_type;
      val.data.b = !eval(e->e1).data.b;
    }
    void visit(if_then_else_expr* e) {
      val.kind = Types::boolean_type;
      val.data.b = eval(e->e1).data.b | eval(e->e2).data.b | eval(e->e3).data.b;
      if ((eval(e->e1).data.b)) == true) { return (eval(e->e1).data.b) = (eval(e->e2).data.b) }
      else { return (eval(e->e3).data.b) }
    }
    void vist(equal_to_expr* e) {
      val.kind = Types::boolean_type; // type bool
      val.data.b = eval(e->e1).data.b == eval(e->e2).data.b;
    }
    void visit(not_equal_to_expr* e) {
      val.kind = Types::boolean_type; // type bool
      val.data.b = eval(e->e1).data.b != eval(e->e2).data.b;
    }
    void visit(less_than_expr* e) {
      val.kind = Types::integer_type; // type int according to rules
      val.data.b = eval(e->e1).data.i < eval(e->e2).data.i;
    }
    void visit(greater_than_expr* e) {
      val.kind = Types::integer_type; // type int according to rules
      val.data.b = eval(e->e1).data.i > eval(e->e2).data.i;
    }
    void visit(less_than_or_equal_to_expr* e) {
      val.kind = Types::integer_type; // type int according to rules
      val.data.b = eval(e->e1).data.i <= eval(e->e2).data.i;
    }
    void visit(greater_than_or_equal_to_expr* e) {
      val.kind = Types::integer_type; // type int according to rules
      val.data.b = eval(e->e1).data.i >= eval(e->e2).data.i;
    }
    void visit(add_expr* e) {
      val.kind = Types::integer_type;
      val.data.i = eval(e->e1).data.i + eval(e->e2).data.i;
    }
    void visit(sub_expr* e) {
      val.kind = Types::integer_type;
      val.data.i = eval(e->e1).data.i - eval(e->e2).data.i;
    }
    void visit(multi_expr* e) {
      val.kind = Types::integer_type;
      val.data.i = eval(e->e1).data.i * eval(e->e2).data.i;
    }
    void visit(div_expr* e) {
      val.kind = Types::integer_type;
      val.data.i = eval(e->e1).data.i / eval(e->e2).data.i;
    }
    void visit(rem_expr* e) {
      val.kind = Types::integer_type;
      val.data.i = eval(e->e1).data.i % eval(e->e2).data.i;
    }
    void visit(arithmetic_neg_expr* e) {
      val.kind = Types::integer_type;
      val.data.i = 0 - (eval(e->e1).data.i);
    }
  };

  V vis;
  e->accept(vis);
  return vis.val;
}
