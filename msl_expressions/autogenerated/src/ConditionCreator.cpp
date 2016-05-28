#include "ConditionCreator.h"

#include  "Plans/GameStrategy/Other/Parking1426695119330.h"

#include  "Plans/GameStrategy/Other/DropBallPositioning1455537014534.h"

#include  "Plans/GenericStandards/GenericOppStandards1432132075122.h"

#include  "Plans/Defence/BackroomDefence1454507425037.h"

#include  "Plans/GenericStandards/GenericExecute1431522123418.h"

#include  "Plans/Attack/StandardAttack1434046634656.h"

#include  "Plans/Attack/AttackPlay1434045709191.h"

#include  "Plans/Attack/TestPlans/TestPassPointMaster1441106724156.h"

#include  "Plans/WM161413992564408.h"

#include  "Plans/TwoHoledWall/TwoHoledWallMaster1417621468963.h"

#include  "Plans/Attack/TestPlans/TestAttackPlan1436960675873.h"

#include  "Plans/Attack/TestPlans/RobotMovementTestPlan1462969665131.h"

#include  "Plans/Standards/Opponent/FreeKick/OppFreeKick1445411471122.h"

#include  "Plans/TestPlans/KickCurveTuning/KickCurveTuning1457698586746.h"

#include  "Plans/Defence/MidfieldDefense1458033329973.h"

#include  "Plans/Defence/MidfieldBlock1458033620834.h"

#include  "Plans/GameStrategy/Gameplay/GamePlay1457173546734.h"

#include  "Plans/GameStrategy/Other/DroppedBall1426694906399.h"

#include  "Plans/Attack/PassPlay1436268896671.h"

#include  "Plans/Standards/Own/Corner/CornerPosBounceShot1459361999064.h"

#include  "Plans/Attack/StandardKickOff1438777024734.h"

#include  "Plans/Defence/ReleaseOwnHalf1458033644590.h"

#include  "Plans/GenericStandards/DummyMasterPlan1432139066765.h"

#include  "Plans/CarpetCalibrator1435159127771.h"

#include  "Plans/GameStrategy/Gameplay/DefendPlay1457173681216.h"

#include  "Plans/Attack/TestPlans/AttackOppGoalPlan1437902649389.h"

#include  "Plans/Standards/Own/ThrowIn/ThrowInOwnHalf1462360503828.h"

#include  "Plans/Attack/Dribble1434049476066.h"

#include  "Plans/Goalie/Test/GoalieDefault1447254438614.h"

#include  "Plans/Attack/ProtectBall1449151802193.h"

#include  "Plans/Example/ExamplePlan1433938652021.h"

#include  "Plans/Standards/Opponent/FreeKick/StopRobots1457015643757.h"

#include  "Plans/Attack/TestPlans/DribbleToPointPlan1436960829485.h"

#include  "Plans/Attack/RunFree1434115664325.h"

#include  "Plans/Standards/Own/Corner/CornerBounceShot1459361887233.h"

#include  "Plans/Attack/TestPlans/TestDriveToMiddle1457434329037.h"

#include  "Plans/Attack/TestPlans/PassPlan1441106995954.h"

#include  "Plans/Standards/Opponent/OppStandardExecution1457015277573.h"

#include  "Plans/Standards/Own/ThrowIn/ThrowInNearGoal1461237603689.h"

#include  "Plans/Attack/TestPlans/TestCheckGoalKick1449076138236.h"

#include  "Plans/Attack/AttackSupportPlan1434046705214.h"

#include  "Plans/Attack/TestPlans/TestDribblePlan1437902404050.h"

#include  "Plans/Standards/Own/Corner/CornerKick1462373376006.h"

#include  "Plans/Standards/Own/PassIntoPath/PassIntoPath1457530916296.h"

#include  "Plans/GameStrategy/Other/SimpleDropBall1426696586622.h"

#include  "Plans/Defence/Test/TestApproachBallMaster1430324312981.h"

