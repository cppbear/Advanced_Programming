#include "Athlete.h"

bool Athlete::checkVisitedPlace(const char* place) const
{
	for (int i = 0; i < places.size(); i++)
	{
		if (places[i] == place)
			return true;
	}
	return false;
}
