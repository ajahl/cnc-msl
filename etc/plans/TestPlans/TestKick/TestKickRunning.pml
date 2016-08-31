<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1472647818767" name="TestKickRunning" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/TestPlans/TestKick" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1472647848895" name="DriveToA" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">TestDriveTo.beh#1472648841944</plans>
    <plans xsi:type="alica:BehaviourConfiguration">../../Dribble/DribbleControl.beh#1449742099555</plans>
    <inTransitions>#1472648740577</inTransitions>
    <outTransitions>#1472648741815</outTransitions>
  </states>
  <states id="1472648701821" name="DriveToB" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">TestDriveTo.beh#1472648852426</plans>
    <plans xsi:type="alica:BehaviourConfiguration">../../Dribble/DribbleControl.beh#1449742099555</plans>
    <inTransitions>#1472648741815</inTransitions>
    <outTransitions>#1472648742732</outTransitions>
  </states>
  <states id="1472648712038" name="GetBall" comment="" entryPoint="1472647848896">
    <plans xsi:type="alica:BehaviourConfiguration">TestGetBall.beh#1472647982006</plans>
    <outTransitions>#1472648740577</outTransitions>
  </states>
  <states id="1472648717255" name="Kick" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">TestKick.beh#1472648373489</plans>
    <inTransitions>#1472648742732</inTransitions>
    <outTransitions>#1472648743629</outTransitions>
  </states>
  <states id="1472648733912" name="Idle" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">TestIdle.beh#1472648954665</plans>
    <inTransitions>#1472648743629</inTransitions>
  </states>
  <transitions id="1472648740577" name="MISSING_NAME" comment="GetBall2DriveToA" msg="">
    <preCondition id="1472648741726" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1472648712038</inState>
    <outState>#1472647848895</outState>
  </transitions>
  <transitions id="1472648741815" name="MISSING_NAME" comment="DriveToA2DriveToB" msg="">
    <preCondition id="1472648742636" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1472647848895</inState>
    <outState>#1472648701821</outState>
  </transitions>
  <transitions id="1472648742732" name="MISSING_NAME" comment="DriveToB2Kick" msg="">
    <preCondition id="1472648743524" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1472648701821</inState>
    <outState>#1472648717255</outState>
  </transitions>
  <transitions id="1472648743629" name="MISSING_NAME" comment="Kick2Idle" msg="">
    <preCondition id="1472648744508" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1472648717255</inState>
    <outState>#1472648733912</outState>
  </transitions>
  <entryPoints id="1472647848896" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1225112227903</task>
    <state>#1472648712038</state>
  </entryPoints>
</alica:Plan>
