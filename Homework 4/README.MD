# Homework 4 : Extended Calc and LLVM

## Overview

In this assignment, I took my existing simple calculator language compiler and transformed it into a much more extended calculator that is capable of doing more things. My implementation can parse an input file and produce an internal representation. I declared all of my visitors, types, and expressions within the “prelude.hpp” source file which includes all of the declarations that are to be used throughout the compiler. My calculator defines two types, which are bool and int. In addition, function types and reference types are included as well. The set of types are the function types, where “t” is a return type of the function. The reference types are the memory locations of the stored objects of type t.

My extended calculator language compiler defines a number of different expressions. Included are Unary Expressions, Arithmetic Expressions, Binary Expressions, Logical Expressions and Literal Expressions. For simplicity, I have organized my expressions into three different sub-groups: Literal Expressions, Unary Expressions and Binary Expressions. Also included with these is the ref_expr for reference types and I also have the conditional expression if_then_else_expr which is first converted into bool and then checked for further conversions if the types are different.

My compiler defines three kinds of different declarations, which include: functions, parameters, and variables. A function def defines an identifier to be a parameterized statement that computes or returns a value of type t. The parameters are declarations that determine the number and type of arguments that the function accepts. Lastly, variables define an identifier to be a stored object of type t whose value is initialized by the given expression. It is good to remember that parameters are not to be declared outside of the functions.

In the previous assignments, I already created my parser and lexer, so therefore I won’t be going into too much detail about them. However, there are two phases of translation that my compiler goes through. First the input file or source text is converted into tokens according to the rules that I established within my lexer. Afterwards, the tokens that were created from my lexer are then analyzed by the parser and parsed to produce an AST, which is an abstract representation of the program. This is how program translation works in my compiler.

In this assignment, I also added source code for scope. I will admit that I did not know how to exactly define scope corresponding to my language, so I looked at and used Dr. Sutton’s example from his compiler as a reference. The global scope covers the whole program, whereas parameter scope covers the region of text at the start of a parameter list of a function and ending at the closing brace of the function. Lastly block scope only covers the region of text with opening and closing brace of a statement.

I added in the “utilize.hpp” and “utilize.cpp” which handles getting the right type. It enables my language to get the correct expression type, and to get the correct type type. Using the visitor functions, my language can process expression types as strings and it can process type types as strings as well. These types also include reference types and function types. With all that said, it is important to note that all of my AST declarations and definitions can be found within “type.hpp” and “expression.hpp”. All of the visitor declarations are within “visitor.hpp” and all of my expressions are within “expression.hpp”.

Lastly, the goal of my language is to provide a compiler that can create LLVM definitions. The purpose of LLVM is to first compile the source code to an intermediate form, and then convert the intermediate code into machine language. LLVM is designed to work like a library. It is flexible. The benefits of this approach are clear and that is why it is part of the assignment. Within the other files, there is a LLVM section that has my LLVM code generation.

This has been a very fun project to work on throughout the semester. I have learned a lot thinking back to when I had my first assignment versus this last assignment. I had no idea what I was doing with the first assignment when I had to create an AST for the language. A few months later and now I have learned how to implement a parser and a lexer and how to even extend my simple calculator that I originally created into a more complex sophisticated language compiler that can support different types and different expressions. There is still a lot that I need to learn. This was a tough assignment. It might not be all 100% correct, but I tried my best and I learned a lot doing so. In the future, I plan on implementing the above and beyond things that my professor recommended doing within the assignments.

## Tools used
 
1. MacBook Pro (Retina, 13-inch, Early 2015)
2. Dual Monitor Setup
3. Terminal
4. Emacs
5. Atom
6. Xcode
