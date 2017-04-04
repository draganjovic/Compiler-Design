#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "ast.hpp"

#include <iostream>
#include <vector>
#include <string>

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
  bool_tok,             // true/false
  int_tok,              // digit digit*
};

// Used for printing
std::string Token_Names[22] = {
  "Eof_tok",            // 0
  "plus_tok",           // 1
  "minus_tok",          // 2
  "star_tok",           // 3
  "slash_tok",          // 4
  "percent_tok",        // 5
  "and_tok",            // 6
  "or_tok",             // 7
  "bang_tok",           // 8
  "equalequal_tok",     // 9
  "notequal_tok",       // 10
  "lessthan_tok",       // 11
  "greaterthan_tok",    // 12
  "lessthaneq_tok",     // 13
  "greaterthaneq_tok",  // 14
  "query_tok",          // 15
  "colon_tok",          // 16
  "leftparen_tok",      // 17
  "rightparen_tok",     // 18
  "true",               // 19
  "false"               // 20
  "int_tok",            // 21
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
