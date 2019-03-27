#pragma once
#include"Action.h"

class PasteAction:public Action
{
	Point p1 ;
public:
	PasteAction(ApplicationManager * );
	~PasteAction(void);
	void Execute() ;
	void ReadActionParameters() ;
	// to check whether the point was clicked in the drawing area or not
	bool Pointcheck(Point p);
	bool RhoElliPointCheck(Point p);
};