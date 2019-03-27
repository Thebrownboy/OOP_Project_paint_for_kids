#include "LoadAction.h"
using namespace std;
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}


void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please enter the file you want load from");
	filename = pIn->GetSrting(pOut);
}
void LoadAction::Execute() {
	ReadActionParameters();
	loadfile.open(filename + ".txt");
	if (!loadfile.is_open()) {
		pManager->GetOutput()->PrintMessage("there is no file with this name");
	}
	else {
		string klammlo4lazma;
		string Drawcolour;
		string Fillcolour;
		getline(loadfile, Drawcolour, ' ');
		getline(loadfile, Fillcolour);
		getline(loadfile, klammlo4lazma);
		if (Drawcolour == "CBLUE")
			UI.DrawColor = BLUE;
		if (Drawcolour == "CGREEN")
			UI.DrawColor = GREEN;
		if (Drawcolour == "CRED")
			UI.DrawColor = RED;
		if (Drawcolour == "CBLACK")
			UI.DrawColor = BLACK;
		if (Drawcolour == "CWHITE")
			UI.DrawColor = WHITE;
		if (Fillcolour == "CBLUE")
			UI.FillColor = BLUE;
		if (Fillcolour == "CGREEN")
			UI.FillColor = GREEN;
		if (Fillcolour == "CRED")
			UI.FillColor = RED;
		if (Fillcolour == "CBLACK")
			UI.FillColor = BLACK;
		if (Fillcolour == "CWHITE")
			UI.FillColor = WHITE;
		if (Fillcolour == "CMAGENTA")
			UI.FillColor = MAGENTA;
		while (!loadfile.eof())
		{
			int id;
			string line;
			getline(loadfile, line, ' ');
			if (line[0] == '\n') {
				line.erase(0, 1);
			}
			string RE = "RECT";
			if (line == RE) {

				Point P1, P2;
				loadfile >> id;
				loadfile >> P1.x;
				loadfile >> P1.y;
				loadfile >> P2.x;
				loadfile >> P2.y;
				GfxInfo RectGfxInfo;
				RectGfxInfo.isFilled = true;
				string drawcolour;
				string fillcolour;
				getline(loadfile, drawcolour, 'C');
				getline(loadfile, drawcolour, ' ');
				getline(loadfile, fillcolour);
				if (fillcolour[0] == ' ') {
					fillcolour.erase(0, 1);
				}
				if (drawcolour == "BLUE")
					RectGfxInfo.DrawClr = BLUE;
				if (drawcolour == "GREEN")
					RectGfxInfo.DrawClr = GREEN;
				if (drawcolour == "RED")
					RectGfxInfo.DrawClr = RED;
				if (drawcolour == "BLACK")
					RectGfxInfo.DrawClr = BLACK;
				if (drawcolour == "WHITE")
					RectGfxInfo.DrawClr = WHITE;
				if (fillcolour == "CNONFILLED")
					RectGfxInfo.isFilled = false;
				if (fillcolour == "CBLACK")
					RectGfxInfo.FillClr = BLACK;
				if (fillcolour == "CRED")
					RectGfxInfo.FillClr = RED;
				if (fillcolour == "CGREEN")
					RectGfxInfo.FillClr = GREEN;
				if (fillcolour == "CWHITE")
					RectGfxInfo.FillClr = WHITE;
				if (fillcolour == "CBLUE")
					RectGfxInfo.FillClr = BLUE;

				//Create a rectangle with the parameters read from the loadfile
				CRectangle *R = new CRectangle(P1, P2, RectGfxInfo, id);

				//Add the rectangle to the list of figures
				pManager->AddFigure(R);
			}
			string E = "ELIP";
			if (line == E) {
				Point P1;
				loadfile >> id;

				loadfile >> P1.x;
				loadfile >> P1.y;

				GfxInfo EllpsGfxInfo;
				EllpsGfxInfo.isFilled = true;
				string drawcolour;
				string fillcolour;
				getline(loadfile, drawcolour, 'C');
				getline(loadfile, drawcolour, ' ');
				getline(loadfile, fillcolour);
				if (drawcolour == "BLUE")
					EllpsGfxInfo.DrawClr = BLUE;
				if (drawcolour == "GREEN")
					EllpsGfxInfo.DrawClr = GREEN;
				if (drawcolour == "RED")
					EllpsGfxInfo.DrawClr = RED;
				if (drawcolour == "BLACK")
					EllpsGfxInfo.DrawClr = BLACK;
				if (drawcolour == "WHITE")
					EllpsGfxInfo.DrawClr = WHITE;
				if (fillcolour == "CNONFILLED")
					EllpsGfxInfo.isFilled = false;
				if (fillcolour == "CBLACK")
					EllpsGfxInfo.FillClr = BLACK;
				if (fillcolour == "CRED")
					EllpsGfxInfo.FillClr = RED;
				if (fillcolour == "CGREEN")
					EllpsGfxInfo.FillClr = GREEN;
				if (fillcolour == "CWHITE")
					EllpsGfxInfo.FillClr = WHITE;
				if (fillcolour == "CBLUE")
					EllpsGfxInfo.FillClr = BLUE;

				//Create a elipse with the parameters read from the loadfile
				CEllipse *E = new CEllipse(P1, EllpsGfxInfo, id);

				//Add the triangle to the list of figures
				pManager->AddFigure(E);
			}
			string L = "LINE";
			if (line == L) {
				GfxInfo LineGfxInfo;
				Point P1, P2;
				loadfile >> id;

				LineGfxInfo.isFilled = true;

				loadfile >> P1.x;
				loadfile >> P1.y;
				loadfile >> P2.x;
				loadfile >> P2.y;
				string drawcolour;
				string fillcolour;
				getline(loadfile, drawcolour, 'C');
				getline(loadfile, drawcolour, ' ');
				getline(loadfile, fillcolour);
				if (drawcolour == "BLUE")
					LineGfxInfo.DrawClr = BLUE;
				if (drawcolour == "GREEN")
					LineGfxInfo.DrawClr = GREEN;
				if (drawcolour == "RED")
					LineGfxInfo.DrawClr = RED;
				if (drawcolour == "BLACK")
					LineGfxInfo.DrawClr = BLACK;
				if (drawcolour == "WHITE")
					LineGfxInfo.DrawClr = WHITE;
				if (fillcolour == "CNONFILLED")
					LineGfxInfo.isFilled = false;
				if (fillcolour == "CBLACK")
					LineGfxInfo.FillClr = BLACK;
				if (fillcolour == "CRED")
					LineGfxInfo.FillClr = RED;
				if (fillcolour == "CGREEN")
					LineGfxInfo.FillClr = GREEN;
				if (fillcolour == "CWHITE")
					LineGfxInfo.FillClr = WHITE;
				if (fillcolour == "CBLUE")
					LineGfxInfo.FillClr = BLUE;


				//Create a line with the parameters read from the loadfile
				CLine *L = new CLine(P1, P2, LineGfxInfo, id);

				//Add the line to the list of figures
				pManager->AddFigure(L);
			}
			string R = "RHOM";
			if (line == R) {
				GfxInfo RHOMGfxInfo;
				Point P1;
				loadfile >> id;
				RHOMGfxInfo.isFilled = true;

				loadfile >> P1.x;
				loadfile >> P1.y;
				string drawcolour;
				string fillcolour;
				getline(loadfile, drawcolour, 'C');
				getline(loadfile, drawcolour, ' ');
				getline(loadfile, fillcolour);
				if (drawcolour == "BLUE")
					RHOMGfxInfo.DrawClr = BLUE;
				if (drawcolour == "GREEN")
					RHOMGfxInfo.DrawClr = GREEN;
				if (drawcolour == "RED")
					RHOMGfxInfo.DrawClr = RED;
				if (drawcolour == "BLACK")
					RHOMGfxInfo.DrawClr = BLACK;
				if (drawcolour == "WHITE")
					RHOMGfxInfo.DrawClr = WHITE;
				if (fillcolour == "CNONFILLED")
					RHOMGfxInfo.isFilled = false;
				if (fillcolour == "CBLACK")
					RHOMGfxInfo.FillClr = BLACK;
				if (fillcolour == "CRED")
					RHOMGfxInfo.FillClr = RED;
				if (fillcolour == "CGREEN")
					RHOMGfxInfo.FillClr = GREEN;
				if (fillcolour == "CWHITE")
					RHOMGfxInfo.FillClr = WHITE;
				if (fillcolour == "CBLUE")
					RHOMGfxInfo.FillClr = BLUE;
				//Create a Rhombus with the parameters read from the user
				CRhombus *R = new CRhombus(P1, RHOMGfxInfo, id);

				//Add the Rhombus to the list of figures
				pManager->AddFigure(R);
			}
			string T = "TRIANG";
			if (line == T) {
				GfxInfo TRIGfxInfo;
				Point P1, P2, P3;
				loadfile >> id;
				TRIGfxInfo.isFilled = true;

				loadfile >> P1.x;
				loadfile >> P1.y;
				loadfile >> P2.x;
				loadfile >> P2.y;
				loadfile >> P3.x;
				loadfile >> P3.y;
				string drawcolour;
				string fillcolour;
				getline(loadfile, drawcolour, 'C');
				getline(loadfile, drawcolour, ' ');
				getline(loadfile, fillcolour);
				if (drawcolour == "BLUE")
					TRIGfxInfo.DrawClr = BLUE;
				if (drawcolour == "GREEN")
					TRIGfxInfo.DrawClr = GREEN;
				if (drawcolour == "RED")
					TRIGfxInfo.DrawClr = RED;
				if (drawcolour == "BLACK")
					TRIGfxInfo.DrawClr = BLACK;
				if (drawcolour == "WHITE")
					TRIGfxInfo.DrawClr = WHITE;
				if (fillcolour == "CNONFILLED")
					TRIGfxInfo.isFilled = false;
				if (fillcolour == "CBLACK")
					TRIGfxInfo.FillClr = BLACK;
				if (fillcolour == "CRED")
					TRIGfxInfo.FillClr = RED;
				if (fillcolour == "CGREEN")
					TRIGfxInfo.FillClr = GREEN;
				if (fillcolour == "CWHITE")
					TRIGfxInfo.FillClr = WHITE;
				if (fillcolour == "CBLUE")
					TRIGfxInfo.FillClr = BLUE;

				//Create a triangle with the parameters read from the user
				CTriangle *T = new CTriangle(P1, P2, P3, TRIGfxInfo, id);

				//Add the triangle to the list of figures
				pManager->AddFigure(T);
			}

			
		}


	}
	pManager->GetOutput()->PrintMessage("loaded");
}


LoadAction::~LoadAction(void)
{
	loadfile.close();
}
