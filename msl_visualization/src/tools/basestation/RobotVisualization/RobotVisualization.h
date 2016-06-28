/*
 * RobotVisualization.h
 *
 *  Created on: Feb 11, 2015
 *      Author: Stefan Jakob
 */

#ifndef CNC_MSL_MSL_VISUALIZATION_SRC_TOOLS_BASESTATION_ROBOTVISUALIZATION_H_
#define CNC_MSL_MSL_VISUALIZATION_SRC_TOOLS_BASESTATION_ROBOTVISUALIZATION_H_

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkLineSource.h>
#include <string>
#include <memory>

class RobotInfo;
class FieldWidget3D;
class Line;

class RobotVisualization {
public:
	RobotVisualization(RobotInfo* robot, FieldWidget3D* field);
	virtual ~RobotVisualization();
	vtkSmartPointer<vtkActor> getBottom();
	void setBottom(vtkSmartPointer<vtkActor> bottom);
	vtkSmartPointer<vtkActor> getTop();
	void setTop(vtkSmartPointer<vtkActor> top);
	void setNameActor(vtkSmartPointer<vtkActor> nameActor);
	vtkSmartPointer<vtkActor> getNameActor();
	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string name);
	int getSenderId();
	void setSenderId(int senderId);
	vtkActor* getBall();
	void setBall(vtkActor* ball);
	vtkSmartPointer<vtkLineSource> getBallVelocity();
	void setBallVelocity(vtkSmartPointer<vtkLineSource> ballVelocity);
	vtkSmartPointer<vtkActor> getBallVelocityActor();
	void setBallVelocityActor(vtkSmartPointer<vtkActor> ballVelocityActor);
	vtkSmartPointer<vtkActor> getSharedBall();
	void setSharedBall(vtkSmartPointer<vtkActor> sharedBall);

	void remove(vtkRenderer *renderer);
	void init(vtkRenderer *renderer, int id);
	void updatePosition(vtkRenderer *renderer);
	void updateBall(vtkRenderer *renderer);
	void updateSharedBall(vtkRenderer *renderer);
	void updateOpponents(vtkRenderer *renderer);

	void updatePathPlannerDebug(vtkRenderer *renderer, bool show);
	void updateCorridorDebug(vtkRenderer *renderer, bool show);
	void updateVoronoiNetDebug(vtkRenderer *renderer, bool showVoronoi,
			bool showSidePoints);
	void updateDebugPoints(vtkRenderer *renderer, bool showDebugPoints);
	void updatePassMsg(vtkRenderer *renderer, bool showPassing);

private:
	void drawOpponent(vtkRenderer *renderer, double x, double y, double z);
	void drawOpponentTop(vtkRenderer *renderer, double x, double y, double z);
	std::array<double, 3>& getColor();
	int getDashedPattern();

private:
	RobotInfo* robot;
	FieldWidget3D* field;
	bool visible;

	std::string name = "";
	int id = 0;
	int senderId = 0;
	vtkSmartPointer<vtkActor> top = nullptr;
	vtkSmartPointer<vtkActor> bottom = nullptr;
	vtkSmartPointer<vtkActor> nameActor = nullptr;
	vtkSmartPointer<vtkActor> ball = nullptr;
	vtkSmartPointer<vtkLineSource> ballVelocity = nullptr;
	vtkSmartPointer<vtkActor> ballVelocityActor = nullptr;
	vtkSmartPointer<vtkActor> sharedBall = nullptr;
	vtkSmartPointer<vtkLineSource> pass = nullptr;
	vtkSmartPointer<vtkActor> passActor = nullptr;
	vtkSmartPointer<vtkActor> passPointActor = nullptr;
	std::vector<vtkSmartPointer<vtkActor>> obstaclesBottom;

	std::vector<vtkSmartPointer<vtkActor>> obstaclesTop;

	std::vector<vtkSmartPointer<vtkActor>> pathLines;
	std::vector<std::shared_ptr<Line>> netLines;
	std::shared_ptr<Line> corridorLine1;
	std::shared_ptr<Line> corridorLine2;
	std::shared_ptr<Line> corridorLine3;
	std::shared_ptr<Line> corridorLine4;
	std::vector<vtkSmartPointer<vtkActor>> sidePoints;
	std::vector<vtkSmartPointer<vtkActor>> debugPoints;
};

#endif /* CNC_MSL_MSL_VISUALIZATION_SRC_TOOLS_BASESTATION_ROBOTVISUALIZATION_H_ */
