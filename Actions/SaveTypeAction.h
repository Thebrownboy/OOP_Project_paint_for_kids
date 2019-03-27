#pragma once
#include "../Actions/Action.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include <fstream>
class SavebytypeAction :
	public Action
{
	ActionType Figchosen;
	string filename;
	ofstream savefile;
	bool iconselected;
public:
	SavebytypeAction(ApplicationManager*);
	void Execute();
	void ReadActionParameters();
	~SavebytypeAction();
};

