# Proposal: Flappy Bird 2.0

## Synopsis

### Elements
Our game will have three main elements:
- a bird avatar, controlled by the player
- endless stream of vertical obstacles that the bird must pass through
- coins that exist in the gaps in some of the obstacles

### Goal
The player's goal is to maximize their score, which is determined by the number of obstacles passed through and the 
number of coins collected.

### Game play
The bird starts out in the center of the left side of the screen. The player starts the game by pressing the space bar,
after which the bird starts flying. The game background begins moving from right to left as if the bird is moving to the
right. The bird also naturally starts falling downwards, and the player presses the space bar to give the bird a boost
upwards to prevent it from falling. Using the space bar, the player needs to help the bird maneuver through as many
obstacles as possible and collect as many coins as they can. If the bird hits the top or bottom of the screen or any of
the obstacles, then it dies and the game ends. The player can press the space bar again to restart.

## Functional requirements

1. The bird initially starts at the center of the left side of the screen.
2. The game starts when the player presses the space bar.
3. The bird automatically moves from left to right at a constant horizontal velocity.
4. The bird flaps once (moves upward by one constant amount) when the player presses the space bar.
5. Otherwise, the bird falls at a constant velocity.
6. Vertical pipes/obstacles have randomly generated gaps of randomly generated sizes (that must be larger than the bird).
7. All pipes are green and vertically stationary. 
8. If the bird hits the top or bottom of the screen or any of the pipes, then it dies, the screen stops moving, and the 
round ends.
9. If the bird passes through one pipe, then the player gains one point.
10. Coins may be randomly placed in the center of some pipes' gaps such that if the bird touches the coin, then the coin 
disappears and the player gains an extra point.
11. After the game is over, the player can press enter to replay.
12. The game will keep track of the high score, and display it after a round ends.

## Open questions

- How can we randomly determine the location and size of the gaps in the obstacles?
- How should we determine whether the bird collides with other objects of different shapes?
- How do we define the bird passing through an obstacle?
- What should the bird's velocity be like (i.e. constant, changing) and how should the boost affect it?

