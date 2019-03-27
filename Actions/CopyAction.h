#pragma once
#include"Action.h"

class CopyAction :public Action
{
public:
	CopyAction(ApplicationManager *);
	~CopyAction(void);
	void Execute() ;
	void ReadActionParameters() ;
};
