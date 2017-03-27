# Homework 3 - Parser for Calc

## Semantic Rules

`expression ->` conditional expression

`conditional-expression ->`     logical-or-expression ? expression : expression 

 `logical-or-expression ->`     logical-or-expression || logical-and-expression 
 
 `logical-and-expression ->`    logical-and-expression && equality-expression 

 `equality-expression ->`         equality-expression == ordering-expression
                                  equality-expression != ordering=expression 

 `ordering-expression ->`     (ordering-expression < additive-expression)
                              (ordering-expression > additive-expression)
                              (ordering-expression <= additive-expression)
                              (ordering-expression >= additive-expression)
      
`additive-expression ->` additive-expression + multiplicative-expression
                              additive-expression - multiplicative-expression
             
 `multiplicative-expression ->` multiplicative-expression * unary-expression
                                    multiplicative-expression / unary-expression
                                    multiplicative-expression % unary-expression
                             
`unary-expression ->` ! unary-expression
                           - unary-expression
                           primary-expression
                    
`primary-expression ->` boolean-literal
                             integer-literal
                             ( expression )
                   
                       

