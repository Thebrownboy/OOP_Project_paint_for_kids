#pragma once
#include "..\Actions\Action.h"
class ChngFilClrAction: public Action
{
	Point ChangeColor;
	int ColorChosen;
public:
	ChngFilClrAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChngFilClrAction  ();



};
