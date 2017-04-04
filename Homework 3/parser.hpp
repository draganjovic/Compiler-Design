#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast.hpp"
#include "value.hpp"
#include "evaluate.hpp"
#include "lexer.hpp"
#include "token.hpp"
#include "statement.hpp"

struct Parser {
  private:
    std::vector<Token*> t;
    std::vector<Token*>::iterator it;
    Context cxt;

    // returns true if there are no more tokens
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

        

}
