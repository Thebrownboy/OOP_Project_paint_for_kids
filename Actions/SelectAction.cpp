#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Select a Figure ");
	Input* pIn = pManager->GetInput();

	
	pIn->GetPointClicked(Select.x, Select.y);


}

//Execute the action
void SelectAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	if(pManager->GetSelected())
		pManager->GetSelected()->SetSelected(false);
	if(pManager->GetFigure(Select.x,Select.y))
	{
		pManager->GetFigure(Select.x,Select.y)->SetSelected(true);
		pManager->GetFigure(Select.x,Select.y)->PrintInfo(pOut);
	}
	
}



SelectAction::~SelectAction(void)
{	
}
