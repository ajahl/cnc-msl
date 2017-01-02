/*
 * Base.cpp
 *
 *  Created on: 22.10.2014
 *      Author: Andreas Witsch
 */

#include <iostream>

#include <thread>
#include <chrono>
#include "Base.h"
#include "SigFault.h"
#include "SolverType.h"
#include "CGSolver.h"
#include "engine/IAlicaClock.h"
#include "clock/AlicaSystemClock.h"
#include "communication/AlicaDummyCommunication.h"

using namespace std;
using namespace msl;

namespace msl
{

	Base::Base(string roleSetName, string masterPlanName, string roleSetDir, bool sim)
	{
		ae = new alica::AlicaEngine();
		bc = new alica::BehaviourCreator();
		cc = new alica::ConditionCreator();
		uc = new alica::UtilityFunctionCreator();
		crc = new alica::ConstraintCreator();
		ae->setIAlicaClock(new alica_dummy_proxy::AlicaSystemClock());
		ae->setCommunicator(new alica_dummy_proxy::AlicaDummyCommunication(ae));
		ae->addSolver(SolverType::GRADIENTSOLVER,new alica::reasoner::CGSolver(ae));
		ae->init(bc, cc, uc, crc, roleSetName, masterPlanName, roleSetDir, false);
	}

	void Base::start()
	{
		ae->start();
	}

	Base::~Base()
	{
		ae->shutdown();
		delete ae->getIAlicaClock();
		delete ae->getCommunicator();
		delete ae;
		delete cc;
		delete bc;
		delete uc;
		delete crc;
	}

} /* namespace msl */

void printUsage()
{
	cout << "Usage: ./msl_base -m \"Masterplan\" [-rd \"RoleSetDirectory\"] [-rset \"RoleSet\"] [-sim]" << endl;
}

string getNodeName(string postFix)
{
	string hostName = supplementary::SystemConfig::getInstance()->getHostname();
	replace(hostName.begin(), hostName.end(), '-', '_');

	return hostName + "_" + postFix;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printUsage();
		return 0;
	}
	//This makes segfaults to exceptions
	segfaultdebug::init_segfault_exceptions();
	cout << "Parsing command line parameters:" << endl;
	string masterplan = "";
	string rolesetdir = ".";
	string roleset = "";
	bool sim = false;
	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == "-m" || string(argv[i]) == "-masterplan")
		{
			masterplan = argv[i + 1];
			i++;
		}

		if (string(argv[i]) == "-rd" || string(argv[i]) == "-rolesetdir")
		{
			rolesetdir = argv[i + 1];
			i++;
		}
		if (string(argv[i]) == "-r" || string(argv[i]) == "-roleset")
		{
			roleset = argv[i + 1];
			i++;
		}
		if (string(argv[i]) == "-sim")
		{
			sim = true;
		}
	}
	if (masterplan.size() == 0 || rolesetdir.size() == 0)
	{
		printUsage();
		return 0;
	}
	cout << "\tMasterplan is:       \"" << masterplan << "\"" << endl;
	cout << "\tRolset Directory is: \"" << rolesetdir << "\"" << endl;
	cout << "\tRolset is:           \"" << (roleset.empty() ? "Default" : roleset) << "\"" << endl;

	cout << "\nConstructing Base ..." << endl;
	Base* base = new Base(roleset, masterplan, rolesetdir, sim);

	cout << "\nStarting Base ..." << endl;
	base->start();

	// STRG c abfangen
	while (true)
	{
		std::chrono::milliseconds dura(500);
		std::this_thread::sleep_for(dura);
	}
	delete base;

	return 0;
}
