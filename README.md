# so_long
This project is a very small 2D game. Its purpose is to work with textures, sprites, and some other very basic gameplay elements.

The character has to collect all collectibles and escape. Using `MiniLibX` is mandatory

## Game
- The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.
- The `W`, `A`, `S`, and `D` keys must be used to move the main character.
- The player should be able to move in these 4 directions: **up**, **down**, **left**, **right**.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell (or in the window).
- The game should be 2D (top-down or profile).
- The game doesn’t have to be real time.

## Graphic management
- The program has to display the image in a window.
- The management of the window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing `ESC` must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
- The use of the images of the MiniLibX is mandatory

## Map
- The map has to be constructed with 3 components: **walls**, **collectibles**, and **free
space**.
- The map can be composed of only these 5 characters:\
`0` for an empty space,\
`1` for a wall,\
`C` for a collectible,\
`E` for a map exit,\
`P` for the player’s starting position.
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
_If the map contains a duplicates characters (exit/start), you should
display an error message_
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return
an error.
- There must be a valid path in the map.
- If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return `"Error\n"` followed by an explicit error message of
your choice.

## Bonus
- The player should lose when they touch an enemy patrol.
- There must be some sprite animation in the game.
- The movement count has to be displayed directly on screen not in the shell.

## Launching the program

_Before launching the program you may need to install MiniLibX library. The instructions for the installation can be found in `minilibx-linux` folder in `README` file_

To compile the program use command `make`. Then execute `./so_long maps/map.ber`. The map should have `.ber` extension. Different maps are stored in `maps` folder. Pay attention that some maps are invalid. In this case game doesn't start and shows an error message in the shell. You can create a map of your choice
To compile the program with bonus use command `make bonus`. After launching the program the window with the game will open and the game will start. The gaol is to collect all collectibles and escape. If the character touches the bomb, it dies. To close the window use `x` button or press `ESC`.
