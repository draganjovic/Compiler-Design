#include "ast.hpp"
#include "value.hpp"
#include <iostream>
#include <cassert>

// Check: check whether bool or int
Type* check(Context& cx, Expr* e) {
    struct V : Expr::Visitor {
        Context& context_;
        Type* value;

        V(Context& c) : context_(c) { }

        void visit(bool_expr* e) {
            value = &context_.bool_type;
        }
        void visit(int_expr* e) {
            value = &context_.int_type;
        }
        void visit(and_expr* e) {
            // check that e->e1 is bool
            assert(check(context_, e->e1) == &context_.bool_type
            // check that e->e2 is bool
            && check(context_, e->e2) == &context_.bool_type);
            value = &context_.bool_type;
        }
        void visit(or_expr* e) {
            // check that e->e1 is bool
            assert(check(context_, e->e1) == &context_.bool_type
            // check that e->e2 is bool
            && check(context_, e->e2) == &context_.bool_type);
            value = &context_.bool_type;
        }
        void visit(xor_expr* e) {
            // check that e->e1 is bool
            assert(check(context_, e->e1) == &context_.bool_type
            // check that e->e2 is bool
            && check(context_, e->e2) == &context_.bool_type);
            value = &context_.bool_type;
        }
        void visit(not_expr* e) {
            // check that e->e1 is bool
            assert(check(context_, e->e1) == &context_.bool_type);
            value = &context_.bool_type;
        }
        void visit(if_then_else_expr* e) {
          //check that e->e1 is bool
          assert(check(context_, e->e1) == &context_.bool_type
          // check that e->e2 is bool
          && check(context_, e->e2) == &context_.bool_type
          // check that e->e3 is bool
          && check(context_, e->e3) == &context_.bool_type);
          value = &context_.bool_type;
        }
        void visit(equal_to_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type ||
            // check that e->e1 is bool
            check(context_, e->e1) == &context_.bool_type
            // check that e->e2 is bool
            && check(context_, e->e2) == &context_.bool_type);
            value = &context_.bool_type;
        }
        void visit(not_equal_to_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type ||
            // check that e->e1 is bool
            check(context_, e->e1) == &context_.bool_type
            // check that e->e2 is bool
            && check(context_, e->e2) == &context_.bool_type);
            value = &context_.bool_type;
        }
        void visit(less_than_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.bool_type;
        }
        void visit(greater_than_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.bool_type;
        }
        void visit(less_than_or_equal_to_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.bool_type;
        }
        void visit(greater_than_or_equal_to_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.bool_type;
        }
        void visit(add_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.int_type;
        }
        void visit(sub_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.int_type;
        }
        void visit(multi_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.int_type;
        }
        void visit(div_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.int_type;
        }
        void visit(rem_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type
            // check that e->e2 is int
            && check(context_, e->e2) == &context_.int_type);
            value = &context_.int_type;
        }
        void visit(arithmetic_neg_expr* e) {
            // check that e->e1 is int
            assert(check(context_, e->e1) == &context_.int_type);
            value = &context_.int_type;
        }

    };
    V vis(context_);
    e->accept(vis);
    return vis.value;
}
