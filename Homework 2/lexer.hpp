#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <iostream>
#include <iomanip>

struct Lexer {

    char * first;
    char * last;
    std::string::buffer;

    Lexer(char * first, char * last) : first(first), last(last) {}

    bool Eof() const { return first == last; }
    char lookahead() const { if (Eof()) return 0; else return *first; }
    void consume() { ++first; }

    char buffer() {
      if Eof()) { return 0; }
      buffer += lookahead();
      consume();
      return buffer.back();
    }

    Token * Next() {
      buffer.clear();
      switch(lookahead()) {
        case '+':
          consume();
          return new punc_operator_token(plus_tok);
          std::cout << std::Token_Names[1];
          break;
        case '-':
          consume();
          return new punc_operator_token(minus_tok);
          std::cout << std::Token_Names[2];
          break;
        case '*':
          consume();
          return new punc_operator_token(star_tok);
          std::cout << std::Token_Names[3];
          break;
        case '/':
          consume();
          return new punc_operator_token(slash_tok);
          std::cout << std::Token_Names[4];
          break;
        case: '%':
          consume();
          return new punc_operator_token(percent_tok);
          std::cout << std::Token_Names[5];
          break;
        case '&':
          consume();
          if(lookahead() == '&') {
            consume();
            return new punc_operator_token(and_tok);
            std::cout << std::Token_Names[6];
            break;
        case '|':
          consume();
          if(lookahead() == '|') {
            consume();
            return new punc_operator_token(or_tok);
            std::cout << std::Token_Names[7];
            break;
        case '!':
          consume();
          if(lookahead() == '=') {
            consume();
            return new punc_operator_token(notequal_tok);
            std::cout << std::Token_Names[10];
          }
          return new punc_operator_token(bang_tok);
          std::cout << std::Token_Names[8];
          break;
        case '=':
          consume();
          if(lookahead() == '=') {
            consume();
            return new punc_operator_token(equalequal_tok);
            std::cout << std::Token_Names[9];
            break;
          }
        case '<':
          consume();
          if(lookahead() == '=') {
            consume();
            return new punc_operator_token(lessthaneq_tok);
            std::cout << std::Token_Names[13];
            }
            return new punc_operator_token(lessthan_tok);
            std::cout << std::Token_Names[11];
            break;
          case '>':
            consume();
            if(lookahead() == '=') {
              consume();
              return new punc_operator_token(greaterthaneq_tok);
              std::cout << std::Token_Names[14];
              }
              return new punc_operator_token(greaterthan_tok);
              std::cout << std::Token_Names[12];
              break;
          case '?':
            consume();
            return new punc_operator_token(query_tok);
            std::cout << std::Token_Names[15];
            break;
          case ':':
            consume();
            return new punc_operator_token(colon_tok);
            std::cout << std::Token_Names[16];
            break;
          case '(':
            consume();
            return new punc_operator_token(leftparen_tok);
            std::cout << std::Token_Names[17];
            break;
          case ')':
            consume();
            return new punc_operator_token(rightparen_tok);
            std::cout << std::Token_Names[18];
            break;
          case 'a' ... 'z' :
            while (lookahead() >= 'a' && lookahead() <= 'z') {
              consume();
              }
            if (buffer == "false") {
              return new bool_token(false);
              std::cout << std::Token_Names[20];
            }
            if (buffer == 'true') {
              return new bool_token(true);
              std::cout << std::Token_Names[19]
          }
            break;
          case '0' ... '9':
            consume();
            while (lookahead() >= '0' && lookahead() <= '9') {
              consume();
            }
            return new int_token(int_tok);
            std::cout << std::Token_Names[21];
            break;
          case 0:
            return Eof_tok;
            break;

            default:
              consume();
            }
            return -1;
        }
    }
};
