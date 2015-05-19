/*
 * PathEvaluator.h
 *
 *  Created on: May 14, 2015
 *      Author: Stefan Jakob
 */

#ifndef CNC_MSL_MSL_WORLDMODEL_INCLUDE_PATHPLANNER_EVALUATOR_PATHEVALUATOR_H_
#define CNC_MSL_MSL_WORLDMODEL_INCLUDE_PATHPLANNER_EVALUATOR_PATHEVALUATOR_H_

#include <vector>
#include <memory>
#include "container/CNPoint2D.h"
#include "pathplanner/PathPlanner.h"
#include <SystemConfig.h>
namespace msl
{

	class PathEvaluator
	{
	public:
		PathEvaluator(PathPlanner* planner);
		virtual ~PathEvaluator();
		virtual double eval(double costsSoFar, shared_ptr<VoronoiNet> voronoi, shared_ptr<vector<shared_ptr<CNPoint2D>>> path,
							CNPoint2D startPos, CNPoint2D goal, shared_ptr<SearchNode> currentNode, shared_ptr<SearchNode> nextNode) = 0;
	protected:
		double clearSpaceWeight;
		PathPlanner* planner;
		static double distance(CNPoint2D first, CNPoint2D second);
		static double square(double a);
		SystemConfig* sc;

	};



} /* namespace msl */

#endif /* CNC_MSL_MSL_WORLDMODEL_INCLUDE_PATHPLANNER_EVALUATOR_PATHEVALUATOR_H_ */
