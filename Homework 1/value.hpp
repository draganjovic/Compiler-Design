#ifndef VALUE_HPP
#define VALUE_HPP

enum Types {
  bool_type,
  int_type,
};

union result {
  bool b;
  int i;
};

struct Value {
    value_type type;
    value_data data;
};

#endif
