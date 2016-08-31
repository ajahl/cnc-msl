#ifndef TestIdle_H_
#define TestIdle_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1472648936658) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class TestIdle : public DomainBehaviour
    {
    public:
        TestIdle();
        virtual ~TestIdle();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1472648936658) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1472648936658) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1472648936658) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* TestIdle_H_ */
