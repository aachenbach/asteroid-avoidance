#pragma once

#include "BoardState.h"
#include "State.h"
#include "Transducer.h"

using namespace std;

extern BoardState board; 

void State::setState(int start) 
{
	int counter = 0;

	for (int i = 0; i < board.getSize(); i++)
	{
		for (int j = i; j < board.getSize(); j++)
		{
			if (counter == start)
			{
				this->state[j][i] = { false };
			}
			else
			{
				this->state[j][i] = { true };
			}
			counter++;
		}		
	}
}

void State::setParent(State *parent)
{
	this->parent = parent;
}

bool State::isOccupied(int j, int i)
{
	if (this->state[j][i] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool State::isOnBoard(int j, int i)
{
	if ((i <= j) && (i < board.getSize()) && (i >= 0) && (j < board.getSize()) && (j >= 0)) //if the point is on the triangle and within bounds of the array
	{															  
		return true;
	}
	else
	{
		return false;
	}	
}

bool State::getState(int j, int i)
{
	return this->state[j][i];
}

void State::setPeg(int j, int i)
{
	this->state[j][i] = true;
}
void State::setHole(int j, int i)
{
	this->state[j][i] = false;
}

State::State(const State &cSource)
{
	parent = cSource.parent;


	for (int i = 0; i < board.getSize(); i++)
	{
		for (int j = i; j < board.getSize(); j++)
		{
			state[j][i] = cSource.state[j][i];
		}
	}	
}


State& State::operator= (const State &cSource)
{
	// do the copy
	
	parent = cSource.parent; 
	
	
	for (int i = 0; i < board.getSize(); i++)
	{
		for (int j = i; j < board.getSize(); j++)
		{
			state[j][i] = cSource.state[j][i];
		}
	}
	
	// return the existing object
	return *this;
}

State::State() //default constructor
{
	parent = 0;

	for (int i = 0; i < board.getSize(); i++)
	{
		for (int j = i; j < board.getSize(); j++)
		{
			state[j][i] = true;
		}
	}
}

State* State::getParent()
{
	return this->parent;
}

