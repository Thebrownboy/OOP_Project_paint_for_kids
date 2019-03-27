#include "SwitchToPlayAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager *pApp):Action(pApp)
{}

void SwitchToPlayAction::ReadActionParameters()
{
	Output*pOut	=pManager->GetOutput();	
	pOut->PrintMessage("Action: Switch to Play Mode ");
}



void SwitchToPlayAction::Execute()
{
	ReadActionParameters();
	Output*pOut	=pManager->GetOutput();	
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
	pOut->ClearDrawArea();
}

SwitchToPlayAction::~SwitchToPlayAction(void)
{
}
