You are given an integer N, followed by N lines of input (1 <= N <= 100). Each line of input contains one or several words separated with single spaces. Each word is a sequence of letters of English alphabet containing between 1 and 10 characters, inclusive. The total number of words in the input is between 1 and 100, inclusive.

Your task is to reverse the order of words in each line of input, while preserving the words themselves. The lines of your output should not have any trailing or leading spaces.

Example

input
3
Hello World
Bye World
Useless World

output
World Hello
World Bye
World Useless

BREAKDOWN

the max amount of characters in a single line is 1011 due to the limitations and including \n.
In order to get the result i need to read each individual line and separate them into different words by using the space between them.
I will save the output into an array of length 100 as i know that is the maximum of words in a single line at a TIME
it is important to re declare everything every line due to the amount of words varying from one to other.
Having the words stored in an array makes it so i just have to go through it backwards.

Base case: 1 word outputs the same
