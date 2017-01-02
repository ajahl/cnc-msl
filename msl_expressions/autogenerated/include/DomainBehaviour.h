#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"

namespace supplementary {
	class SystemConfig;
}

namespace alica
{
class DomainBehaviour : public BasicBehaviour
{
	public:
		DomainBehaviour(string name);
		virtual ~DomainBehaviour();

	protected:
		supplementary::SystemConfig* sc;

	private:

		double __maxTranslation;
		int ownID;
	};
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

