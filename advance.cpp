//
//  advance.cpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 14/05/24.
//

#include "advance.h"
#include "bird.h"
#include <cassert>



void Inertia::advance(Velocity &v, Position &pt, int &points, Bird& bird)
{
   // small amount of drag
   v *= 0.995;

   // inertia
   pt.add(v);

   // out of bounds checker
   if (bird.isOutOfBounds())
   {
      bird.kill();
      points *= -1; // points go negative when it is missed!
   }
}


void Gravity::advance(Velocity &v, Position &pt, int &points, Bird& bird)
{
   // gravity
   v.addDy(-0.07);

   // inertia
   pt.add(v);

   // out of bounds checker
   if (bird.isOutOfBounds())
   {
      bird.kill();
      points *= -1; // points go negative when it is missed!
   }
}



void Buoyancy::advance(Velocity &v, Position &pt, int &points, Bird& bird)
{
   // large amount of drag
   v *= 0.990;

   // inertia
   pt.add(v);

   // anti-gravity
   v.addDy(0.05);

   // out of bounds checker
   if (bird.isOutOfBounds())
   {
      bird.kill();
      points *= -1; // points go negative when it is missed!
   }
   
}


int randomInt(int min, int max);
double randomFloat(double min, double max);


void Chaos::advance(Velocity &v, Position &pt, int &points, Bird& bird)
{
   // erratic turns eery half a second or so
   if (randomInt(0, 15) == 0)
   {
      v.addDy(randomFloat(-1.5, 1.5));
      v.addDx(randomFloat(-1.5, 1.5));
   }

   // inertia
   pt.add(v);

   // out of bounds checker
   if (bird.isOutOfBounds())
   {
      bird.kill();
      points *= -1; // points go negative when it is missed!
   }
}

