#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{
	//this initialization is an indicator that the points weren't taken from the user yet
	P1.x = 0;
	P1.y = 0;
}



void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input/Outpur Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	

	//to check if the starting point is zero (first time to call this fuction)	the click should be put in P1
	if(!P1.x && !P1.y)
		pIn->GetPointClicked(P1.x, P1.y);

	// prompt the user for the second corner if the first one is already entered
	else
		pIn->GetPointClicked(P2.x, P2.y);
	if(UI.FillColor == OLDLACE)
		LineGfxInfo.isFilled = false;	//default is not filled
	else
		LineGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();


}

//Execute the action
void AddLineAction::Execute() 
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	if(UI.VoiceMode==SoundON)
		PlaySound(TEXT("line.wav"),NULL,SND_ASYNC);
	pOut->PrintMessage("New Line: Click at the starting point");
	//Read starting point and store in point P1
	ReadActionParameters();
	if (!Pointcheck(P1))
	{
		pOut->PrintMessage("Adding Line has terminated, Choose another icon from the tool bar");
		return;
	}
	
	
	pOut->PrintMessage("New Line: Click at the end point");
	//Read 2nd corner and store in point P2
	ReadActionParameters();
	if (!Pointcheck(P2))
	{
		pOut->PrintMessage("Adding Line has terminated, Choose another icon from the tool bar");
		return;
	}

	//Create a rectangle with the parameters read from the user
	CLine *L=new CLine(P1, P2, LineGfxInfo, pManager->GetFigureCount() + 1);

	//Add the rectangle to the list of figures
	pManager->AddFigure(L);
}