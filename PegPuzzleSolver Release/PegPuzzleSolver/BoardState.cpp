#include "BoardState.h"
#include "misc.h"
#include "State.h"
#include <queue>
#include <string>
#include "Transducer.h"

extern BoardState board;
extern int startPos;

using namespace std;

string BoardState::runSearch()
{
	queue<State> myqueue;
	State *current = new State;
	current->setState(startPos); //initializes starting state to TOP peg
	current->setParent(NULL);
	myqueue.push(*current);
	

	while (!myqueue.empty())
	{

		

		State *current = new State(myqueue.front());

		if (board.getSize() == 1)
		{
			string result = "Not possible to solve with given initial, goal and size!";
		}

		if (board.getSize() == 2)
		{
			string result = "Not possible to solve with given initial, goal and size!";
		}

		if (board.getSize() == 3)
		{
			string result = "Not possible to solve with given initial, goal and size!";
		}

		if (board.getSize() == 4)
		{
			if (current->getState(0, 0) == board.goal[0] &&
				current->getState(1, 0) == board.goal[1] &&
				current->getState(1, 1) == board.goal[4] &&
				current->getState(2, 0) == board.goal[2] &&
				current->getState(2, 1) == board.goal[5] &&
				current->getState(2, 2) == board.goal[7] &&
				current->getState(3, 0) == board.goal[3] &&
				current->getState(3, 1) == board.goal[6] &&
				current->getState(3, 2) == board.goal[8] &&
				current->getState(3, 3) == board.goal[9])
			{
				//print all the states from start to goal
				string result;
				State *temp = current;

				result += "Peg Board Position Chart\n";
				result += "---------------------------\n";
				result += "            0            \n\n";
				result += "         1     4          \n\n";
				result += "      2     5    7        \n\n";
				result += "   3     6    8    9     \n\n";
				result += " 0 = EMPTY HOLE   1 = PEG\n";
				result += " Starting state at bottom, goal state at top\n";
				result += " --------------------------------------\n";
				result += " Position: 0  1  2  3  4  5  6  7  8  9\n";
				result += " --------------------------------------\n";

				while (temp != NULL)
				{

					{
						result += "\t   ";
						for (int i = 0; i < board.getSize(); i++)
						{
							for (int j = i; j < board.getSize(); j++)
							{
								result += intToString(temp->getState(j, i));
								result += "  ";
							}
						}
						result += "\n";
					}
					temp = temp->getParent();
				}

				return result;
			}
		}

		if (board.getSize() == 5)
		{


			if (current->getState(0, 0) == board.goal[0] &&
				current->getState(1, 0) == board.goal[1] &&
				current->getState(1, 1) == board.goal[5] &&
				current->getState(2, 0) == board.goal[2] &&
				current->getState(2, 1) == board.goal[6] &&
				current->getState(2, 2) == board.goal[9] &&
				current->getState(3, 0) == board.goal[3] &&
				current->getState(3, 1) == board.goal[7] &&
				current->getState(3, 2) == board.goal[10] &&
				current->getState(3, 3) == board.goal[12] &&
				current->getState(4, 0) == board.goal[4] &&
				current->getState(4, 1) == board.goal[8] &&
				current->getState(4, 2) == board.goal[11] &&
				current->getState(4, 3) == board.goal[13] &&
				current->getState(4, 4) == board.goal[14]) //check and see if we are done

			{
				//print all the states from start to goal
				string result;
				State *temp = current;

				result += "Peg Board Position Chart\n";
				result += "---------------------------\n";
				result += "            0            \n\n";
				result += "         1     5          \n\n";
				result += "      2     6    9        \n\n";
				result += "   3     7    10   12     \n\n";
				result += "4    8     11    13   14     \n\n";
				result += " 0 = EMPTY HOLE   1 = PEG\n";
				result += " Starting state at bottom, goal state at top\n";
				result += " -----------------------------------------------------\n";
				result += " Position: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14\n";
				result += " -----------------------------------------------------\n";

				while (temp != NULL)
				{
					
					{
						result += "\t ";
			
						for (int i = 0; i < board.getSize(); i++)
						{
							for (int j = i; j < board.getSize(); j++)
							{
								result += "  ";
								result += intToString(temp->getState(j, i));
							}
						}
						result += "\n";
					}
					
					temp = temp->getParent();
				}

				return result;
			}
		}
		

		if (board.getSize() == 6)
		{


			if (current->getState(0, 0) == board.goal[0] &&
				current->getState(1, 0) == board.goal[1] &&
				current->getState(1, 1) == board.goal[6] &&
				current->getState(2, 0) == board.goal[2] &&
				current->getState(2, 1) == board.goal[7] &&
				current->getState(2, 2) == board.goal[11] &&
				current->getState(3, 0) == board.goal[3] &&
				current->getState(3, 1) == board.goal[8] &&
				current->getState(3, 2) == board.goal[12] &&
				current->getState(3, 3) == board.goal[15] &&
				current->getState(4, 0) == board.goal[4] &&
				current->getState(4, 1) == board.goal[9] &&
				current->getState(4, 2) == board.goal[13] &&
				current->getState(4, 3) == board.goal[16] &&
				current->getState(4, 4) == board.goal[18] &&
				current->getState(5, 0) == board.goal[5] &&
				current->getState(5, 1) == board.goal[10] &&
				current->getState(5, 2) == board.goal[14] &&
				current->getState(5, 3) == board.goal[17] &&
				current->getState(5, 4) == board.goal[19] &&
				current->getState(5, 5) == board.goal[20]) //check and see if we are done

			{
				//print all the states from start to goal
				string result;
				State *temp = current;

				result += " 0 = EMPTY HOLE   1 = PEG\n";
				result += " Starting state at bottom, goal state at top\n";
				result += " -----------------------------------------------------------------------\n";
				result += " Position: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20\n";
				result += " -----------------------------------------------------------------------\n";

				while (temp != NULL)
				{

					{
						result += "\t ";

						for (int i = 0; i < board.getSize(); i++)
						{
							for (int j = i; j < board.getSize(); j++)
							{
								result += "  ";
								result += intToString(temp->getState(j, i));
							}
						}
						result += "\n";
					}

					temp = temp->getParent();
				}

				return result;
			}
		}

		/////////////////////////////////////////////////////////////////////
		myqueue.pop(); //pop top state off stack

		for (int i = 0; i < board.getSize(); i++) //loop through all the holes
		{
			for (int j = i; j < board.getSize(); j++)
			{
				if (current->getState(j, i) == true) //if theres a peg in the hole at (i,j), lets check to see its available moves
				{
					//logic here to check for available moves for the peg located at i, j --- use isOnBoard and isOccupied --- see video
					//move right
					if (current->isOnBoard(j, (i + 1)) && current->isOnBoard(j, (i + 2)) && current->isOccupied(j, (i + 1)) && !current->isOccupied(j, (i + 2)))
					{
						State *temp = new State(*current); 
						temp->setParent(current);
						temp->setHole(j, i);
						temp->setHole(j, i + 1);
						temp->setPeg(j, i + 2);
						myqueue.push(*temp);
						
					}
					//move down and to the right
					if (current->isOnBoard((j + 1), (i + 1)) && current->isOnBoard((j + 2), (i + 2)) && current->isOccupied((j + 1), (i + 1)) && !current->isOccupied((j + 2), (i + 2)))
					{
						State *temp = new State(*current);
						temp->setParent(current);
						temp->setHole(j, i);
						temp->setHole(j + 1, i + 1);
						temp->setPeg(j + 2, i + 2);
						myqueue.push(*temp);
						
					}
					//move down and to the left
					if (current->isOnBoard((j + 1), i) && current->isOnBoard((j + 2), i) && current->isOccupied((j + 1), i) && !current->isOccupied((j + 2), i))
					{
						State *temp = new State(*current);
						temp->setParent(current);
						temp->setHole(j, i);
						temp->setHole(j + 1, i);
						temp->setPeg(j + 2, i);
						myqueue.push(*temp);
						
					}
					//move left
					if (current->isOnBoard(j, (i - 1)) && current->isOnBoard(j, (i - 2)) && current->isOccupied(j, (i - 1)) && !current->isOccupied(j, (i - 2)))
					{
						State *temp = new State(*current);
						temp->setParent(current);
						temp->setHole(j, i);
						temp->setHole(j, i - 1);
						temp->setPeg(j, i - 2);
						myqueue.push(*temp);
						
					}
					//move up and to the left
					if (current->isOnBoard((j - 1), (i - 1)) && current->isOnBoard((j - 2), (i - 2)) && current->isOccupied((j - 1), (i - 1)) && !current->isOccupied((j - 2), (i - 2)))
					{
						State *temp = new State(*current);
						temp->setParent(current);
						temp->setHole(j, i);
						temp->setHole(j - 1, i - 1);
						temp->setPeg(j - 2, i - 2);
						myqueue.push(*temp);
						
					}
					//move up and to the right
					if (current->isOnBoard((j - 1), i) && current->isOnBoard((j - 2), i) && current->isOccupied((j - 1), i) && !current->isOccupied((j - 2), i))
					{
						State *temp = new State(*current);
						int hello = 5; //delete this
						temp->setParent(current);
						temp->setHole(j, i);
						temp->setHole(j - 1, i);
						temp->setPeg(j - 2, i);
						myqueue.push(*temp);
						
					}
				}
			}
		}

				
	}

	string result = "Not possible to solve with given initial, goal and size!";
	return result;
}

void BoardState::setSize(int i)
{
	this->size = i;
	int temp = 0;
	for (int j = i; j > 0; j--)
	{
		temp += j;
	}
	this->numHoles = temp;
}

void BoardState::setStart(int i)
{
	for (int j = 0; j < board.getNumHoles(); j++)//15 should be number of holes in terms of boardsize
	{
		if (j == i)
		{
			this->start[j] = false;
		}
		else
		{
			this->start[j] = true;
		}
	}
}

void BoardState::setGoal(int i)
{
	for (int j = 0; j < board.getNumHoles(); j++)//15 should be number of holes in terms of boardsize
	{
		if (j == i)
		{
			this->goal[j] = true;
		}
		else
		{
			this->goal[j] = false;
		}
	}

}

int BoardState::getSize()
{
	return size;
}

int BoardState::getNumHoles()
{
	return numHoles;
}

bool BoardState::getStart()
{
	return start;
}

bool BoardState::getGoal()
{
	return goal;
}

BoardState& getBoardState()
{
	static BoardState board; 
	return board; 
}



