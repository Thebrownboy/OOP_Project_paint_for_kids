#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}

void DeleteAction:: ReadActionParameters()
{	
	
}
void DeleteAction:: Execute() 
{
	Output*pOut	=pManager->GetOutput();	
	// check whether a there is a selected shape or no
	if(!pManager->GetSelected())
	{
		pOut->PrintMessage("No shape was selected please select a shape then try again, Choose another icon from the tool bar");
		return;
	}

	pManager->DeleteFigure();
	{
		pOut->PrintMessage("A figure was deleted successfully, Choose another icon from the tool bar");
	}
	
}


DeleteAction::~DeleteAction(void)
{
}

