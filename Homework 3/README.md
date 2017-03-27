##Homework 3 - Parser for Calc

expression -> conditional expression

conditional-expression -> logical-or-expression ? expression : expression 

logical-or-expression -> logical-or-expression || logical-and-expression

logical-and-expression -> logical-and-expression && equality-expression

equality-expression -> equality-expression == ordering-expression
                       equality-expression != ordering=expression
                       

