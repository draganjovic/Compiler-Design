#include "scope.hpp"

void
environment::insert(symbol* s, decl* d)
{
  map.insert({s, d});
}

decl*
environment::find(symbol* s)
{
  auto iter = map.find(s);
  if (iter != map.end())
    return iter->second;
  else
    return nullptr;
}
