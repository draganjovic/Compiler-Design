#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast.hpp"
#include "prelude.hpp"
#include "evaluate.hpp"
#include "lexer.hpp"

#include <iostream>
#include <vector>

class Parser {
  private:
    std::vector<Token*> t;
    std::vector<Token*>::iterator it;
    context* cxt;

    // return if there are no more tokens
    bool Eof() { return it == t.end(); }

    // returns the kind of current token
    Token * LookAhead() { return (this->Eof() ? new punc_operator_token(Eof_tok) : *it); }

    // returns the nth token past the current token
    Token * LookAhead(int);

    // consume
    void Consume() { ++it; }
    Token * Consume_();

    // compare token kind, if current token has given kind, consume it
    // otherwise no action.
    bool MatchIf(Token_kind k) { return LookAhead()->kind == k; }

    // compare token kind, if current token has given kind, consume it
    // otherwise give error.
    Token * Match(Token_kind k);

    // require that token have given kind & consume
    Token * Require(Token_kind k);

    // Parse functions
    expr * ParseExpr();      // expression
    expr * ParseCond();      // conditional expression
    expr * ParseOr();        // logical or expression
    expr * ParseAnd();       // logical and expression
    expr * ParseEqual();     // equality expression
    expr * ParseOrdering();  // relational expression
    expr * ParseAdd();       // additive expression
    expr * ParseMult();      // multiplicative expression
    expr * ParseUnary();     // unary expression
    expr * ParsePrimary();   // boolean and integer literals

    // Statements
    Statement * ParseStmt();       // statement
    Statement * ParseDecl_Stmt();  // declaration statement
    Statement * ParseExpr_Stmt();  // expression statement

    // Declarations
    Declaration * ParseDecl();
    Declaration * ParseVariable_Decl();

    // Types
    const type * ParseType();

  public:
    Statement * Parse() { return ParseStmt(); }

    // Constructor
    Parser(std::vector<Token*> _t, Context* _cxt) : t(_t), cxt(_cxt)
    {
      it = t.begin();
    }

    // destructor
    ~Parser() {}

  }
