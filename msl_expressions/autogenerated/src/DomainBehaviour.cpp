#include "DomainBehaviour.h"

#include <SystemConfig.h>

namespace alica
{
	DomainBehaviour::DomainBehaviour(string name) :
			BasicBehaviour(name)
	{
		this->sc = supplementary::SystemConfig::getInstance();
		this->ownID = sc->getOwnRobotID();
	}

	DomainBehaviour::~DomainBehaviour()
	{
	}

} /* namespace alica */

