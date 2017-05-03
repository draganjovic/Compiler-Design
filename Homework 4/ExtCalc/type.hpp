#ifndef TYPE_HPP
#define TYPE_HPP

#include "visitor.hpp"

struct type
{
    struct Visitor;
    
    virtual ~type() {}
    virtual void accept(type_visitor &) const = 0;
    
    virtual type const* ref() const;
};

struct int_type : type
{
    void accept(type_visitor & v) const { v.visit(this); }
};

struct bool_type : type
{
    void accept(type_visitor & v) const { v.visit(this); }
};

struct ref_type : type
{
  ref_type(type const* t)
    : first(t)
  { }

  void accept(type_visitor & v) const { v.visit(this); };

  virtual type const* ref() const;

  Type const* type() const { return first; }

  Type const* first;
};

#endif
