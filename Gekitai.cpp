//Cheung Ka Yan,1155162671,1155162671@link.cuhk.edu.hk
#include <iostream>
#include <stdio.h>      
using namespace std;
const int N = 6;// board size
const int P = 8;// number of pieces per player
const int L = 3;// number of pieces required to form a line

//To check whether the move the valid to put
bool is_valid_move(char board[][N], char player, int y, int x)
{
	int ychar, xchar;
	ychar = y;
	xchar = x;
	bool is_valid_move = false;//Delfault to be cannot move
	//int counter = 0;
	if (ychar > 5 || xchar > 5) 
	{                 
		is_valid_move = false;
	}
	if (board[xchar][ychar] != '.')           
	{
		is_valid_move = false;
	}
	else
	{
		is_valid_move = true;
	}
	return is_valid_move;
}

//To count the number of piece of that player on the gameboard
int pieces_on_board(char board[][N], char player)
{
	int pieces_on_board = 0;
	int temp = 0;//To temporatory store the value of the counted piece
	//int pieces_on_board = 0;//To initalise the count piece is zero on the board
	for (int counter = 0; counter < N; counter++)
	{
		for (int i = 0; i < N; i++)
		{
			if (board[counter][i] == player)
			{
				temp = temp + 1;
			}
		}
	}
	pieces_on_board = temp;
	return pieces_on_board;
}

//To check whether the chesse in L in line
bool pieces_in_line(char board[][N], char player)
{
	bool pieces_in_line = false;
	int addone = 0;
	int temp_check = 0;//To store the temp value of check weather there are l in line
	for (int counter = 0; counter < N; counter++)
	{
		for (int i = 0; i < N; i++)
		{
			if (board[counter][i] == player)
			{
				//check up for player
				addone = i + 1;
				if (board[counter][addone] == player)
				{
					temp_check = temp_check + 1;
				}
				//check down for player
				if (board[counter + 1][i] == player)
				{
					temp_check = temp_check + 1;
				}
				//check upright for player
				addone = i + 1;
				if (board[counter - 1][addone] == player)
				{
					temp_check = temp_check + 1;
				}
				//check downright for player
				addone = i + 1;
				if (board[counter + 1][addone] == player)
				{
					temp_check = temp_check + 1;
				}
			}
			if (temp_check == L)
			{
				pieces_in_line = true;
				break;
			}
		}
		
	}
	return pieces_in_line;
}

//To move the player chesse
void move(char board[][N], char player, int y, int x)
{
	board[x][y] = player;//The player move
	//Check the top row

	if (y - 1 == 0) 
	{
		board[y - 1][x] = '.'; 
	}
	else if (board[y - 2][x] == '.') 
	{
		board[y - 2][x] = board[y - 1][x]; board[y - 1][x] = '.';
	} 
	//Check up
	if (x + 1 == N - 1) 
	{ 
		board[y][x + 1] = '.';
	}
	else if (board[y][x + 2] == '.')
	{
		board[y][x + 2] = board[y][x + 1]; board[y][x + 1] = '.';
	} 
	//Check right
	if (x - 1 == 0 || y - 1 == 0) 
	{ 
		board[y - 1][x - 1] = '.';
	}
	else if (board[y - 2][x - 2] == '.')
	{
		board[y - 2][x - 2] = board[y - 1][x - 1]; board[y - 1][x - 1] = '.';
	} 
	//Check top left
	if (x + 1 == N - 1 || y + 1 == N - 1)
	{ 
		board[y + 1][x + 1] = '.'; 
	}
	else if (board[y + 2][x + 2] == '.')
	{
		board[y + 2][x + 2] = board[y + 1][x + 1]; board[y + 1][x + 1] = '.';
	}
	//Check down right
	if (x - 1 == 0)
	{
		board[y][x - 1] = '.';
	}
	else if (board[y][x - 2] == '.')
	{
		board[y][x - 2] = board[y][x - 1]; board[y][x - 1] = '.';
	}
	//Check left side
	if (x - 1 == 0 || y + 1 == N - 1) 
	{
		board[y + 1][x - 1] = '.'; 
	}
	else if (board[y + 2][x - 2] == '.') 
	{
		board[y + 2][x - 2] = board[y + 1][x - 1]; board[y + 1][x - 1] = '.';
	} 
	//Check down left
	if (y + 1 == N - 1)
	{
		board[y + 1][x] = '.';
	}
	else if (board[y + 2][x] == '.')
	{
		board[y + 2][x] = board[y + 1][x]; board[y + 1][x] = '.';
	}
	//Check downward
	if (x + 1 == N - 1 || y - 1 == 0)
	{
		board[y - 1][x + 1] = '.';
	}
	else if (board[y - 2][x + 2] == '.')
	{
		board[y - 2][x + 2] = board[y - 1][x + 1]; board[y - 1][x + 1] = '.';
	}
	//Check top right
}

//To print the gameboard out
void print(char board[][N])
{
	cout << " ";
	for (int ASCII_count = 0; ASCII_count < N; ASCII_count++)
	{
		cout << char(ASCII_count + 65);
		cout << " ";
	}
	//cout << "  A B C D E F";
	cout << endl;
	for (int counter = 0; counter < N; counter++)
	{
		cout << counter + 1;
		cout << " ";
		//cout << counter, " ";
		for (int i = 0; i < N; i++)
		{
			cout << board[counter][i];
			cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	char board[N][N];
	char player = 'O';
	int round = 1;
	char board_row;
	int board_col;
	int x , y = 0;
	//Empty board
	for (int i = 0; i < N; i++)       
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = '.';
		}
	}
	int tempASCII = 0;
	while (pieces_on_board(board, player) != P && pieces_in_line(board, player) == false)//Loop unitl condition be true
	{	
		cout << "Round ";
		cout << round;
		cout << ":";
		cout << endl;
		print(board);
		cout << "Player ";
		cout << player;
		cout << "'s turn: ";
		cin >> board_row;
		cin >> board_col;
		x = board_col - 1;
		if (board_row >= 'A' && board_row <= 'G')
		{
			tempASCII = board_row - '0' - '0';
			y = tempASCII + 31;
		}
		else
		{
			tempASCII = board_row - '0' - '0';
			y = tempASCII - 1;
		}
		while (is_valid_move(board, player, y, x) == false) //Do when the condition is false
		{
			cout << "Invalid move!";
			cout << endl;
			cout << "Player ";
			cout << player;
			cout << "'s turn: ";
			cin >> board_row;
			cin >> board_col;
			x = board_col - 1;
			if (board_row >= 'A' && board_row <= 'G') 
			{
				tempASCII = board_row - '0' - '0';
				y = tempASCII + 31;
			}
			else
			{
				tempASCII = board_row - '0' - '0';
				y = tempASCII - 1;
			}
		}
		move(board, player, y, x);
		if (player == 'X') player = 'O'; else player = 'X';//Seitch player
		round = round + 1; //Swithch to the next round
	}

	//Check winning condition
	if (pieces_in_line(board, 'X') == true && pieces_in_line(board, 'O') == true)
	{
		print(board);
		cout << "Draw game!";
		cout << endl;
	}
	else if (pieces_on_board(board, player) < P)
	{
		cout << "Game over:";
		cout << endl;
		print(board);
		cout << "Player ";
		cout << player;
		cout << " wins !";
		cout << endl;
	}
}