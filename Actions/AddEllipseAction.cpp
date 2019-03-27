#pragma once

#include "AddEllipseAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp):Action(pApp)
{}


bool AddEllipseAction::PointCheck(Point p) 
{
	if((p.y-51 >= UI.ToolBarHeight && p.y+51 < UI.height - UI.StatusBarHeight) && (p.x-110 >= 0  && p.x+110< UI.width))
		return true;
	return false;

}

void AddEllipseAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if(UI.VoiceMode==SoundON)
		PlaySound(TEXT("eli.wav"),NULL,SND_ASYNC);
	pOut->PrintMessage("New Elipse: Click at the Center");
	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if(UI.FillColor == OLDLACE)
		EllpsGfxInfo.isFilled = false;	//default is not filled
	else 
		EllpsGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	EllpsGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllpsGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute() 
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	
	if(!PointCheck(P1))
	{
		pOut->PrintMessage("Error you can't draw with this point because the shape will get out of drawing area boundaries, Choose another icon from the toolbar.");
		return;
	}

	//Create an ellipse with the parameters read from the user
	CEllipse *E=new CEllipse(P1, EllpsGfxInfo, pManager->GetFigureCount() + 1);
	//Add the triangle to the list of figures
	pManager->AddFigure(E);
}
