#pragma once
#include "..\Actions\Action.h"

class DeleteAction:public Action
{
	Point Delete;
public:
	DeleteAction(ApplicationManager *pApp);	
	virtual void ReadActionParameters();
	virtual void Execute() ;
	//to check whether the point was clicked in the drawing area or not 
	~DeleteAction(void);
};
