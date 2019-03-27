#pragma once
#include "..\Actions\Action.h"
#include "..\Figures\CFigure.h"

class PickColorAction:public Action
{
	Point HIDE;

public:
	PickColorAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	// function to make the picked figure's pointer point to null so that it will not drawn 
	void HideFigure(CFigure** list, CFigure* ShapePtr, int size);
	~PickColorAction(void);
};

