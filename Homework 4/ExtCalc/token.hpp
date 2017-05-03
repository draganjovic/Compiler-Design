#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <vector>
#include <string>

#include "ast.hpp"

enum Token_kind {
  Eof_tok,              //  End of file, 0, null
  plus_tok,             //  +
  minus_tok,            //  -
  star_tok,             //  *
  slash_tok,            //  /
  percent_tok,          //  %
  and_tok,              //  &&
  or_tok,               //  ||
  bang_tok,             //  !
  equalequal_tok,       //  ==
  notequal_tok,         //  !=
  lessthan_tok,         //  <
  greaterthan_tok,      //  >
  lessthaneq_tok,       //  <=
  greaterthaneq_tok,    //  >=
  query_tok,            //  ?
  colon_tok,            //  :
  leftparen_tok,        //  (
  rightparen_tok,       //  )
  var_d,                // var declaration
  ident_tok,            // identifiers
  bool_tok,             // true/false
  int_tok,              // digit digit*
};

struct Token {
  int kind;
  virtual ~Token() = default;
  std::string EnumName() { return Token_Names[kind]; }
};

// Creates a non-literal token
struct punc_operator_token : Token {
  punc_operator_tok(int tok) { kind = tok; };
};

// Creates a boolean token
struct bool_token : Token {
  bool value;
  bool_token(bool b) : value(b) { kind = bool_tok; };
};

// Creates an integer token
struct int_token : Token  {
  int value;
  int_token(int i) : value(i) { kind = int_tok, digit_tok; };
};

#endif
