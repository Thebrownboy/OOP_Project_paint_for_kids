#pragma once
#include "../Actions\Action.h"
class SwitchToDrawAction:public Action
{
public:
	SwitchToDrawAction(ApplicationManager *pApp);	
	//Add rectangle to the ApplicationManager
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~SwitchToDrawAction(void);
};

