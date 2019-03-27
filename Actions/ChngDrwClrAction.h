#pragma once
#include "..\Actions\Action.h"
class ChngDrwClrAction: public Action
{
	Point ChangeColor;
	int ColorChosen;
public:
	ChngDrwClrAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChngDrwClrAction  ();



};
