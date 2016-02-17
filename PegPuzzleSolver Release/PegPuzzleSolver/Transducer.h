#pragma once

#include <string>
#include "BoardState.h"
//#include main functional header file
using namespace std;

class Transducer
{
public:
	string transduce(string command);
	

private:
	//Add main functional object here 
	
	//BoardState *board = new BoardState;
	
	bool startupFiles = false;

};