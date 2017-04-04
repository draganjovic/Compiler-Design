#ifndef VALUE_HPP
#define VALUE_HPP

enum Types {
  integer_type,
  boolean_type,
};

union result {
  int i;
  bool b;
};

struct Value {
    Types kind;
    result data;
};

#endif
