#include "Transducer.h"
#include <vector>
#include "misc.h"
#include <fstream>
#include <iostream>
#include "BoardState.h"
#include "State.h"
using namespace std;

BoardState board;   
int startPos;

string Transducer::transduce(string command)
{

	string result;
	vector<string> token = tokenize(command);
	if ((token[0] == "HELP") || (token[0] == "H"))
	{
		result = "Commands:\n";
		result += "-------------------\n";
		result += "\tSETSIZE(SS) <size>\n";
		result += "\tSETINITIAL(SI) <position>\n";
		result += "\tSETGOAL(SG) <position>\n";
		result += "\tRUNSEARCH(RS)\n";
		result += "\tHELP(H)\n";
		result += "\tQUIT(Q)\n";
		
		result += "\n";
		result += "Welcome to the Peg Puzzle Solver\n";
		result += "Before running a search, please specify a size (x by x by x), a starting peg to\n";
		result += "remove, and the peg you wish to have remaining at the end. Enter the peg \n";
		result += "positions as an integer based on the following chart, which has a size 5 \n";
		result += "triangle as an example:\n";
		result += "\n";
		result += "Peg Board Position Chart\n";
		result += "---------------------------\n";
		result += "            0            \n\n";
		result += "         1     5          \n\n";
		result += "      2     6    9        \n\n";
		result += "   3     7    10   12     \n\n";
		result += "4    8     11    13   14     \n\n";
	}
	else if ((token[0] == "SETSIZE") || (token[0] == "SS"))
	{
		int temp;
		temp = stringToInt(token[1]);
		board.setSize(temp);
	}
	else if ((token[0] == "SETINITIAL") || (token[0] == "SI"))
	{
		int temp = stringToInt(token[1]);	
		board.setStart(temp);		
		startPos = temp;
	}
	else if ((token[0] == "SETGOAL") || (token[0] == "SG"))
	{
		int temp = stringToInt(token[1]);
		board.setGoal(temp);		
	}
	else if ((token[0] == "RUNSEARCH") || (token[0] == "RS"))
	{
		result = board.runSearch();
	}
	else if ((token[0] == "QUIT") || (token[0] == "Q"))
	{
		result = "";
	}
	else
	{
		result = "Invalid command!";
	}
	return result;
}
