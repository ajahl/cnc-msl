<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1472647610805" name="TestKickMaster" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/TestPlans/TestKick" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1472647610806" name="Idle" comment="" entryPoint="1472647610808">
    <inTransitions>#1472648640369</inTransitions>
    <outTransitions>#1472648638637</outTransitions>
  </states>
  <states id="1472648628993" name="Running" comment="">
    <plans xsi:type="alica:Plan">TestKickRunning.pml#1472647818767</plans>
    <inTransitions>#1472648638637</inTransitions>
    <outTransitions>#1472648640369</outTransitions>
  </states>
  <transitions id="1472648638637" name="MISSING_NAME" comment="Idle2Run" msg="">
    <preCondition id="1472648640273" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1472647610806</inState>
    <outState>#1472648628993</outState>
  </transitions>
  <transitions id="1472648640369" name="MISSING_NAME" comment="Run2Idle" msg="">
    <preCondition id="1472648641417" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1472648628993</inState>
    <outState>#1472647610806</outState>
  </transitions>
  <entryPoints id="1472647610808" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1225112227903</task>
    <state>#1472647610806</state>
  </entryPoints>
</alica:Plan>
