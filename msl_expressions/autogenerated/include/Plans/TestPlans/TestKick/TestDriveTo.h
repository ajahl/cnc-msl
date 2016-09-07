#ifndef TestDriveTo_H_
#define TestDriveTo_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1472648297552) ENABLED START*/ //Add additional includes here
#include "msl_robot/robotmovement/MovementQuery.h"
/*PROTECTED REGION END*/
namespace alica
{
    class TestDriveTo : public DomainBehaviour
    {
    public:
        TestDriveTo();
        virtual ~TestDriveTo();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1472648297552) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1472648297552) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1472648297552) ENABLED START*/ //Add additional private methods here
        double toX;
        double toY;
        shared_ptr<msl::MovementQuery> query;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* TestDriveTo_H_ */
