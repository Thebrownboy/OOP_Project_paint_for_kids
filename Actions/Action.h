#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\GUI\UI_Info.h"	//had to include this to access the height of the tool bar to use it with fuc check which is used by merely all actions

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;


	// to check whether the point was clicked in the drawing area or not
	virtual bool Pointcheck(Point p)
	{
		if(p.y >= UI.ToolBarHeight && p.y < UI.height - UI.StatusBarHeight)
			return true;
		return false;
	}

};

#endif