using namespace std;
#include "Plans/Behaviours/DriveForward.h"

/*PROTECTED REGION ID(inccpp1414427325853) ENABLED START*/ //Add additional includes here
#include <tuple>
#include <MSLWorldModel.h>
using namespace std;
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1414427325853) ENABLED START*/ //initialise static variables here
/*PROTECTED REGION END*/DriveForward::DriveForward() :
    DomainBehaviour("DriveForward")
{
  /*PROTECTED REGION ID(con1414427325853) ENABLED START*/ //Add additional options here
  /*PROTECTED REGION END*/}
DriveForward::~DriveForward()
{
  /*PROTECTED REGION ID(dcon1414427325853) ENABLED START*/ //Add additional options here
  /*PROTECTED REGION END*/}
void DriveForward::run(void* msg)
{
  /*PROTECTED REGION ID(run1414427325853) ENABLED START*/ //Add additional options here
  msl::MSLWorldModel* wm = msl::MSLWorldModel::get();
  tuple<double, double, double> ownPos = wm->getOwnPosition();
  pair<double, double> alloBallPos = wm->getBallPosition();
  pair<double, double> egoBallPos = wm->allo2Ego(alloBallPos, ownPos);

  cout << "OwnPosition: ( " << get < 0 > (ownPos) << " ; " << get < 1 > (ownPos) << " ; " << get < 2
      > (ownPos) << " )\t Ball: ( " << alloBallPos.first << " ; " << alloBallPos.second << " )" << endl;

  msl_simulator::sim_robot_command c;

  if (fabs(egoBallPos.first) <= 125 && fabs(egoBallPos.second) <= 125)
  {
    c.velangular = 0;
    c.velnormal = 0;
    c.veltangent = 0;
    c.kickspeedx = 2;
    c.kickspeedz = 0;
  }
  else
  {
    c.velnormal = min(egoBallPos.second * 0.002, 2.0);
    c.veltangent = min(egoBallPos.first * 0.002, 2.0);
    c.velangular = 3 * atan2(egoBallPos.second, egoBallPos.first);

  }

  this->send(c);

  /*PROTECTED REGION END*/}
void DriveForward::initialiseParameters()
{
  /*PROTECTED REGION ID(initialiseParameters1414427325853) ENABLED START*/ //Add additional options here
  /*PROTECTED REGION END*/}
/*PROTECTED REGION ID(methods1414427325853) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/} /* namespace alica */
