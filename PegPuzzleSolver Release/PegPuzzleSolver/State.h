#pragma once

using namespace std;


class State {
public:
	void setState(int start);
	void setParent(State *parent);
	bool getState(int i, int j);
	State* getParent();

	void setPeg(int i, int j);
	void setHole(int i, int j); 

	bool isOccupied(int i, int j);
	bool isOnBoard(int i, int j);

	State();
	State(const State &cSource);
	State& State::operator= (const State &cSource);
	
	

private:
	State* parent = 0;
	bool state[8][8];

};

