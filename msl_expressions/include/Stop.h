#ifndef Stop_H_
#define Stop_H_
/*PROTECTED REGION ID(inc1413992604875) ENABLED START*/  //Add additional includes here
/*PROTECTED REGION END*/
namespace alica {
class Stop : public BasicBehaviour {
 public:
  Stop();
  virtual ~Stop();
  virtual void run(void* msg);
  /*PROTECTED REGION ID(pub1413992604875) ENABLED START*/  //Add additional public methods here
  /*PROTECTED REGION END*/
 protected:
  int callCounter;
  virtual void initialiseParameters();
  /*PROTECTED REGION ID(pro1413992604875) ENABLED START*/  //Add additional protected methods here
  /*PROTECTED REGION END*/
 private:
  /*PROTECTED REGION ID(prv1413992604875) ENABLED START*/  //Add additional private methods here
  /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Stop_H_ */