#include  "Plans/Attack/TestPlans/DuelTestMaster1454506180437.h"

#include  "Plans/Standards/Own/KickOff/OwnKickOff1438785376159.h"

#include  "Plans/GameStrategy/Other/DropBallExecution1455537039421.h"

#include  "Plans/Standards/Own/Corner/CornerExecBounceShot1459362028865.h"

#include  "Plans/GameStrategy/Other/WanderPlan1458553921358.h"

#include  "Plans/Robotcheck/Robotcheck1456756058055.h"

#include  "Plans/TwoHoledWall/ShootTwoHoledWall1417620189234.h"

#include  "Plans/Calibration/MotionCalibration1442919721161.h"

#include  "Plans/GenericStandards/GenericDefend1432133473779.h"

#include  "Plans/Penalty/OwnPenalty1431525185678.h"

#include  "Plans/Attack/Duel1450178655416.h"

#include  "Plans/Attack/Tackle1434116965565.h"

#include  "Plans/GenericStandards/GenericOwnStandards1430924951132.h"

#include  "Plans/Defence/Test/TestBackroomDefence1455127495970.h"

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

            case 1429111678112:

                return make_shared<TransitionCondition1429111678112>();

                break;

            case 1432132367859:

                return make_shared<TransitionCondition1432132367859>();

                break;

            case 1432132369717:

                return make_shared<TransitionCondition1432132369717>();

                break;

            case 1432132371055:

                return make_shared<TransitionCondition1432132371055>();

                break;

            case 1432132372365:

                return make_shared<TransitionCondition1432132372365>();

                break;

            case 1432132373471:

                return make_shared<TransitionCondition1432132373471>();

                break;

            case 1432132374502:

                return make_shared<TransitionCondition1432132374502>();

                break;

            case 1432132432036:

                return make_shared<TransitionCondition1432132432036>();

                break;

            case 1432132434051:

                return make_shared<TransitionCondition1432132434051>();

                break;

            case 1432132436308:

                return make_shared<TransitionCondition1432132436308>();

                break;

            case 1432132438181:

                return make_shared<TransitionCondition1432132438181>();

                break;

            case 1432132441034:

                return make_shared<TransitionCondition1432132441034>();

                break;

            case 1432132442910:

                return make_shared<TransitionCondition1432132442910>();

                break;

            case 1457955744730:

                return make_shared<RunTimeCondition1457955744730>();

                break;

            case 1431522783626:

                return make_shared<TransitionCondition1431522783626>();

                break;

            case 1431522922124:

                return make_shared<TransitionCondition1431522922124>();

                break;

            case 1431523013533:

                return make_shared<TransitionCondition1431523013533>();

                break;

            case 1431524871023:

                return make_shared<TransitionCondition1431524871023>();

                break;

            case 1433949707598:

                return make_shared<TransitionCondition1433949707598>();

                break;

            case 1435761870069:

                return make_shared<TransitionCondition1435761870069>();

                break;

            case 1434048722207:

                return make_shared<TransitionCondition1434048722207>();

                break;

            case 1434048723635:

                return make_shared<TransitionCondition1434048723635>();

                break;

            case 1434048731181:

                return make_shared<TransitionCondition1434048731181>();

                break;

            case 1434048737070:

                return make_shared<TransitionCondition1434048737070>();

                break;

            case 1434716048353:

                return make_shared<TransitionCondition1434716048353>();

                break;

            case 1434716049299:

                return make_shared<TransitionCondition1434716049299>();

                break;

            case 1434716050319:

                return make_shared<TransitionCondition1434716050319>();

                break;

            case 1450175866027:

                return make_shared<TransitionCondition1450175866027>();

                break;

            case 1450175867019:

                return make_shared<TransitionCondition1450175867019>();

                break;

            case 1450175926118:

                return make_shared<TransitionCondition1450175926118>();

                break;

            case 1450175931490:

                return make_shared<TransitionCondition1450175931490>();

                break;

            case 1457687428316:

                return make_shared<TransitionCondition1457687428316>();

                break;

            case 1434112519736:

                return make_shared<RunTimeCondition1434112519736>();

                break;

            case 1436536099859:

                return make_shared<TransitionCondition1436536099859>();

                break;

            case 1436536101707:

                return make_shared<TransitionCondition1436536101707>();

                break;

            case 1436536103010:

                return make_shared<TransitionCondition1436536103010>();

                break;

            case 1436536104021:

                return make_shared<TransitionCondition1436536104021>();

                break;

            case 1436536150520:

                return make_shared<TransitionCondition1436536150520>();

                break;

            case 1436536151584:

                return make_shared<TransitionCondition1436536151584>();

                break;

            case 1436536152571:

                return make_shared<TransitionCondition1436536152571>();

                break;

            case 1436536161660:

                return make_shared<TransitionCondition1436536161660>();

                break;

            case 1441106955179:

                return make_shared<TransitionCondition1441106955179>();

                break;

            case 1441106956349:

                return make_shared<TransitionCondition1441106956349>();

                break;

            case 1426691976695:

                return make_shared<TransitionCondition1426691976695>();

                break;

            case 1426691979272:

                return make_shared<TransitionCondition1426691979272>();

                break;

            case 1426691980585:

                return make_shared<TransitionCondition1426691980585>();

                break;

            case 1426692078983:

                return make_shared<TransitionCondition1426692078983>();

                break;

            case 1426692165988:

                return make_shared<TransitionCondition1426692165988>();

                break;

            case 1426692246279:

                return make_shared<TransitionCondition1426692246279>();

                break;

            case 1426692307991:

                return make_shared<TransitionCondition1426692307991>();

                break;

            case 1426692309848:

                return make_shared<TransitionCondition1426692309848>();

                break;

            case 1426692322491:

                return make_shared<TransitionCondition1426692322491>();

                break;

            case 1426692324569:

                return make_shared<TransitionCondition1426692324569>();

                break;

            case 1426692326693:

                return make_shared<TransitionCondition1426692326693>();

                break;

            case 1426692328653:

                return make_shared<TransitionCondition1426692328653>();

                break;

            case 1426692330833:

                return make_shared<TransitionCondition1426692330833>();

                break;

            case 1426692332679:

                return make_shared<TransitionCondition1426692332679>();

                break;

            case 1426692655810:

                return make_shared<TransitionCondition1426692655810>();

                break;

            case 1417621600501:

                return make_shared<TransitionCondition1417621600501>();

                break;

            case 1417621604870:

                return make_shared<TransitionCondition1417621604870>();

                break;

            case 1417621607305:

                return make_shared<TransitionCondition1417621607305>();

                break;

            case 1417621611163:

                return make_shared<TransitionCondition1417621611163>();

                break;

            case 1422464818034:

                return make_shared<TransitionCondition1422464818034>();

                break;

            case 1422464821945:

                return make_shared<TransitionCondition1422464821945>();

                break;

            case 1422464825529:

                return make_shared<TransitionCondition1422464825529>();

                break;

            case 1422464875980:

                return make_shared<TransitionCondition1422464875980>();

                break;

            case 1436960798234:

                return make_shared<TransitionCondition1436960798234>();

                break;

            case 1436960799378:

                return make_shared<TransitionCondition1436960799378>();

                break;

            case 1462969760665:

                return make_shared<TransitionCondition1462969760665>();

                break;

            case 1462969788458:

                return make_shared<TransitionCondition1462969788458>();

                break;

            case 1445442215438:

                return make_shared<RunTimeCondition1445442215438>();

                break;

            case 1447875675479:

                return make_shared<TransitionCondition1447875675479>();

                break;

            case 1454663210272:

                return make_shared<TransitionCondition1454663210272>();

                break;

            case 1454663213143:

                return make_shared<TransitionCondition1454663213143>();

                break;

            case 1457698634601:

                return make_shared<TransitionCondition1457698634601>();

                break;

            case 1457698635818:

                return make_shared<TransitionCondition1457698635818>();

                break;

            case 1458033411271:

                return make_shared<TransitionCondition1458033411271>();

                break;

            case 1458033412464:

                return make_shared<TransitionCondition1458033412464>();

                break;

            case 1458033413418:

                return make_shared<TransitionCondition1458033413418>();

                break;

            case 1458033723845:

                return make_shared<RunTimeCondition1458033723845>();

                break;

            case 1458033705136:

                return make_shared<TransitionCondition1458033705136>();

                break;

            case 1457173604049:

                return make_shared<TransitionCondition1457173604049>();

                break;

            case 1457173606067:

                return make_shared<TransitionCondition1457173606067>();

                break;

            case 1426696478377:

                return make_shared<TransitionCondition1426696478377>();

                break;

            case 1436268944209:

                return make_shared<TransitionCondition1436268944209>();

                break;

            case 1436268945305:

                return make_shared<TransitionCondition1436268945305>();

                break;

            case 1458033759784:

                return make_shared<RunTimeCondition1458033759784>();

                break;

            case 1435159171807:

                return make_shared<TransitionCondition1435159171807>();

                break;

            case 1435159188113:

                return make_shared<TransitionCondition1435159188113>();

                break;

            case 1436979720241:

                return make_shared<TransitionCondition1436979720241>();

                break;

            case 1436979742914:

                return make_shared<TransitionCondition1436979742914>();

                break;

            case 1457173948942:

                return make_shared<RunTimeCondition1457173948942>();

                break;

            case 1437903089358:

                return make_shared<TransitionCondition1437903089358>();

                break;

            case 1437903090726:

                return make_shared<TransitionCondition1437903090726>();

                break;

            case 1437903092576:

                return make_shared<TransitionCondition1437903092576>();

                break;

            case 1437903093659:

                return make_shared<TransitionCondition1437903093659>();

                break;

            case 1437903095031:

                return make_shared<TransitionCondition1437903095031>();

                break;

            case 1437903097184:

                return make_shared<TransitionCondition1437903097184>();

                break;

            case 1437903100138:

                return make_shared<TransitionCondition1437903100138>();

                break;

            case 1462361418213:

                return make_shared<RunTimeCondition1462361418213>();

                break;

            case 1462360958757:

                return make_shared<TransitionCondition1462360958757>();

                break;

            case 1462360959862:

                return make_shared<TransitionCondition1462360959862>();

                break;

            case 1462360961688:

                return make_shared<TransitionCondition1462360961688>();

                break;

            case 1462368132067:

                return make_shared<TransitionCondition1462368132067>();

                break;

            case 1462368203054:

                return make_shared<TransitionCondition1462368203054>();

                break;

            case 1462368267324:

                return make_shared<TransitionCondition1462368267324>();

                break;

            case 1462368269701:

                return make_shared<TransitionCondition1462368269701>();

                break;

            case 1462369227764:

                return make_shared<TransitionCondition1462369227764>();

                break;

            case 1434116267322:

                return make_shared<RunTimeCondition1434116267322>();

                break;

            case 1434050620829:

                return make_shared<TransitionCondition1434050620829>();

                break;

            case 1434050638814:

                return make_shared<TransitionCondition1434050638814>();

                break;

            case 1434050643664:

                return make_shared<TransitionCondition1434050643664>();

                break;

            case 1434050649090:

                return make_shared<TransitionCondition1434050649090>();

                break;

            case 1434050650300:

                return make_shared<TransitionCondition1434050650300>();

                break;

            case 1434050655008:

                return make_shared<TransitionCondition1434050655008>();

                break;

            case 1434050656151:

                return make_shared<TransitionCondition1434050656151>();

                break;

            case 1434050674307:

                return make_shared<TransitionCondition1434050674307>();

                break;

            case 1434050677358:

                return make_shared<TransitionCondition1434050677358>();

                break;

            case 1434050685640:

                return make_shared<TransitionCondition1434050685640>();

                break;

            case 1434050690800:

                return make_shared<TransitionCondition1434050690800>();

                break;

            case 1447255447830:

                return make_shared<TransitionCondition1447255447830>();

                break;

            case 1433939023616:

                return make_shared<TransitionCondition1433939023616>();

                break;

            case 1433939026572:

                return make_shared<TransitionCondition1433939026572>();

                break;

            case 1437390979726:

                return make_shared<TransitionCondition1437390979726>();

                break;

            case 1437390981105:

                return make_shared<TransitionCondition1437390981105>();

                break;

            case 1437483384075:

                return make_shared<TransitionCondition1437483384075>();

                break;

            case 1437483384840:

                return make_shared<TransitionCondition1437483384840>();

                break;

            case 1437483410098:

                return make_shared<TransitionCondition1437483410098>();

                break;

            case 1437483411068:

                return make_shared<TransitionCondition1437483411068>();

                break;

            case 1434115869504:

                return make_shared<TransitionCondition1434115869504>();

                break;

            case 1434115870439:

                return make_shared<TransitionCondition1434115870439>();

                break;

            case 1434115871872:

                return make_shared<TransitionCondition1434115871872>();

                break;

            case 1434115873056:

                return make_shared<TransitionCondition1434115873056>();

                break;

            case 1459361912141:

                return make_shared<TransitionCondition1459361912141>();

                break;

            case 1459361914252:

                return make_shared<TransitionCondition1459361914252>();

                break;

            case 1459361916700:

                return make_shared<TransitionCondition1459361916700>();

                break;

            case 1457434475372:

                return make_shared<TransitionCondition1457434475372>();

                break;

            case 1457434476549:

                return make_shared<TransitionCondition1457434476549>();

                break;

            case 1441107213887:

                return make_shared<TransitionCondition1441107213887>();

                break;

            case 1441107217606:

                return make_shared<TransitionCondition1441107217606>();

                break;

            case 1457015310255:

                return make_shared<TransitionCondition1457015310255>();

                break;

            case 1457015479684:

                return make_shared<TransitionCondition1457015479684>();

                break;

            case 1458555989600:

                return make_shared<TransitionCondition1458555989600>();

                break;

            case 1458555991152:

                return make_shared<TransitionCondition1458555991152>();

                break;

            case 1458555993122:

                return make_shared<TransitionCondition1458555993122>();

                break;

            case 1458555994351:

                return make_shared<TransitionCondition1458555994351>();

                break;

            case 1461574228077:

                return make_shared<RunTimeCondition1461574228077>();

                break;

            case 1461237657374:

                return make_shared<TransitionCondition1461237657374>();

                break;

            case 1461237677283:

                return make_shared<TransitionCondition1461237677283>();

                break;

            case 1461237854702:

                return make_shared<TransitionCondition1461237854702>();

                break;

            case 1461572770571:

                return make_shared<TransitionCondition1461572770571>();

                break;

            case 1461584286706:

                return make_shared<TransitionCondition1461584286706>();

                break;

            case 1461584441559:

                return make_shared<TransitionCondition1461584441559>();

                break;

            case 1449076203800:

                return make_shared<TransitionCondition1449076203800>();

                break;

            case 1449076205925:

                return make_shared<TransitionCondition1449076205925>();

                break;

            case 1434110243177:

                return make_shared<TransitionCondition1434110243177>();

                break;

            case 1434110244361:

                return make_shared<TransitionCondition1434110244361>();

                break;

            case 1434110245418:

                return make_shared<TransitionCondition1434110245418>();

                break;

            case 1434110246639:

                return make_shared<TransitionCondition1434110246639>();

                break;

            case 1437902448394:

                return make_shared<TransitionCondition1437902448394>();

                break;

            case 1437902449568:

                return make_shared<TransitionCondition1437902449568>();

                break;

            case 1457531039142:

                return make_shared<RunTimeCondition1457531039142>();

                break;

            case 1457531305067:

                return make_shared<TransitionCondition1457531305067>();

                break;

            case 1457531315717:

                return make_shared<TransitionCondition1457531315717>();

                break;

            case 1457531317223:

                return make_shared<TransitionCondition1457531317223>();

                break;

            case 1457531342108:

                return make_shared<TransitionCondition1457531342108>();

                break;

            case 1457531352472:

                return make_shared<TransitionCondition1457531352472>();

                break;

            case 1426696641527:

                return make_shared<TransitionCondition1426696641527>();

                break;

            case 1426696642635:

                return make_shared<TransitionCondition1426696642635>();

                break;

            case 1458562142910:

                return make_shared<TransitionCondition1458562142910>();

                break;

            case 1458562144595:

                return make_shared<TransitionCondition1458562144595>();

                break;

            case 1458562147436:

                return make_shared<TransitionCondition1458562147436>();

                break;

            case 1430324477939:

                return make_shared<TransitionCondition1430324477939>();

                break;

            case 1431012032315:

                return make_shared<TransitionCondition1431012032315>();

                break;

            case 1431528626141:

                return make_shared<TransitionCondition1431528626141>();

                break;

            case 1431528765720:

                return make_shared<TransitionCondition1431528765720>();

                break;

            case 1431528885384:

                return make_shared<TransitionCondition1431528885384>();

                break;

            case 1431528887593:

                return make_shared<TransitionCondition1431528887593>();

                break;

            case 1431528896437:

                return make_shared<TransitionCondition1431528896437>();

                break;

            case 1431528902161:

                return make_shared<TransitionCondition1431528902161>();

                break;

            case 1431529012684:

                return make_shared<TransitionCondition1431529012684>();

                break;

            case 1431529014647:

                return make_shared<TransitionCondition1431529014647>();

                break;

            case 1454506224420:

                return make_shared<TransitionCondition1454506224420>();

                break;

            case 1458125293553:

                return make_shared<TransitionCondition1458125293553>();

                break;

            case 1458125320118:

                return make_shared<TransitionCondition1458125320118>();

                break;

            case 1458135843050:

                return make_shared<TransitionCondition1458135843050>();

                break;

            case 1440675385644:

                return make_shared<TransitionCondition1440675385644>();

                break;

            case 1440772443709:

                return make_shared<TransitionCondition1440772443709>();

                break;

            case 1440772549250:

                return make_shared<TransitionCondition1440772549250>();

                break;

            case 1440772553737:

                return make_shared<TransitionCondition1440772553737>();

                break;

            case 1440772876913:

                return make_shared<TransitionCondition1440772876913>();

                break;

            case 1441811702176:

                return make_shared<TransitionCondition1441811702176>();

                break;

            case 1455537184881:

                return make_shared<TransitionCondition1455537184881>();

                break;

            case 1459365392367:

                return make_shared<TransitionCondition1459365392367>();

                break;

            case 1459365394125:

                return make_shared<TransitionCondition1459365394125>();

                break;

            case 1459365401307:

                return make_shared<TransitionCondition1459365401307>();

                break;

            case 1459365407637:

                return make_shared<TransitionCondition1459365407637>();

                break;

            case 1459365410684:

                return make_shared<TransitionCondition1459365410684>();

                break;

            case 1459365411722:

                return make_shared<TransitionCondition1459365411722>();

                break;

            case 1459365412597:

                return make_shared<TransitionCondition1459365412597>();

                break;

            case 1459365413923:

                return make_shared<TransitionCondition1459365413923>();

                break;

            case 1456841218640:

                return make_shared<TransitionCondition1456841218640>();

                break;

            case 1456841244750:

                return make_shared<TransitionCondition1456841244750>();

                break;

            case 1456841276132:

                return make_shared<TransitionCondition1456841276132>();

                break;

            case 1417620269159:

                return make_shared<TransitionCondition1417620269159>();

                break;

            case 1417620286821:

                return make_shared<TransitionCondition1417620286821>();

                break;

            case 1417620329181:

                return make_shared<TransitionCondition1417620329181>();

                break;

            case 1442919804925:

                return make_shared<TransitionCondition1442919804925>();

                break;

            case 1442921109582:

                return make_shared<TransitionCondition1442921109582>();

                break;

            case 1443003809289:

                return make_shared<TransitionCondition1443003809289>();

                break;

            case 1443003847207:

                return make_shared<TransitionCondition1443003847207>();

                break;

            case 1443522265673:

                return make_shared<TransitionCondition1443522265673>();

                break;

            case 1446733731395:

                return make_shared<TransitionCondition1446733731395>();

                break;

            case 1446733733995:

                return make_shared<TransitionCondition1446733733995>();

                break;

            case 1432134616532:

                return make_shared<TransitionCondition1432134616532>();

                break;

            case 1432134618673:

                return make_shared<TransitionCondition1432134618673>();

                break;

            case 1431526792158:

                return make_shared<TransitionCondition1431526792158>();

                break;

            case 1432744250382:

                return make_shared<TransitionCondition1432744250382>();

                break;

            case 1433337666610:

                return make_shared<TransitionCondition1433337666610>();

                break;

            case 1433338526794:

                return make_shared<TransitionCondition1433338526794>();

                break;

            case 1433338530469:

                return make_shared<TransitionCondition1433338530469>();

                break;

            case 1458131561310:

                return make_shared<TransitionCondition1458131561310>();

                break;

            case 1430925918456:

                return make_shared<TransitionCondition1430925918456>();

                break;

            case 1430925919738:

                return make_shared<TransitionCondition1430925919738>();

                break;

            case 1430925921267:

                return make_shared<TransitionCondition1430925921267>();

                break;

            case 1430925922740:

                return make_shared<TransitionCondition1430925922740>();

                break;

            case 1430925924055:

                return make_shared<TransitionCondition1430925924055>();

                break;

            case 1430925925549:

                return make_shared<TransitionCondition1430925925549>();

                break;

            case 1430925962659:

                return make_shared<TransitionCondition1430925962659>();

                break;

            case 1430925965501:

                return make_shared<TransitionCondition1430925965501>();

                break;

            case 1430925967520:

                return make_shared<TransitionCondition1430925967520>();

                break;

            case 1430925970967:

                return make_shared<TransitionCondition1430925970967>();

                break;

            case 1430925972838:

                return make_shared<TransitionCondition1430925972838>();

                break;

            case 1430925975558:

                return make_shared<TransitionCondition1430925975558>();

                break;

            case 1458555207377:

                return make_shared<TransitionCondition1458555207377>();

                break;

            case 1458555210443:

                return make_shared<TransitionCondition1458555210443>();

                break;

            case 1458555218469:

                return make_shared<TransitionCondition1458555218469>();

                break;

            case 1458555220837:

                return make_shared<TransitionCondition1458555220837>();

                break;

            case 1458555223252:

                return make_shared<TransitionCondition1458555223252>();

                break;

            case 1458555791025:

                return make_shared<TransitionCondition1458555791025>();

                break;

            case 1458555821886:

                return make_shared<TransitionCondition1458555821886>();

                break;

            case 1458555856023:

                return make_shared<TransitionCondition1458555856023>();

                break;

            case 1458555881015:

                return make_shared<TransitionCondition1458555881015>();

                break;

            case 1458555898277:

                return make_shared<TransitionCondition1458555898277>();

                break;

            case 1455127612198:

                return make_shared<TransitionCondition1455127612198>();

                break;

            case 1455127641457:

                return make_shared<TransitionCondition1455127641457>();

                break;

            default:
                cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << endl;
                throw new exception();
                break;
        }
    }
}
