#include "parser.hpp"

#include <iostream>
#include <vector>

Token * Parser::LookAhead(int count) {
  if(this->Eof())
    return new punc_operator_token(Eof_tok);

  std::vector<Token*>::iterator temp = it;
  for(int i = 0; i < count; ++i) {
    ++temp;
    if(temp == t.end())
      return nullptr;
  }
  return *temp; // otherwise return temporary var
}

Token * Parser::Consume_() {
  Token * tok = LookAhead();
  Consume();
  return tok;
}

Token * Parser::Match(Token_kind k) {
  if(LookAhead()->kind == k)
    return Consume_();
  else
    return nullptr;
}

// Throw error if token kind is not as given
Token * Parser::Require(Token_kind k) {
  if(LookAhead()->kind == k)
    return Consume_();
  else
    throw std::cout << "Error";
}

// statement
Statement * Parser::ParseStmt() {
  switch (LookAhead()->kind) {
  case var_d:
    return ParseDecl_Stmt();
  case ident_tok:
    if(LookAhead(1) && MatchIf(LookAhead(1))
      return ParseDecl_Stmt();
  default:
    return ParseExpr_Stmt(); // else return an expression
  }
}

// declaration statement
Statement * Parser::ParseDecl_Stmt() {
  decl* d = ParseDecl();
  return new decl_stmt(d);
}

// expression statement
Statement * Parser::ParseExpr_Stmt()) {
  expr* e = ParseDecl();
  return new  expr_stmt(e);
}

// declaration
Declaration * Parser::ParseDecl() {
  switch (LookAhead()->kind) {
  case var_d:
    return ParseVariable_Decl();
  case ident_tok:
    return ParseVariable_Decl();
  default:
    break;
  }
  throw std::cout << "Invalid Declaration";
}

// variable declaration
Declaration * Parser::ParseVariable_Decl() {
  Require(var_d); // require var declaration
  const Type* t = ParseType(); // get type

  if(cxt->FindSymbol(n)) // check for existing var
    throw std::cout << "Invalid";

  Var_Declaration* var = new Var_Declaration(cxt, n, t);
  Require(equal_tok); // make sure there is =

  Expr* e = ParseExpr();

  if(e->Check() != t) // compare var type to expr type
    throw std::cout << "Error";

  var->noneval_expr = e;
  var->eval_expr = e->Precompute();

  return var;
}


// type identifier
const Type * Parser::ParseType() {
  switch(LookAhead()->kind) {
  case bool_tok:
    Consume();
    return &(cxt->bool_type);
  case int_tok:
    Consume();
    return &(cxt->int_type);
  }
  throw std::cout << "Syntax Error";
}

// expression
Expr * Parser::ParseExpr() {
  return ParseCond();
}

// conditional expression
Expr * Parser::ParseCond() {
  Expr * e = ParseOr();
  while(true) {
    if(MatchIf(query_tok)) {
      Consume();
      Expr * e1 = ParseExpr();
      if(MatchIf(colon_tok)) {
	Consume();
	e = new if_then_else_expr(e, e1, ParseExpr(), cxt);
      }
      else
	throw std::cout << "Syntax Error";
    }
    else
      return e;
  }
}

// logical or expression
Expr * Parser::ParseOr() {
  Expr * e = ParseAnd();
  while(true) {
    if(MatchIf(or_tok)) {
      Consume();
      e = new or_expr(e, ParseAnd(), cxt);
    }
    else
      return e;
  }
}

// logical and expression
Expr * Parser::ParseAnd() {
  Expr * e = ParseOr();
  while(true) {
    if(MatchIf(and_tok)) {
      Consume();
      e = new and_expr(e, ParseOr(), cxt);
    }
    else
      return e;
  }
}

// equality expression
Expr * Parser::ParseEqual() {
  Expr * e = ParseOrdering();
  while(true) {
    if(MatchIf(equalequal_tok)) {
      Consume();
      e = new equal_to_expr(e, ParseOrdering(), cxt);
    }
    else if(MatchIf(notequal_tok)) {
      Consume();
      e = new not_equal_to_expr(e, ParseOrdering(), cxt);
    }
    else
      return e;
  }
}

// relational expression
Expr * Parser::ParseOrdering() {
  Expr * e = ParseAdd();
  while(true) {
    if(MatchIf(lessthan_tok)) {
      Consume();
      e = new less_than_expr(e, ParseAdd(), cxt);
    }
    else if(MatchIf(greaterthan_tok)) {
      Consume();
      e = new greater_than_expr(e, ParseAdd(), cxt);
    }
    else if(MatchIf(lessthaneq_tok)) {
      Consume();
      e = new less_than_or_equal_to_expr(e, ParseAdd(), cxt);
    }
    else if(MatchIf(greaterthaneq_tok)) {
      Consume();
      e = new greater_than_or_equal_to_expr(e, ParseAdd(), cxt);
    }
    else
      return e;
  }
}

// additive expression
Expr * Parser::ParseAdd() {
  Expr * e = ParseMult();
  while(true) {
    if(MatchIf(plus_tok)) {
      Consume();
      e = new add_expr(e, ParseMult(), cxt);
    }
    else if(MatchIf(minus_tok)) {
      Consume();
      e = new sub_expr(e, ParseMult(), cxt);
    }
    else
      return e;
  }
}

// multiplicative expression
Expr * Parser::ParseMult() {
  Expr * e = ParseUnary();
  while(true) {
    if(MatchIf(star_tok)) {
      Consume();
      e = new multi_expr(e, ParseUnary(), cxt); // evaluate.hpp
    }
    else if(MatchIf(slash_tok)) {
      Consume();
      e = new div_expr(e, ParseUnary(), cxt); // evaluate.hpp
    }
    else if(MatchIf(percent_tok)) {
      Consume();
      e = new rem_expr(e, ParseUnary(), cxt); // evaluate.hpp
    }
    else
      return e;
  }
}

// unary expression
Expr * Parser::ParseUnary() {
  if(MatchIf(bang_tok)) {
    Consume();
    return new not_expr(ParseUnary(), cxt); // evaluate.hpp
  }
  else if(MatchIf(minus_tok)) {
    Consume();
    return new arithmetic_neg_exp(ParseUnary(), cxt); // evaluate.hpp
  }
  else
    return ParsePrimary();
}

// boolean and integer literals
Expr * Parser::ParsePrimary() {
  if(MatchIf(int_tok)) {
    Token * t = LookAhead();
    Consume();
    return new int_expr(ParsePrimary(), cxt);
  }
  else if(MatchIf(bool_tok) {
    Consume();
    return new bool_expr(true, cxt); // evaluate.hpp
  }
  else if(MatchIf(bool_tok) {
    Consume();
    return new bool_expr(false, cxt); // evaluate.hpp
  }
  else if(MatchIf(leftparen_tok)) {
    Consume();
    Expr * e = ParseExpr();
    if(MatchIf(rightparen_tok) {
      Consume();
      return e;
    }
    else
      throw std::cout << "Error";
  }
