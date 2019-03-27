#pragma once

#include "Action.h"
class AddRhombusAction:public Action
{
private:
	Point P1; // Rhombus center
	GfxInfo RhomGfxInfo;
public:
	public:
	AddRhombusAction(ApplicationManager* pApp);

	//to check whether the point was clicked in the drawing area or not
	bool PointCheck(Point p);  

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};
