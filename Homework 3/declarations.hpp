#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include "ast.hpp"

struct Expr;
struct Type;
struct Context;

struct Declaration {
  Context* cxt;
  virtual ~Declaration() = default;
  virtual const std::string getName() = 0;
};

struct Var_Declaration : Declaration {
  const Type* type; // type
  Expr* eval_expr;
  Expr* noneval_expr;
  const std::string name;
  Var_Declaration(Context* _cxt, const std::string n, const Type* t) : type(t), name(n) {
    cxt = _cxt;
  }
  const std::string getName() { return name; }
};

#endif
