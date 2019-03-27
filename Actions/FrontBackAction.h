#pragma once
#include"..\Actions\Action.h"

//enum  back or front (postion of the figures)
enum FB
	{
		Front,
		Back
	};

class FrontBackAction: public Action
{
public:
	FrontBackAction(ApplicationManager *pApp);	
	void ReadActionParameters();
	void Execute() ;
	~FrontBackAction(void);
};

