#pragma once
#include"Action.h"

class CutAction:public Action
{
	//I will make a object of a color to the colot of the cutted figure because if the user cut anthor figure I will make the 
	//last cutted one 
	
public:
	CutAction(ApplicationManager *);
	~CutAction(void);
	void Execute() ;
	void ReadActionParameters() ;
	
};

