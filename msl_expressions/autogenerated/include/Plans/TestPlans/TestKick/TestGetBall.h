#ifndef TestGetBall_H_
#define TestGetBall_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1472647957600) ENABLED START*/ //Add additional includes here
#include "msl_robot/robotmovement/MovementQuery.h"
/*PROTECTED REGION END*/
namespace alica
{
    class TestGetBall : public DomainBehaviour
    {
    public:
        TestGetBall();
        virtual ~TestGetBall();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1472647957600) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1472647957600) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1472647957600) ENABLED START*/ //Add additional private methods here
        shared_ptr<msl::MovementQuery> query;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* TestGetBall_H_ */
