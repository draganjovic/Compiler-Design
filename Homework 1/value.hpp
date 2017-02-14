#ifndef VALUE_HPP
#define VALUE_HPP

enum Types {
  bool_type,
  integer_type,
};

union result {
  bool b;
  int i;
};

struct Value {
    Types kind;
    result data;
};

#endif
