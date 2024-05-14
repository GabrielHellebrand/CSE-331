//
//  advance.hpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 14/05/24.
//
#pragma once

#include <stdio.h>

class Advance
{
private:
   virtual void advance() = 0;

};


class Inertia : Advance
{
   void advance();
};


class Gravity : Advance
{
   void advance();
};



class Buoyancy : Advance
{
   void advance();
};



class Chaos : Advance
{
   void advance();
};
