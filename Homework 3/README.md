# Homework 3 - Parser for Calc

## Overview

The parser is defined in parser.hpp and parser.cpp. The parser is an object with a member variable as the sequence of tokens from the lexer. The constructor takes a sequence of tokens and the context as previously defined. There are several helper functions that the class uses. These include: Eof(), LookAhead(), Consume(), MatchIf(), Match(), and Require(). Followed by the helper functions are all of the parse functions that I had to implement for the parser. Also there are implementations for the declaration statement, expression statement, variable declarations, and type identifiers. I also made the functions throw an exception that says “Error” whenever there was an issue with the inputs. 

The LookAhead() function returns the kind of current token that has been sent from the lexer. The MatchIf() function compares the token kind, and if the current token has the given kind, then it gets consumed. If it doesn’t have the given kind, then the Match() function comes in and gives an error. Lastly, the Require() function made sure that the token had its given kind and that it consumed.

## Tools used
 
1. MacBook Pro (Retina, 13-inch, Early 2015)
2. Dual Monitor Setup
3. Terminal
4. Emacs
5. Atom
6. Xcode

## Semantic Rules

`expression ->` 
      
                              (conditional expression)

`conditional-expression ->`    

                              (logical-or-expression ? expression : expression)

 `logical-or-expression ->`     
 
                              (logical-or-expression || logical-and-expression)
 
 `logical-and-expression ->`    
                    
                              (logical-and-expression && equality-expression)

 `equality-expression ->`        
 
                              (equality-expression == ordering-expression)
                              (equality-expression != ordering=expression) 

 `ordering-expression ->`     
 
                              (ordering-expression < additive-expression)
                              (ordering-expression > additive-expression)
                              (ordering-expression <= additive-expression)
                              (ordering-expression >= additive-expression)
      
`additive-expression ->`      

                              (additive-expression + multiplicative-expression)
                              (additive-expression - multiplicative-expression)
             
 `multiplicative-expression ->` 
 
                              (multiplicative-expression * unary-expression)
                              (multiplicative-expression / unary-expression)
                              (multiplicative-expression % unary-expression)
                             
`unary-expression ->`    

                              (! unary-expression)
                              (- unary-expression)
                              (primary-expression)
                    
`primary-expression ->` 

                             (boolean-literal)
                             (integer-literal)
                             ( expression )
                   
                       

