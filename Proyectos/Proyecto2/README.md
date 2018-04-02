Problem C. Crime House

While working for the police, you've identified a house where people go to commit crimes, called Crime House. One day, you set up a camera over the door of the house and record a video.

You don't know how many people were in Crime House at the start of the day, but you can see people enter and leave through the front door. Unfortunately, because the people entering and leaving Crime House are criminals, sometimes they wear masks; and you aren't quite sure if the front door is the only way in or out.

Sometimes you can guess who was wearing a mask. If criminal #5 entered the house, then someone wearing a mask left, then criminal #5 entered the house again, then either the person wearing the mask was criminal #5, or there is another way out of Crime House.

At the end of the day, when Crime House has closed its doors for the night, you watch your video. Because you're an optimist, you want to figure out if it's possible that there are no other entrances or exits from crime house; and if so, you want to figure out the minimum number of people who could be in Crime House at the end of the day.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing a single integer N, the number of times people pass through the front door of Crime House in the day. Next follows N lines, each of which contains information about one person entering or leaving Crime House through the front door.

That information consists of a single character, E or L, followed by a space and then an integer id. If the first character is E, that indicates someone entered Crime House through the front door; if it's L, someone left through the front door. If id is greater than zero, the person with that identifier entered or left Crime House. If id is zero, then the person who entered or left Crime House was wearing a mask, and we don't know who he or she was.
Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1). If it's possible that there are no other entrances or exits from Crime House, then y should be the minimum number of people who could be in Crime House at the end of the day. If that's impossible, y should be "CRIME TIME".
Limits

1 ≤ T ≤ 100.
0 ≤ id ≤ 2000.


BREAKDOWN:

In essence this problem entails keeping track of which and how many individuals enter and exit the place but with the twists that their id is unknown. There is no limit to how  many times a person can exit or enter a building as long as those actions are possible when only having one entrance.

-invalid cases: the same id cannot exit or enter twice in a row without the existance of another door which means that I should output CRIME TIME or if there is a contrary unknwn id operation to the one repeated in between both of them it is still possible for there to be only one door.

unknown id Ls and Es are not to be counted until all the actions are processed unless a set of actions requires a unknown L (see above).

A person can leave even if the person hasnt entered the building due to the possibility of it staying overnight. 
