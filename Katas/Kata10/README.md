

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

    For 1-byte character, the first bit is a 0, followed by its unicode code.
    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+-------------------------------------
   0000 0000-0000 007F | 0xxxxxxx     
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx     
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents
only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.    Return true.  It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.  

Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.    Return false.  The first 3 bits are all one's and the 4th
bit is 0 means it is a 3-bytes character.  The next byte is a continuation byte which starts with 10 and that's correct.  But the second continuation
byte does not start with 10, so it is invalid.


BREAKDOWN:

The problem can be solved by analyzing each set of integers, first of all each integer can only be in the range 0-255 (not inclusive) to be represented in a byte.
the unicode code is useless to determine if the input is valid as i dont have to check its code. only the range of the number matters to me, ex. 193 to 223 is 110XXXXX, 129-191 is 10XXXXXX
If a number is bigger than 192 it is a n-bytes setter which has to be followed by n-1 numbers in the range 128-191 if any of those isnt in that range it isnt a valid input.

The only way a number smaller than 127 can appear in the input is if it's the first of the array or after a n-bytes character has been processed.
Ranges for the n-bytes indicators:
  192 - 223 : 110XXXXX, 1 extra byte for code
  224 - 239 : 1110XXXX, 2 extra bytes for code     
  240 - 247 : 11110XXX, 3 extra bytes for code       
  248 - 251 : 111110XX, 4 extra bytes for code
  252 - 253 : 1111110X, 5 extra bytes for code
  254       : 11111110, 6 extra bytes for code

255 is not taken as a valid input as per specifications it needs a 0 to end, im considering you can use only one byte to indicate n bytes characters.
