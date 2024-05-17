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
void Advance::inertia(const Bird& bird)
{
	bird.getPosition().add(bird.getVelocity());
}

/******************************************************************
 * ADVANCE::advance
 ******************************************************************/
void Advance::advance(const Bird& bird)
{
	drag(bird);
	inertia(bird);
	buoyancy(bird);
	turn(bird);
}

/******************************************************************
 * STANDARD ADVANCE::drag
 ******************************************************************/
void StandardAdvance::drag(const Bird& bird)
{
	bird.getVelocity() *= 0.995;
}

/******************************************************************
 * FLOATER ADVANCE::drag
 ******************************************************************/
void FloaterAdvance::drag(const Bird& bird)
{
	bird.getVelocity() *= 0.995;
}

/******************************************************************
 * FLOATER ADVANCE::buoyancy
 ******************************************************************/
void FloaterAdvance::buoyancy(const Bird& bird)
{
	bird.getVelocity().addDy(0.05);
}

/*****************************************************************
 * SINKER ADVANCE::buoyancy
 *****************************************************************/
void SinkerAdvance::buoyancy(const Bird& bird)
{
	bird.getVelocity().addDy(-0.07);
}

/*****************************************************************
 * CRAZY ADVANCE::turn
 ****************************************************************/
void CrazyAdvance::turn(const Bird& bird)
{
	if (randomInt(0, 15) == 0)
	{
		bird.getVelocity().addDy(randomFloat(-1.5, 1.5));
		bird.getVelocity().addDx(randomFloat(-1.5, 1.5));
	}
}
