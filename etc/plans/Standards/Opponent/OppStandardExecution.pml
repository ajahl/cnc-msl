<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1457015277573" name="OppStandardExecution" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Standards/Opponent" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1457015277575" name="Position" comment="" entryPoint="1457015277576">
    <plans xsi:type="alica:PlanType">OppStandardPositionType.pty#1457015361187</plans>
    <outTransitions>#1457015308829</outTransitions>
  </states>
  <states id="1457015292860" name="WatchBall" comment="">
    <plans xsi:type="alica:PlanType">OppStandardWatchBallType.pty#1457015489608</plans>
    <plans xsi:type="alica:BehaviourConfiguration">TeamWatchBall.beh#1457015565562</plans>
    <inTransitions>#1457015308829</inTransitions>
    <outTransitions>#1457015478636</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1457015318562" name="NewSuccessState" comment="">
    <inTransitions>#1457015478636</inTransitions>
  </states>
  <transitions id="1457015308829" name="MISSING_NAME" comment="Situation==Start" msg="">
    <preCondition id="1457015310255" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1457015277575</inState>
    <outState>#1457015292860</outState>
  </transitions>
  <transitions id="1457015478636" name="MISSING_NAME" comment="WatchBallMessage || 10Secs since start" msg="">
    <preCondition id="1457015479684" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1457015292860</inState>
    <outState>#1457015318562</outState>
  </transitions>
  <entryPoints id="1457015277576" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1225112227903</task>
    <state>#1457015277575</state>
  </entryPoints>
</alica:Plan>
