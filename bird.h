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
#include <list>

enum move
{
    DRAG, INERTIA, GRAVITY, ANTIGRAV, OB, RANDOM
};


class Bird; // Forward declaration

class Movements
{
public:
    virtual void advance(Bird* bird) = 0;
};

class Drag : public Movements
{
public:
    void advance(Bird* bird);
};

class Inertia : public Movements
{
public:
    void advance(Bird* bird);
};

class Gravity : public Movements
{
public:
    void advance(Bird* bird);
};

class AntiGrav : public Movements
{
public:
    void advance(Bird* bird);
};

class OBound : public Movements
{
public:
    void advance(Bird* bird);
};

class Random : public Movements
{
public:
    void advance(Bird* bird);
};


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
    std::list<Movements*> movements;

public:
    Bird() : dead(false), points(0), radius(1.0) { }
    virtual ~Bird()
    {
        for (Movements* movement : movements)
        {
            delete movement;
        }
        movements.clear();
    }

    // setters
    void operator=(const Position& rhs) { pt = rhs; }
    void operator=(const Velocity& rhs) { v = rhs; }
    void kill() { dead = true; }
    void setPoints(int pts) { points = pts; }

    // getters
    bool isDead()           const { return dead; }
    Position getPosition()     const { return pt; }
    Velocity getVelocity()  const { return v; }
    double getRadius()      const { return radius; }
    int getPoints() const { return points; }
    bool isOutOfBounds() const
    {
        return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
            pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
    }

    // special functions
    virtual void draw() = 0;

    void getMoves(enum move move)
    {
        switch (move)
        {
        case DRAG:
            movements.push_back(new Drag);
            break;
        case INERTIA:
            movements.push_back(new Inertia);
            break;
        case GRAVITY:
            movements.push_back(new Gravity);
            break;
        case ANTIGRAV:
            movements.push_back(new AntiGrav);
            break;
        case OB:
            movements.push_back(new OBound);
            break;
        case RANDOM:
            movements.push_back(new Random);
            break;
        default:
            break;
        }
    }
    void advance()
    {
        for (auto it = movements.begin(); it != movements.end();)
        {
            (*it)->advance(this);
        }
    }

};

/*********************************************
 * STANDARD
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class Standard : public Bird
{
public:
    Standard(double radius = 25.0, double speed = 5.0, int points = 10);
    void draw();
    //void advance();
};

/*********************************************
 * FLOATER
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class Floater : public Bird
{
public:
    Floater(double radius = 30.0, double speed = 5.0, int points = 15);
    void draw();
    //void advance();
};

/*********************************************
 * CRAZY
 * A crazy flying object: randomly changes direction
 *********************************************/
class Crazy : public Bird
{
public:
    Crazy(double radius = 30.0, double speed = 4.5, int points = 30);
    void draw();
    //void advance();
};

/*********************************************
 * SINKER
 * A sinker bird: honors gravity
 *********************************************/
class Sinker : public Bird
{
public:
    Sinker(double radius = 30.0, double speed = 4.5, int points = 20);
    void draw();
    //void advance();
};
