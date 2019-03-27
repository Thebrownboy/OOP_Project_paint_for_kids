#pragma once
#include "..\Actions\Action.h"

class SelectAction:public Action
{Point Select;
public:
	SelectAction(ApplicationManager * );
	virtual void ReadActionParameters();
	//Select to the ApplicationManager
	virtual void Execute() ;
	~SelectAction(void);
};

