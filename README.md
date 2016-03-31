# compilers_assignment
Implementation of scanner(lexer) and parser for "swift" in c language

Token List for scanner

Keywords: int, float, boolean, string, while, if else, true, false, import, for, return
Operators: +, -, *, /, %, :=, ==, >, <, >=, <=, !=, &&, ||, !, ?, :
Delimiters: {, }, (, ), [, ], ;, ,
Identifiers: must start with a letter (upper or lower case), and may contain zero or more
additional characters as long as they are letters, digits, or underscores
Integer Literals: may begin with an optional plus or minus followed by a sequence of
one or more digits, provided that the first digit can only be zero for the number zero
(which should not have a plus or minus before it).
Floating Point Literals: may begin with an optional plus or minus followed by a
sequence of one or more digits with the same provision above for integers, followed by a
decimal point and one or more digits after the decimal point.
String literals: start and end with a double quote followed by zero or more characters
that may not be newlines, carriage returns, double quotes, or backslashes. The only
