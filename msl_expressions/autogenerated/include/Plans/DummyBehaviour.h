#ifndef DummyBehaviour_H_
#define DummyBehaviour_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1482486255763) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class DummyBehaviour : public DomainBehaviour
    {
    public:
        DummyBehaviour();
        virtual ~DummyBehaviour();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1482486255763) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1482486255763) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1482486255763) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DummyBehaviour_H_ */
