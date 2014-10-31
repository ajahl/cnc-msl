#include "ConditionCreator.h"

#include  "Plans/WM161413992564408.h"

using namespace alicaAutogenerated;
namespace alica
{

ConditionCreator::ConditionCreator()
{
}
ConditionCreator::~ConditionCreator()
{
}

shared_ptr<BasicCondition> ConditionCreator::createConditions(long conditionConfId)
{
  switch (conditionConfId)
  {

    case 1413992578046:

      return make_shared<TransitionCondition1413992578046>();

      break;

    case 1414752354525:

      return make_shared<TransitionCondition1414752354525>();

      break;

    case 1414769686605:

      return make_shared<TransitionCondition1414769686605>();

      break;

    default:
      cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << endl;
      throw new exception();
      break;
  }
}
}
