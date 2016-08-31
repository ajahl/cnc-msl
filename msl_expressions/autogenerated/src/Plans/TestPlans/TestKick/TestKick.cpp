using namespace std;
#include "Plans/TestPlans/TestKick/TestKick.h"

/*PROTECTED REGION ID(inccpp1472648360493) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1472648360493) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    TestKick::TestKick() :
            DomainBehaviour("TestKick")
    {
        /*PROTECTED REGION ID(con1472648360493) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    TestKick::~TestKick()
    {
        /*PROTECTED REGION ID(dcon1472648360493) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void TestKick::run(void* msg)
    {
        /*PROTECTED REGION ID(run1472648360493) ENABLED START*/ //Add additional options here
        this->setSuccess(true);
        /*PROTECTED REGION END*/
    }
    void TestKick::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1472648360493) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1472648360493) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
