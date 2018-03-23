
  The Goal
Win the race.
  Rules
The circuit of the race is made up of checkpoints. To complete one lap, your vehicle (pod) must pass through each checkpoints in order and back through the start. The first player to reach the starting checkpoint on the final lap wins.

The pods work as follows:

    To pass a checkpoint, the center of a pod must be inside the radius of the checkpoint.
    To move a pod, you must print a target destination point followed by a thrust value. Details of the protocol can be found further down.
    The thrust value of a pod is its acceleration and must be between 0 and 100.
    You can use 1 acceleration boost in the race, you need only replace the thrust value by the BOOST keyword.
    The pods have a circular force-field around their center, with a radius of 400 units, which activates in case of collisions with other pods.


Victory Conditions
Be the first to complete all the laps of the circuit with your pod.

Lose Conditions

    Your program provides incorrect output.
    Your program times out.
    Your pod does not reach the next checkpoint in time.
    Somebody else wins.

  Expert Rules
The game is played on a map 16000 units wide and 9000 units high. The coordinate X=0, Y=0 is the top left pixel.

The checkpoints work as follows:

    The checkpoints are circular, with a radius of 600 units.
    The disposition of the checkpoints is selected randomly for each race.

The pods work as follows:

    If none of your pods make it to their next checkpoint in under 100 turns, you are eliminated and lose the game.
    The pods may move normally outside the game area.


Note: You may activate debug mode in the settings panel () to view additional game data.
  Note
The program must, within an infinite loop, read the contextual data from the standard input and provide to the standard output the desired instructions.
  Game Input
Input for one game turn
First line: 6 integers x & y for your pod's position. nextCheckpointX & nextCheckpointY for the coordinates of the next checkpoint the pod must go through. nextCheckpointDist for the computed distance between your pod and the next checkpoint, nextCheckpointAngle for the angle in degrees between your pod orientation and the direction of the next checkpoint (from -180 to 180).

Second line: 2 integers opponentX & opponentY for the opponent pod's position.
Output for one game turn
One line: 2 integers for the target coordinates of your pod followed by thrust, the thrust to give to your pod. You may replace the thrust value by BOOST.
Constraints
0 ≤ thrust ≤ 100
Response time first turn ≤ 1000ms
Response time per turn ≤ 150ms
