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
	void inertia(Bird& bird);
	virtual void drag(Bird& bird) {};

	virtual void buoyancy(Bird& bird) {};
	virtual void turn(Bird& bird) {};
public:
	void advance(Bird& bird);
};

class StandardAdvance : public Advance
{
private:
	void drag(Bird& bird);
};

class FloaterAdvance : public Advance
{
	void drag(Bird& bird);
	void buoyancy(Bird& bird);
};

class SinkerAdvance : public Advance
{
	void buoyancy(Bird& bird);
};

class CrazyAdvance : public Advance
{
	void turn(Bird& bird);
};

