#ifndef RobotTest_H_
#define RobotTest_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1456756113767) ENABLED START*/ //Add additional includes here
#include "container/CNPoint2D.h"
#include "container/CNPosition.h"
/*PROTECTED REGION END*/
namespace alica
{
    class RobotTest : public DomainBehaviour
    {
    public:
        RobotTest();
        virtual ~RobotTest();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1456756113767) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1456756113767) ENABLED START*/ //Add additional protected methods here
        int move;

        bool driveForward;
        bool driveBack;
        bool rotateForward;
        bool rotateBack;
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1456756113767) ENABLED START*/ //Add additional private methods here
        bool translationRotationRobot(int movement, bool trans, int duration);

        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* RobotTest_H_ */
