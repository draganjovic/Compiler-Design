#ifndef STATEMENT_HPP
#define STATEMENT_HPP

struct Expr;
struct Decl;

struct Statement {
  virtual ~Statement() = default;
};

// Expr statement
struct expr_stmt : Statement {
  expr_stmt(expr* _e) : e(_e) {}
  expr* e;
};

// Decl statement
struct decl_stmt : Statement {
  decl_stmt(decl* _d) : d(_d) {}
  decl* d;
};

#endif
