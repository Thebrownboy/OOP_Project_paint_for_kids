#include "SaveAction.h"
using namespace std;

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}

void SaveAction::Execute() {
	ReadActionParameters();
	if (savefile.is_open()) {

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
		pManager->Savefigures(savefile);
		savefile.close();
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("enter file name to save");
	}
	else {
		pManager->GetOutput()->PrintMessage(" can't save this figures");
	}

}
void SaveAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter file name to save");
	filename = pIn->GetSrting(pOut);
	savefile.open(filename + ".txt");

}

SaveAction::~SaveAction(void)
{}
