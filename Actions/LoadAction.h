#pragma once
#include <string>
#include <fstream>
#include "action.h"
#include "../ApplicationManager.h"
#include <iostream>
#include "../Figures/CEllipse.h"
#include "../Figures/CRectangle.h"
#include"../Figures/Cline.h"
#include"../Figures/CRhombus.h"
#include "../Figures/CTriangle.h"

using namespace std;

class LoadAction :
	public Action
{
	string filename;
	ifstream loadfile;
public:
	LoadAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~LoadAction(void);
};

