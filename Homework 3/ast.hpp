#ifndef AST_HPP
#define AST_HPP
#include <cassert>

// Language types - Two types: bools & ints
struct Bool_type;
struct Int_type;

struct bool_expr;                        // bool - true/false
struct int_expr;                         // integer literals

struct and_expr;                         // AND
struct or_expr;                          // inclusive OR
struct xor_expr;                         // exclusive OR
struct not_expr;                         // logical negation

struct if_then_else_expr;                // conditional
struct equal_to_expr;                    // equal to
struct not_equal_to_expr;                // not equal to
struct less_than_expr;                   // less than (<)
struct greater_than_expr;                // greater than (>)
struct less_than_or_equal_to_expr;       // <=
struct greater_than_or_equal_to_expr;    // >=

struct add_expr;                         // addition
struct sub_expr;                         // subtraction
struct multi_expr;                       // multiplication
struct div_expr;                         // integer division
struct rem_expr;                         // remainder of division
struct arithmetic_neg_expr;              // arithmetic negation

// Creating my own data types using enum
enum struct TYPE {
  Int_type,
  Bool_type,
};

// Class/Structure for Type
struct Type {
  struct Visitor;
  virtual ~Type() = default;            // destructor
  virtual void accept(Visitor&) {}
};

// Let both types inherit the "Type" structure
struct Bool_type : Type {};
struct Int_type : Type {};

struct Expr {
  struct Visitor;
  virtual ~Expr() = default;          // destructor
  virtual void accept(Visitor&) = 0;
};

// Defining the Visitor Class/structure and expr
struct Expr::Visitor
{
  virtual void visit(bool_expr*) = 0;
  virtual void visit(int_expr*) = 0;

  virtual void visit(and_expr*) = 0;
  virtual void visit(or_expr*) = 0;
  virtual void visit(xor_expr*) = 0;
  virtual void visit(not_expr*) = 0;

  virtual void visit(if_then_else_expr*) = 0;
  virtual void visit(equal_to_expr*) = 0;
  virtual void visit(not_equal_to_expr*) = 0;
  virtual void visit(less_than_expr*) = 0;
  virtual void visit(greater_than_expr*) = 0;
  virtual void visit(less_than_or_equal_to_expr*) = 0;
  virtual void visit(greater_than_or_equal_to_expr*) = 0;

  virtual void visit(add_expr*) = 0;
  virtual void visit(sub_expr*) = 0;
  virtual void visit(multi_expr*) = 0;
  virtual void visit(div_expr*) = 0;
  virtual void visit(rem_expr*) = 0;
  virtual void visit(arithmetic_neg_expr*) = 0;
};

struct bool_expr : Expr {
  bool value;
  bool_expr(bool b) : value(b) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct int_expr : Expr {
  int literal;
  int_expr(int a) : literal(a) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct and_expr : Expr {
  Expr* e1;
  Expr* e2;
  and_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct or_expr : Expr {
  Expr* e1;
  Expr* e2;
  or_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct xor_expr : Expr { // either value1 or value2, but not both
  Expr* e1;
  Expr* e2;
  xor_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct not_expr : Expr {
  Expr* e1;
  not_expr(Expr* e1) : e1(e1) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct if_then_else_expr : Expr {
  Expr* e1;
  Expr* e2;
  Expr* e3;
  if_then_else_expr(Expr* e1, Expr* e2, Expr* e3) : e1(e1), e2(e2), e3(e3) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct equal_to_expr : Expr {
  Expr* e1;
  Expr* e2;
  equal_to_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct not_equal_to_expr : Expr {
  Expr* e1;
  Expr* e2;
  not_equal_to_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct less_than_expr : Expr {
  Expr* e1;
  Expr* e2;
  less_than_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct greater_than_expr : Expr {
  Expr* e1;
  Expr* e2;
  greater_than_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct less_than_or_equal_to_expr : Expr {
  Expr* e1;
  Expr* e2;
  less_than_or_equal_to_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct greater_than_or_equal_to_expr : Expr {
  Expr* e1;
  Expr* e2;
  greater_than_or_equal_to_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct add_expr : Expr {
  Expr* e1;
  Expr* e2;
  add_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct sub_expr : Expr {
  Expr* e1;
  Expr* e2;
  sub_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct multi_expr : Expr {
  Expr* e1;
  Expr* e2;
  multi_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct div_expr : Expr {
  Expr* e1;
  Expr* e2;
  div_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct rem_expr : Expr {
  Expr* e1;
  Expr* e2;
  rem_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct arithmetic_neg_expr : Expr {
  Expr* e1;
  arithmetic_neg_expr(Expr* e1) : e1(e1) {}
  void accept(Visitor& v) { return v.visit(this); };
};

struct Context
{
  Bool_type bool_type;
  Int_type int_type;
};

#endif
