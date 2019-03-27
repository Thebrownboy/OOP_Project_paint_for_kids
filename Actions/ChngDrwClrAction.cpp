#include "ChngDrwClrAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ChngDrwClrAction::ChngDrwClrAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChngDrwClrAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input  Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar() ;
	pOut->CreatecolorToolBar() ;
	pOut->PrintMessage("Choose the desired color, if want to skip changing the color press any where on the drawing area.");
	ColorChosen = pIn->GetUserAction();
	pOut->ClearStatusBar();

}

void ChngDrwClrAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* Change = pManager->GetSelected();
	if(!Change)
	{
		pOut->PrintMessage("No shape was selected, Please select an item first.");
		return;
	}

	ReadActionParameters();
	switch (ColorChosen)
	{
	case CRED:
		UI.DrawColor = RED;
		Change->ChngDrawClr(RED);
		break;
	case CBLACK:
		UI.DrawColor = BLACK;
		Change->ChngDrawClr(BLACK);
		break;
	case CBLUE:
		UI.DrawColor = BLUE;
		Change->ChngDrawClr(BLUE);
		break;
	case CWHITE:
		UI.DrawColor = WHITE;
		Change->ChngDrawClr(WHITE);
		break;
	case CGREEN:
		UI.DrawColor = GREEN;
		Change->ChngDrawClr(GREEN);
		break;
	default:
		break;
	}
	pOut->PrintMessage("Click any where on the drawing area to unselect this shape.");
	pOut->CreateDrawToolBar();
	pManager->UnSelect(pManager->GetSelected());


}

