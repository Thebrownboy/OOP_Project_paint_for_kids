#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "Figures\Cline.h"
#include "Figures\CRhombus.h"
#include "Figures\CEllipse.h"
#include "Figures\CTriangle.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <Windows.h>
#include <MMsystem.h>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFigure();				   // deletes the selected figure
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
	int GetFigureCount()const;		 // get the actual number of figures
	CFigure ** GetFigures();	  // get a copy of the figure list
	CFigure* GetSelected();
	void UnSelect(CFigure*);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SetClipboard(CFigure*) ;//made by abdalla 
	CFigure* GetClipboard();//made by abdalla 
	CFigure*GetFigure(int index );//made by abdalla 
	void removeafigure(CFigure * );//made by abdalla 
	void Savefigures(ofstream& file);
	void ApplicationManager::Savefiguresbytype(ofstream& file, ActionType fig);
};

#endif