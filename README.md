# Gekitai
The objective of this assignment is to let you practice (1) using 2D arrays, and (2) modularizing your
program into appropriate functions.
You will implement a two-player board game called Gekitai (a Japanese word which means “repel” 
or “push away”). Here is the game description from the designer (we rephrased a little bit): Gekitai is 
a 3-in-a-row game played on a 6x6 grid. Each player has eight colored pieces and takes turns placing 
them anywhere on any open space on the board. When placed, a piece pushes all adjacent pieces 
outwards one space if there is an open space for it to move to (or off the board). Pieces shoved off 
the board are returned to the player. If there is not an open space on the opposite side of the 
pushed piece, it does not push (a newly played piece cannot push two or more other lined-up 
pieces). The first player who either (1) lines up three of their color in a row (horizontal or vertical or 
diagonal) at the end of their turn (after pushing), or (2) has all eight of their pieces on the board (also 
after pushing), is declared the winner. To quickly understand how to play this game, you may also 
watch this game review video or play this online game implementing Gekitai. 
The key idea of this game is the “repel” effect when placing a piece onto the board. For example, 
refer to Figure 1 below. Suppose that the player (Red) of the current turn is to put a piece at location 
B2. Then all the three pieces (both the player’s and opponent’s) adjacent to B2 will be pushed away 
by one square outward. So, the black piece originally at A1 is shoved off the board and recycled to 
the player (Black) for making future turns whereas the pieces at C2 and B3 will be repelled to new 
positions D2 and B4 respectively.
