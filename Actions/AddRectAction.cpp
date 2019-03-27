#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{
	//this initialization is an indicator that the points weren't taken from the user yet
	P1.x = 0;
	P1.y = 0;
}


void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input/Outpur Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//to check if the first corner is zero(first time to call this fuction)	the click should be put in P1
	if(!P1.x && !P1.y)
		pIn->GetPointClicked(P1.x, P1.y);

	// prompt the user for the second corner if the first one is already entered
	else
		pIn->GetPointClicked(P2.x, P2.y);
	if(UI.FillColor == OLDLACE)
		RectGfxInfo.isFilled = false;	//default is not filled
	else 
		RectGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	
	if(UI.VoiceMode==SoundON)
		PlaySound(TEXT("rect.wav"),NULL,SND_ASYNC);

	pOut->PrintMessage("New Rectangle: Click at the first corner");
	//Read 1st corner and store in point P1
	ReadActionParameters();
	if (!Pointcheck(P1))
	{
		pOut->PrintMessage("Adding Rectangle has terminated, Choose another icon from the tool bar");
		return;
	}
	
	
	pOut->PrintMessage("New Rectangle: Click at the second corner");
	//Read 2nd corner and store in point P2
	ReadActionParameters();
	if (!Pointcheck(P2))
	{
		pOut->PrintMessage("Adding Rectangle has terminated, Choose another icon from the tool bar");
		return;
	}

	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo, pManager->GetFigureCount() + 1);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}


