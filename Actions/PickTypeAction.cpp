#include "PickTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <cstdlib>
#include <ctime>
#include "..\Figures\CEllipse.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Cline.h"
#include "..\Figures\CRhombus.h"


PickTypeAction::PickTypeAction(ApplicationManager* pApp):Action(pApp)
{
}


void PickTypeAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input  Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(HIDE.x,HIDE.y);
	// check for the icon of the game to restart it
	if(HIDE.y <= UI.ToolBarHeight && HIDE.y >= 0)
		if(HIDE.x >= 0 && HIDE.x<= UI.MenuItemWidth)
			HIDE.x = HIDE.y =  0;
		else
			HIDE.x = HIDE.y = 1;
}

// function to make the picked figure's pointer point to null so it's not drawn this wasn't made a member fuction in order not to include CFigure in the header of the class 
void HideFigure(CFigure** list, CFigure* ShapePtr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(list[i] == ShapePtr)
		{
			list[i] = NULL;
		}
	}
} 

void PickTypeAction::Execute()
{
	enum ShapeType{Rectangle, Triangle, Line, Ellipse, Rhombus};
	// variables to store the count of each shape
	int RectCount = 0, ElpsCount = 0, LineCount = 0, RhomCount = 0, TriCount = 0, ShapeCount = 0;
	// stores the number of figures in the figure list before any manipulations
	int InitFigCnt = pManager->GetFigureCount();
	//random number for randomly chosen shapetype
	int RandShapeType; 
	// need the output pointer to print messages on the status bar
	Output* pOut = pManager->GetOutput();
	if(pManager->GetFigureCount() == 0)
	{
		pOut->PrintMessage("No figures to play with, please draw some figures then try again.");
		return;
	}
	// a copy of the figure list
	CFigure **Copy= pManager->GetFigures();
	CFigure **TempPtr = new CFigure*[InitFigCnt];
	for (int i = 0; i < InitFigCnt; i++)
	{
		TempPtr[i] = Copy[i];
	}
	// loop to count each type of shapes
	for (int i = 0; i < InitFigCnt; i++)
	{
		if(dynamic_cast<CRectangle*>(Copy[i]))
			RectCount++;
		else if(dynamic_cast<CTriangle*>(Copy[i]))
			TriCount++;
		else if(dynamic_cast<CLine*>(Copy[i]))
			LineCount++;
		else if(dynamic_cast<CEllipse*>(Copy[i]))
			ElpsCount++;
		else if(dynamic_cast<CRhombus*>(Copy[i]))
			RhomCount++;
	}
	// function to generate a seed for the rand fuction using the current time
	srand(time(NULL));
	// to make sure that the chosen number is for an existing type
	while (true)
	{
		RandShapeType = rand()%5;
		if(RandShapeType == Rectangle && RectCount != 0)
		{
			ShapeCount = RectCount;
			break;
		}
		if(RandShapeType == Triangle && TriCount != 0)
		{
			ShapeCount = TriCount;
			break;
		}
		if(RandShapeType == Line && LineCount != 0)
		{
			ShapeCount = LineCount;
			break;
		}
		if(RandShapeType == Ellipse && ElpsCount != 0)
		{
			ShapeCount = ElpsCount;
			break;
		}
		if(RandShapeType == Rhombus && RhomCount != 0)
		{
			ShapeCount = RhomCount;
			break;
		}
	}
	// prompt the user to pick all shapes of a randomly chosen certain type
	switch (RandShapeType)
	{
	case Rectangle:
		pOut->PrintMessage("Pick all the rectangles. ");
		break;
	case Triangle:
		pOut->PrintMessage("Pick all the triangles. ");
		break;
	case Line:
		pOut->PrintMessage("Pick all the lines. ");
		break;
	case Ellipse:
		pOut->PrintMessage("Pick all the ellipses. ");
		break;
	default:
		pOut->PrintMessage("Pick all the Rhombuses. ");
		break;
	}

	// to store number of correct and incorrect picks
	int WrongCount = 0;
	int RightCount = 0;

	
	for (int i = 0; i < pManager->GetFigureCount() + 8; i++)
	{	
		ReadActionParameters();
		if(HIDE.y == 0)
		{
			for (int i = 0; i < InitFigCnt; i++)
			{
				Copy[i] = TempPtr[i];
			}
			delete [] TempPtr ;
			pManager->UpdateInterface();
			Execute();
			return;
		}
		// a click on the tool bar except the game icon terminates the game
		if(HIDE.y == 1)
			break;

		CFigure* PickedFigure = pManager->GetFigure(HIDE.x, HIDE.y);
		if(dynamic_cast<CRectangle*>(PickedFigure) && RandShapeType == Rectangle)
		{
			HideFigure(Copy, PickedFigure, InitFigCnt);
			RightCount++;
			ShapeCount--;
			pOut->PrintMessage("Well done!");

		}
					
		else if(dynamic_cast<CTriangle*>(PickedFigure) && RandShapeType == Triangle)
		{
			HideFigure(Copy, PickedFigure, InitFigCnt);
			RightCount++;
			ShapeCount--;
			pOut->PrintMessage("Well done!");
		}
		else if(dynamic_cast<CLine*>( PickedFigure) && RandShapeType == Line)
		{
			HideFigure(Copy, PickedFigure, InitFigCnt);
			RightCount++;
			ShapeCount--;
			pOut->PrintMessage("Well done!");
		}
		else if(dynamic_cast<CEllipse*>(PickedFigure) && RandShapeType == Ellipse)
		{
			HideFigure(Copy, PickedFigure, InitFigCnt);
			RightCount++;
			ShapeCount--;
			pOut->PrintMessage("Well done!");
		}

		else if(dynamic_cast<CRhombus*>(PickedFigure) && RandShapeType == Rhombus)
		{
			HideFigure(Copy, PickedFigure, InitFigCnt);
			RightCount++;
			ShapeCount--;
			pOut->PrintMessage("Well done!");
		}
		else if(PickedFigure == NULL)
		{
			pOut->PrintMessage("You should pick all the existing figures of the type specified.");
		}
		else
		{
			pOut->PrintMessage("Wrong shape picked");
			HideFigure(Copy, PickedFigure, InitFigCnt);
			WrongCount++;
		}
		pManager->UpdateInterface();
		if (ShapeCount == 0)
		{
			break;
		}
		

	}
	if(HIDE.y !=1 && HIDE.y != 0)
	{
		pOut->PrintMessage("number of wrong picks : " + to_string(WrongCount)+"   number of right picks : " + to_string(RightCount) + ", Press anywhere to continue");
		ReadActionParameters();	 // picked figure in this line is found but not necessary but i used this function inorder not to declare another variable of type input
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("Pick by type has terminated, Please choose an icon from the tool bar.");

	for (int i = 0; i < InitFigCnt; i++)
	{
		Copy[i] = TempPtr[i];
	}
	delete []TempPtr;
	pManager->UnSelect(pManager->GetSelected());
}



PickTypeAction::~PickTypeAction(void)
{
	
}

