
#pragma once
using namespace std;
#include "Action.h"
#include <fstream>
#include <string>
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class SaveAction :
	public Action
{

	string filename;
	ofstream savefile;
public:
	SaveAction(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
	void savefigure(CFigure*);
	~SaveAction(void);
};