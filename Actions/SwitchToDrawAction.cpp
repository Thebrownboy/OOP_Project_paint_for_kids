#include "SwitchToDrawAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager *pApp):Action(pApp)
{

}

void SwitchToDrawAction:: ReadActionParameters()
{
	Output*pOut	=pManager->GetOutput();	
	pOut->PrintMessage("Action: Switch to Draw Mode ");
}

void SwitchToDrawAction:: Execute()
{
	ReadActionParameters();
	Output*pOut	=pManager->GetOutput();	
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}


SwitchToDrawAction::~SwitchToDrawAction(void)
{
}
