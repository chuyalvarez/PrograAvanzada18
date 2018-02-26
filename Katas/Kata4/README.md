65. Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Breakdown:

digits are able to be used indefinitely. Special characters
    . - able to be used only once
    e - separates a set of numbers, and can be followed by a - or + to indicate exponential
    , - can separate subsets of 3 numbers, if the fourth character from a comma is another comma, a period, or the end of the array it is used correctly, if at the fourth character no comma has been used commas can no longer be used
