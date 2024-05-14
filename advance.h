//
//  advance.hpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 14/05/24.
//
#pragma once

#include <stdio.h>
#include "bird.h"

class Advance
{
private:
   virtual void advance(Bird bird) = 0;

};


class Inertia : Advance
{
   void advance(Bird bird);
};


class Gravity : Advance
{
   void advance(Bird bird);
};



class Buoyancy : Advance
{
   void advance(Bird bird);
};



class Chaos : Advance
{
   void advance(Bird bird);
};
