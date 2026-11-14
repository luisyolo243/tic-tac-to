#include"TicTacToe.h"

#include<iostream> 
#include<string>



void TicTacToe::playGame(twoDGrid& ticTacToeGrid)
{

	//how to stop this game? 

	//for () //probably NOT a good approach (definite loop) 
	bool isGameWon = false;
	int moveCount = 0;

	while (isGameWon == false) //while the game is not yet won, do the stuff in the body of the loop 
	{
		//(prompt players for moves)
		printTheGrid(ticTacToeGrid);

		std::cout << "Player X, enter your move: " << std::endl;
		std::cout << "Allowed moves are:" << std::endl;
		std::cout << "abc" << std::endl; //doing this prevents user from having to say 0, 0 or 1, 2, etc.
		std::cout << "def" << std::endl;
		std::cout << "ghi" << std::endl;

		std::string playerXMove;

		std::getline(std::cin, playerXMove);

		//ticTacToeGrid[0][0] = "X";
		updateGrid(ticTacToeGrid, playerXMove, "X");
		moveCount = moveCount + 1; //alternatively: moveCount++; 

		if (moveCount >= 5) //alternatively: moveCount > 4
		{
			isGameWon = checkForWin(ticTacToeGrid);

			if (isGameWon == true)
			{
				break; //exits the loop
			}
		}

		//if all 9 squares are used and nobody won, it's a draw
		if (moveCount == 9)
		{
			printTheGrid(ticTacToeGrid);
			std::cout << "It's a draw!" << std::endl;
			break;
		}

		//after X makes a move, we should show O what the updated grid looks like: 
		std::cout << "After the player X made a move, the grid looks like:" << std::endl;
		printTheGrid(ticTacToeGrid);

		/*now player O moves :*************************************************************/
		std::cout << std::endl << std::endl; //makes 2 blank lines for spacing
		std::cout << "Now player O" << std::endl;
		std::string playerOMove;

		std::getline(std::cin, playerOMove);

		updateGrid(ticTacToeGrid, playerOMove, "O");
		moveCount++;

		if (moveCount >= 5) //alternatively: moveCount > 4
		{
			isGameWon = checkForWin(ticTacToeGrid);

			if (isGameWon == true)
			{
				break;
			}
		}


		printTheGrid(ticTacToeGrid);



	}

} //end of the playGame function

void TicTacToe::updateGrid(twoDGrid& ticTacToeGrid, std::string theMove, std::string playerID)
{
	//switch requires chars (or ints) -> strings will NOT work 

	//1st row:
	if (theMove == "a")
	{
		ticTacToeGrid[0][0] = playerID;
	}

	else if (theMove == "b")
	{
		ticTacToeGrid[0][1] = playerID;
	}

	else if (theMove == "c")
	{
		ticTacToeGrid[0][2] = playerID;
	}

	//2nd row: 
	else if (theMove == "d")
	{
		ticTacToeGrid[1][0] = playerID;
	}

	else if (theMove == "e")
	{
		ticTacToeGrid[1][1] = playerID;
	}

	else if (theMove == "f")
	{
		ticTacToeGrid[1][2] = playerID;
	}

	//3rd row:
	else if (theMove == "g")
	{
		ticTacToeGrid[2][0] = playerID;
	}

	else if (theMove == "h")
	{
		ticTacToeGrid[2][1] = playerID;
	}

	else if (theMove == "i")
	{
		ticTacToeGrid[2][2] = playerID;
	}

	else
	{
		std::cout << "That isn't a valid move - you lose your turn! (too harsh?)" << std::endl;
	}
}

void TicTacToe::printTheGrid(twoDGrid& ticTacToeGrid)
{
	//n****** loop
	for