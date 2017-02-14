#include "ast.hpp"
#include <iostream>

// Function to see if you need ()
bool need_paren(Expr* e) {
  struct V : Expr::Visitor {
    bool p;

    void visit(bool_expr* e) { p= false; }
    void visit(int_expr* e) { p = true ; }

    void visit(and_expr* e) { p = true ; }
    void visit(or_expr* e) { p = true ; }
    void visit(xor_expr* e) { p = true ; }
    void visit(not_expr* e) { p = true ; }

    void visit(if_then_else_expr* e) { p = true ; }
    void visit(equal_to_expr* e) { p = true ; }
    void visit(not_equal_to_expr* e) { p = true ; }
    void visit(less_than_expr* e) { p = true ; }
    void visit(greater_than_expr* e) { p = true ; }
    void visit(less_than_or_equal_to_expr* e) { p = true ; }
    void visit(greater_than_or_equal_to_expr* e) { p = true ; }

    void visit(add_expr* e) { p = true ; }
    void visit(sub_expr* e) { p = true ; }
    void visit(multi_expr* e) { p = true ; }
    void visit(div_expr* e) { p = true ; }
    void visit(rem_expr* e) { p = true ; }
    void visit(arithmetic_neg_expr* e) { p = true ; }
  };



V vis;
   e->accept(vis);
   return vis.p;

// Print function
void print(Expr* e) {
  struct V : Expr::Visitor {
    void print_enclosed(Expr* e) {
      if (need_paren(e)) {
        std::cout << '(';
        print(e);
        std::cout << ')';
      }
      else { print(e); }
    }

    void visit(bool_expr* e) {
      if (e->value) std::cout << "true";
      else std::cout << "false";
    }

    void visit(int_expr* e) {
      std::cout << e->literal;
    }

    void visit(and_expr* e) {
      print_enclosed(e->e1);
      std::cout << " & ";
      print_enclosed(e->e2);
    }

    void visit(or_expr* e) {
      print_enclosed(e->e1);
      std::cout << " | ";
      print_enclosed(e->e2);
    }

    void visit(xor_expr* e) {
      print_enclosed(e->e1);
      std::cout << "^";
      print_enclosed(e->e2);
    }

    void visit(not_expr* e) {
      std::cout << '!';
      print_enclosed(e->e1);
    }

    void visit(if_then_else_expr* e) {
      print_enclosed(e->e1);
      std::cout << "If";
      print_enclosed(e->e2);
      std::cout << "Then";
      print_enclosed(e->e3);
      std::cout << "else";
    }

    void visit(equal_to_expr* e) {
      print_enclosed(e->e1);
      std::cout << "==";
      print_enclosed(e->e2);
    }

    void visit(not_equal_to_expr* e) {
      print_enclosed(e->e1);
      std::cout << "!=";
      print_enclosed(e->e2);
    }

    void visit(less_than_expr* e) {
      print_enclosed(e->e1);
      std::cout << "<";
      print_enclosed(e->e2);
    }

    void visit(greater_than_expr* e) {
      print_enclosed(e->e1);
      std::cout << ">";
      print_enclosed(e->e2);
    }

    void visit(less_than_or_equal_to_expr* e) {
      print_enclosed(e->e1);
      std::cout << "<=";
      print_enclosed(e->e2);

    }

    void visit(greater_than_or_equal_to_expr* e) {
      print_enclosed(e->e1);
      std::cout << ">=";
      print_enclosed(e->e2);
    }

    void visit(add_expr* e) {
      print_enclosed(e->e1);
      std::cout << '+';
      print_enclosed(e->e2);
    }

    void visit(sub_expr* e) {
      print_enclosed(e->e1);
      std::cout << '-';
      print_enclosed(e->e2);
    }

    void visit(multi_expr* e) {
      print_enclosed(e->e1);
      std::cout << '*';
      print_enclosed(e->e2);
    }

    void visit(div_expr* e) {
      print_enclosed(e->e1);
      std::cout << '/';
      print_enclosed(e->e2);
    }

    void visit(rem_expr* e) {
      print_enclosed(e->e1);
      std::cout << '%';
      print_enclosed(e->e2);
    }

    void visit(arithmetic_neg_expr* e) {
      std::cout << '-';
      print_enclosed(e->e1);
    }
  };
  V vis;
  e->accept(vis);
  }
}
