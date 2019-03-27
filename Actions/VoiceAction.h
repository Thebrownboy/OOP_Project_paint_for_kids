#pragma once
#include"..\Actions\Action.h"
class VoiceAction:public Action
{
public:
	VoiceAction(ApplicationManager *pApp);	
	//Add rectangle to the ApplicationManager
	void ReadActionParameters();
	void Execute() ;
	~VoiceAction(void);
};

