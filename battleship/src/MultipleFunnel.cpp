#include <iostream>
#include "MultipleFunnel.h"

MultipleFunnel::MultipleFunnel(vector<pair<int, int>>coordinates, bool human, Grid* secondary) : Ship(coordinates, human, secondary)
{}

MultipleFunnel::MultipleFunnel()
{}

bool MultipleFunnel::canTakeShot()
{
	vector<pair<int, int>>possible = possibleTargets();

	if (!isSunk() && !isReloading() && possible.size() > 0)
	{
		return true;
	}
	else
	{
		if (belongsToHuman() && isReloading())
		{
			throw ShipHaveToWaitException();
		}
		return false;
	}
}

void MultipleFunnel::fire()
{
	shotsCounter++;
	if (shotsCounter > 1)
	{
		set_is_reloading(true);
		shotsCounter = 0;
	}
}

