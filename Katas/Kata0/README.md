TWO SUM

Problem:
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
  Array = [1,8,2,7,3] target = 15

  Answer = 1,5;

Breakdown:

-Simplest problem, array´s length is 2
  In case the array is only 2 in size the answer is 0,1.

-Considerations
  ° If the number in the array is bigger or equal to the target it is not a valid candidate for the result so it can be omited.
  ° Once you select a number you can see which number is needed in order to reach the target and look for it instead of matching all of them with each   other(hash table).

-Steps
  ° Go through the array once, select an element.
  ° If the number is >= to target skip that element.
  ° Substract the element to the target and look for it in the hash table.
  ° If the elemnt exists in the hash table reurn position of both elements; if not add the chosen element to the hash table.
  ° Repeat until done with the array.
