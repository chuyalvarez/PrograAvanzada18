

A password is considered strong if below conditions are all met:

    It has at least 6 characters and at most 20 characters.
    It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
    It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

int strongPasswordChecker(char* s) {    }


Breakdown

I will assume that symbols are a valid input but not required in the passwords.

base case:
 - if the password is 2 characters long then it only needs 4 changes as there is no way that there are 3 characters in succesion.
 - from 3 to 5 ill need to check if after the required changes I still need to add any more characters Ex: 1Ab still need 3 more characters even though it passes the other checks.
 - if the password is over 20 characters long then I need to identify the required changes and also remove characters so its a 20 long password.


In order to analyze the requirements of the passwords I will have to analyze each character one by one and see if any of them meet the requirements if any of them do mark the flag as no longer needed.

For the repeating characters I will just store the current character and and compare it next loop, if its the same turn a flag so i check next time for a third succesion and if there are 3 repeating characters add 1 to the changes and reset so thats there is never 3 in succesion.


Unresolved issues:

THIS WAS FIXED LATER ON
        when you have a password that is more than 24 characters long but also has 3 or more repeating characters you can eliminate those characters instead of swapping one of them and then eliminating others. That is not accounted for in this solution

        Ex:
          AAA01234567890123456a its a 21 length password and has 3 repeating characters. This can be removed in 1 change (removing A) but the program shows 2 as an answer.
