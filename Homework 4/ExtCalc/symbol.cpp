#include "symbol.hpp"

// Symbol

std::string const & symbol::spelling() const
{
    return spell_;
}

token_type symbol::tok() const
{
    return tok_;
}

// Symbol Table

symbol * symbol_table::operator[](std::string str)
{
    auto iter = find(str);
    if(iter != end())
    {
        return iter->second;
    }
    else
    {
        return nullptr;
    }
}

void symbol_table::install()
{
    std::string lp = "(";
    insert(lp, leftparen_tok);
    std::string rp = ")";
    insert(rp, rightparen_tok);
    std::string pl = "+";
    insert(pl, plus_tok);
    std::string mi = "-";
    insert(mi, minus_tok);
    std::string st = "*";
    insert(st, star_tok);
    std::string sl = "/";
    insert(sl, slash_tok);
    std::string pct = "%";
    insert(pct, percent_tok);
    std::string ee = "==";
    insert(ee, equalequal_tok);
    std::string be = "!=";
    insert(be, notequal_tok);
    std::string grt = ">";
    insert(grt, greaterthan_tok);
    std::string let = "<";
    insert(let, lessthaneq_tok);
    std::string grte = ">=";
    insert(grte, greaterthaneq_tok);
    std::string lete = "<=";
    insert(lete, lessthaneq_tok);
    std::string ampr = "&&";
    insert(ampr, and_tok);
    std::string bar = "||";
    insert(bar, or_tok);
    std::string bng = "!";
    insert(bng, bang_tok);
    std::string t = "true";
    insert(t, bool_tok);
    std::string f = "false";
    insert(f, bool_tok;
}
