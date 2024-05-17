/***********************************************************************
 * Header File:
 *    Advance
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Template method implementation for the movement of birds
 ************************************************************************/
#pragma once

class Bird;

class Advance
{
private:
	void inertia(const Bird& bird);
	virtual void drag(const Bird& bird) {};

	virtual void buoyancy(const Bird& bird) {};
	virtual void turn(const Bird& bird) {};
public:
	void advance(const Bird& bird);
};

class StandardAdvance : public Advance
{
private:
	void drag(const Bird& bird);
};

class FloaterAdvance : public Advance
{
	void drag(const Bird& bird);
	void buoyancy(const Bird& bird);
};

class SinkerAdvance : public Advance
{
	void buoyancy(const Bird& bird);
};

class CrazyAdvance : public Advance
{
	void turn(const Bird& bird);
};

