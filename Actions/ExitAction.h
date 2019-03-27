#pragma once
#include "..\Actions\Action.h"

class ExitAction:public Action
{
public:
	ExitAction(ApplicationManager *pApp);	
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~ExitAction(void);
};

