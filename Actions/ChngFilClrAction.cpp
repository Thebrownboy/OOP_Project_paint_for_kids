#include "ChngFilClrAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ChngFilClrAction::ChngFilClrAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChngFilClrAction::ReadActionParameters() 
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

void ChngFilClrAction::Execute()
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
		UI.FillColor = RED;
		Change->ChngFillClr(RED);
		break;
	case CBLACK:
		UI.FillColor = BLACK;
		Change->ChngFillClr(BLACK);
		break;
	case CBLUE:
		UI.FillColor = BLUE;
		Change->ChngFillClr(BLUE);
		break;
	case CWHITE:
		UI.FillColor = WHITE;
		Change->ChngFillClr(WHITE);
		break;
	case CGREEN:
		UI.FillColor = GREEN;
		Change->ChngFillClr(GREEN);
		break;
	default:
		break;
	}
	pOut->PrintMessage("Click any where to unselect this shape.");
	pOut->CreateDrawToolBar();
	pManager->UnSelect(pManager->GetSelected());


}

