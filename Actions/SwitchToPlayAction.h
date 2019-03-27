#pragma once
#include "..\Actions\Action.h"

class SwitchToPlayAction:public Action
{
public:
	SwitchToPlayAction(ApplicationManager *pApp);	
	//Add rectangle to the ApplicationManager
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~SwitchToPlayAction(void);
};

