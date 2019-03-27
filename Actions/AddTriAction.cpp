#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager * pApp):Action(pApp)
{
	//this initialization is an indicator that the points weren't taken from the user yet
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;
}


void AddTriangleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//to check if the first vertex is zero(first time to call this fuction)	the click should be put in P1
	if(!P1.x && !P1.y)
		pIn->GetPointClicked(P1.x, P1.y);

	// prompt the user for the second vertex if the first one is already entered
	else if(!P2.x && !P2.y)
		pIn->GetPointClicked(P2.x, P2.y);

	// prompt the user for the third vertex if the first and second one are already entered
	else
		pIn->GetPointClicked(P3.x, P3.y);
	if(UI.FillColor == OLDLACE)
		TriGfxInfo.isFilled = false;	//default is not filled
	else 
		TriGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute() 
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	if(UI.VoiceMode==SoundON)
		PlaySound(TEXT("tri.wav"),NULL,SND_ASYNC);

	pOut->PrintMessage("New Triangle: Click at the first vertex");
	//Read 1st vertex and store in point P1
	ReadActionParameters();
	//validate that the point isn't out of drawing area bounds
	if (!Pointcheck(P1))
	{
		pOut->PrintMessage("Adding Triangle has terminated, Choose another icon from the tool bar");
		return;
	}

	pOut->PrintMessage("New Triangle: Click at the second vertex");
	//Read 2nd vertex and store in point P2
	ReadActionParameters();
	//validate that the point isn't out of drawing area bounds
	if (!Pointcheck(P2))
	{
		pOut->PrintMessage("Adding Triangle has terminated, Choose another icon from the tool bar");
		return;
	}

	pOut->PrintMessage("New Triangle: Click at the third vertex");
	//Read 3rd vertex and store in point P3
	ReadActionParameters();
	//validate that the point isn't out of drawing area bounds
	if (!Pointcheck(P3))
	{
		pOut->PrintMessage("Adding Triangle has terminated, Choose another icon from the tool bar");
		return;
	}

	
	//Create a triangle with the parameters read from the user
	CTriangle *T=new CTriangle(P1, P2, P3, TriGfxInfo, pManager->GetFigureCount() + 1);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}