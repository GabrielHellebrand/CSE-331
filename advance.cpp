//
//  advance.cpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 14/05/24.
//

#include "advance.h"



void Inertia::advance(Bird bird)
{
   // small amount of drag
   v *= 0.995;

   // inertia
   pt.add(v);

   // out of bounds checker
   if (isOutOfBounds())
   {
      kill();
      points *= -1; // points go negative when it is missed!
   }
}


void Gravity::advance(Bird bird)
{
   
}



void Buoyancy::advance(Bird bird)
{
   
}



void Chaos::advance(Bird bird)
{
   
}
