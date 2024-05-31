/***********************************************************************
 * Header File:
 *    Bird : Everything that can be shot
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once
#include "position.h"
#include "score.h"
#include <list>

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
   static Position dimensions; // size of the screen
   Position pt;                  // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   std::list<Status*> audience;
   
public:
    void subscribe(Status* status) { audience.push_back(status); }
    void unsubscribe()
    {
        for (Status* status : audience)
        {
            audience.remove(status);
        }
    }
    void notify(int message)
    {
        for (Status* status : audience)
        {
            status->notify(message);
        }
    }

   Bird() : dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Position    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill(bool isHit)                          
   { 
       if (isHit)
           notify(getPoints());
       else
           notify(-getPoints());
       dead = true; 
       //unsubscribe();
   }
   void setPoints(int pts)              { points = pts;}

   // getters
   bool isDead()           const { return dead;   }
   Position getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw() = 0;
   virtual void advance() = 0;
};

/*********************************************
 * STANDARD
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class Standard : public Bird
{
public:
    Standard(Status* score, Status* hits, double radius = 25.0, double speed = 5.0, int points = 10);
    void draw();
    void advance();
};

/*********************************************
 * FLOATER
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class Floater : public Bird
{
public:
    Floater(Status* score, Status* hits, double radius = 30.0, double speed = 5.0, int points = 15);
    void draw();
    void advance();
};

/*********************************************
 * CRAZY
 * A crazy flying object: randomly changes direction
 *********************************************/
class Crazy : public Bird
{
public:
    Crazy(Status* score, Status* hits, double radius = 30.0, double speed = 4.5, int points = 30);
    void draw();
    void advance();
};

/*********************************************
 * SINKER
 * A sinker bird: honors gravity
 *********************************************/
class Sinker : public Bird
{
public:
    Sinker(Status* score, Status* hits, double radius = 30.0, double speed = 4.5, int points = 20);
    void draw();
    void advance();
};
