//
//  advance.hpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 14/05/24.
//
#pragma once

#include <stdio.h>
//#include "bird.h"
#include "position.h"
class Bird;

class Advance
{
public:
   virtual void advance(Velocity &v, Position &pt, int &points, Bird& bird) = 0;

};


class Inertia : public Advance
{
   void advance(Velocity &v, Position &pt, int &points, Bird& bird);
};


class Gravity : public Advance
{
   void advance(Velocity &v, Position &pt, int &points, Bird& bird);
};



class Buoyancy : public Advance
{
   void advance(Velocity &v, Position &pt, int &points, Bird& bird);
};



class Chaos : public Advance
{
   void advance(Velocity &v, Position &pt, int &points, Bird& bird);
   friend int randomInt(int min, int max);
   friend double randomFloat(double min, double max);
};
