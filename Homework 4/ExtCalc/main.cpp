#include "evaluate.hpp"
#include "elaborate.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "symbol.hpp"
#include "utilize.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    try{
        std::string input;
        std::vector<std::string> inputs;
        symbol_table sym_tab;
        sym_tab.install();
        while(getline(cin, input))
        {
            lexer lex(input, sym_tab);
            token_stream ts = lex.getTokenStream();
            parser par(ts, sym_tab);
            expr* ast = par.parse();
            type * the_type = elaborate(ast);
            if(the_type != nullptr){
                std::string t = get_type_type(the_type);
                if(t == "int")
                {
                    std::cout << int_evaluate(ast) << std::endl;
                }
                else if(t == "bool")
                {
                    if(bool_evaluate(ast))
                        std::cout << "true" << std::endl;
                    else
                        std::cout << "false" << std::endl;
                }
                else
                {
                    throw std::logic_error("Error");
                }
            }

        }
    }
    catch(exception& err)
    {
        cout << "Error: " << err.what() << endl;
    }
    return 0;
}
