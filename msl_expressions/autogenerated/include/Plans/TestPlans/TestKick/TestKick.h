#ifndef TestKick_H_
#define TestKick_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1472648360493) ENABLED START*/ //Add additional includes here
#include "msl_robot/robotmovement/MovementQuery.h"
/*PROTECTED REGION END*/
namespace alica
{
    class TestKick : public DomainBehaviour
    {
    public:
        TestKick();
        virtual ~TestKick();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1472648360493) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1472648360493) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1472648360493) ENABLED START*/ //Add additional private methods here
        shared_ptr<msl::MovementQuery> query;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* TestKick_H_ */
