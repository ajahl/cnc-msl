#include "DomainCondition.h"
#include <SystemConfig.h>

namespace alica
{
	DomainCondition::DomainCondition() :
			BasicCondition()
	{
		this->sc = supplementary::SystemConfig::getInstance();
	}

	DomainCondition::~DomainCondition()
	{
	}
} /* namespace alica */
