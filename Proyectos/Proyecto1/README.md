1229. Strong Brickwork
Time limit: 1.0 second
Memory limit: 64 MB

The builders must cover a rectangular area of size M × N (M and N are even numbers) with two layers of bricks that are rectangles of size 1 × 2. The first layer of the bricks has been already completed. The second layer (in an effort to make the brickwork really strong) must be done so, that no brick in it rests on a brick from the first layer.

Given the layout of the bricks in the first layer, determine the possible layout for the second one, or show that it is impossible to make the second layer.


Input
N, M — dimensions of the area. Then N lines follow having M numbers each that describe the layout of the first layer. Each brick is marked with two equal numbers written in the squares of the area that are covered by this brick. All bricks are marked with whole numbers ranging from 1 to the total number of the bricks. M and N are even numbers not exceeding 100.

Output
If there is no solution, then write −1. If the solution exists, write N lines with M numbers each that describe the layout of the second layer in the way shown above.

Breakdown:

base case 2x2 has 2 solutions due to the only way to put another brick is either sideways or up.

I can use the numbers in the first row to determine the layout of the top layer. If there is a diferent number means a different brick and meansa brick sideways need to go there.
