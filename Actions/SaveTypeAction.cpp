#include "SaveTypeAction.h"



SavebytypeAction::SavebytypeAction(ApplicationManager* pApp) :Action(pApp)
{
	iconselected = true;
}
void SavebytypeAction::Execute() {
	ReadActionParameters();
	if (savefile.is_open()&&iconselected) {

		string Fillcolour;// a string for fillcolour
		string Drawcolour;// a string for drawcolour
		if (UI.FillColor == MAGENTA)
			Fillcolour = "CMAGENTA";
		if (UI.FillColor == BLACK)
			Fillcolour = "CBLACK";
		if (UI.FillColor == RED)
			Fillcolour = "CRED";
		if (UI.FillColor == GREEN)
			Fillcolour = "CGREEN";
		if (UI.FillColor == WHITE)
			Fillcolour = "CWHITE";
		if (UI.FillColor == BLUE)
			Fillcolour = "CBLUE";
		if (UI.DrawColor == BLUE)
			Drawcolour = "CBLUE";
		if (UI.DrawColor == BLACK)
			Drawcolour = "CBLACK";
		if (UI.DrawColor == RED)
			Drawcolour = "CRED";
		if (UI.DrawColor == GREEN)
			Drawcolour = "CGREEN";
		if (UI.DrawColor == WHITE)
			Drawcolour = "CWHITE";
		savefile << Drawcolour << " " << Fillcolour << endl << pManager->GetFigureCount() << endl;
		

		pManager->Savefiguresbytype(savefile, Figchosen);
		savefile.close();
		Output* pOut = pManager->GetOutput();
		pOut->CreateDrawToolBar();
		pOut->PrintMessage("saved");
	}
	else {
		pManager->GetOutput()->PrintMessage(" can't save this figures");
		Output* pOut = pManager->GetOutput();
		pOut->CreateDrawToolBar();
		pOut->PrintMessage("unsaved");
	}
}
void SavebytypeAction::ReadActionParameters() {
	//Get a Pointer to the Input  Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateChooseFigToolBar();
	pOut->PrintMessage("Choose the desired shape to save");
	Figchosen = pIn->GetUserAction();
	if (Figchosen == EMPTY){
		iconselected = false;
	}
	if (Figchosen == DRAWING_AREA) {
		iconselected = false;
	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("enter file name to save");
	filename = pIn->GetSrting(pOut);
	savefile.open(filename + ".txt");

}
SavebytypeAction::~SavebytypeAction() {
}
