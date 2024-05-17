/***********************************************************************
 * Source File:
 *    Advance : Template Method that handles movement of bird
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Bird movement following a template method
 ************************************************************************/

#include "advance.h"
#include "bird.h"
#include <assert.h>

/******************************************************************
 * RANDOM
 * These functions generate a random number.
 ****************************************************************/
int randomInt(int min, int max);
double randomFloat(double min, double max);

/******************************************************************
 * ADVANCE::inertia
 ******************************************************************/
void Advance::inertia(Bird& bird)
{
	Position& pos = bird.getPositionRef();
	Velocity& v = bird.getVelocityRef();
	pos.add(v);
}

/******************************************************************
 * ADVANCE::advance
 ******************************************************************/
void Advance::advance(Bird& bird)
{
	drag(bird);
	buoyancy(bird);
	turn(bird);
	inertia(bird);
}

/******************************************************************
 * STANDARD ADVANCE::drag
 ******************************************************************/
void StandardAdvance::drag(Bird& bird)
{
	Velocity& velocity = bird.getVelocityRef();
	velocity.setDx(velocity.getDx() * 0.995);
	velocity.setDy(velocity.getDy() * 0.995);
}

/******************************************************************
 * FLOATER ADVANCE::drag
 ******************************************************************/
void FloaterAdvance::drag(Bird& bird)
{
	Velocity& velocity = bird.getVelocityRef(); // Ensure getVelocity() returns a reference
	velocity.setDx(velocity.getDx() * 0.990);
	velocity.setDy(velocity.getDy() * 0.990);
}

/******************************************************************
 * FLOATER ADVANCE::buoyancy
 ******************************************************************/
void FloaterAdvance::buoyancy(Bird& bird)
{
	Velocity& v = bird.getVelocityRef();
	v.addDy(0.05);
}

/*****************************************************************
 * SINKER ADVANCE::buoyancy
 *****************************************************************/
void SinkerAdvance::buoyancy(Bird& bird)
{
	Velocity& v = bird.getVelocityRef();
	v.addDy(-0.07);
}

/*****************************************************************
 * CRAZY ADVANCE::turn
 ****************************************************************/
void CrazyAdvance::turn(Bird& bird)
{
	Velocity& v = bird.getVelocityRef();
	if (randomInt(0, 15) == 0)
	{
		v.addDy(randomFloat(-1.5, 1.5));
		v.addDx(randomFloat(-1.5, 1.5));
	}
}
