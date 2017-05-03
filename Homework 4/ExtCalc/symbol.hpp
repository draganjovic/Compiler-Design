#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "prelude.hpp"
#include "token.hpp"

// Symbol

struct symbol
{
    class symbol_table;
public:
    //initialize with token kind and text
    symbol(std::string s, token_type t) : spell_(s), tok_(t)
    {}

    virtual ~symbol()
    {}

    std::string const & spelling() const;
    token_type tok() const;

protected:
    std::string spell_; 
    token_type tok_;
};

// Symbol table

class symbol_table: std::unordered_map<std::string, symbol*>
{
public:
    //Destructor
    ~symbol_table();

    // The insertion function
    symbol * insert(std::string& , token_type); // Put a new symbol in the table

    symbol * operator[](std::string);
};

inline symbol *
symbol_table::insert(std::string& text, token_type tok)
{
    auto pair = emplace(text, nullptr);
    auto iter = pair.first;
    if(pair.second)
    {
        // Insertion successful
        iter->second = new symbol(text, tok);
    }

    // Return the symbol pointer
    return iter->second;
}

#endif
