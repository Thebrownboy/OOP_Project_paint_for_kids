#include "AddRhomAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp):Action(pApp)
{}
void AddRhombusAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at the Center");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if(UI.FillColor == OLDLACE)
		RhomGfxInfo.isFilled = false;	//default is not filled
	else
		RhomGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

bool AddRhombusAction::PointCheck(Point p) 
{
	if((p.y-51 >= UI.ToolBarHeight && p.y+51 < UI.height - UI.StatusBarHeight) && (p.x-110 >= 0  && p.x+110< UI.width))
		return true;
	return false;

}

//Execute the action
void AddRhombusAction::Execute() 
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first

	if(UI.VoiceMode==SoundON)
		PlaySound(TEXT("rohm.wav"),NULL,SND_ASYNC);

	ReadActionParameters();
	
	if(!PointCheck(P1))
	{
		pOut->PrintMessage("Error you can't draw with this point because the shape will get out of drawing area boundaries, Choose another icon from the toolbar.");
		return;
	}
	//Create a Rhombus with the parameters read from the user
	CRhombus *R=new CRhombus(P1, RhomGfxInfo, pManager->GetFigureCount() + 1);

	//Add the Rhombus to the list of figures
	pManager->AddFigure(R);
}

