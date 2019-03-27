#pragma once
#include "..\Actions\Action.h"

class PickTypeAction:public Action
{
	Point HIDE;

public:
	PickTypeAction(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PickTypeAction(void);
};

