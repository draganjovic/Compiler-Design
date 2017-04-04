#include "ast.hpp"
#include "evaluate.hpp"
#include "print.hpp"
#include "verify_new.hpp"
#include "token.hpp"
#include "parser.hpp"
#include "lexer.hpp"
#include "statement.hpp"
#include <iostream>

int main() {
    Context context_;
    {
      Expr* e = new multi_expr(new int_expr(5), new int_expr(2)); // 5 * 2
      check(context_, e); // check function from "verify_new.hpp"
      print(e); // print function from "print.hpp"
      std::cout << " == " << eval(e).data.b << std::endl;
    }
  }

    std::vector<Token*> t;
    Token* tok = new Token();

// parse tokens
      Parser * parser = new Parser(*t, cxt);
      cout << parser;

}
