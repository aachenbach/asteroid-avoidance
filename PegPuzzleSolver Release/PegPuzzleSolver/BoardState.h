#pragma once
#include "State.h"
#include <string>

using namespace std;

class BoardState {
public:
	
	void setSize(int i);
	void setStart(int i);
	void setGoal(int i);
	int getSize();
	bool getStart();
	bool getGoal();
	int getNumHoles();
	string runSearch();

	BoardState& getBoardState();

private:
	int size = 5; //5x5x5
	bool start[36]; 
	bool goal[36]; 
	int numHoles = 15; //number of holes on board

};