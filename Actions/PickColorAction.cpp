#include "PickColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <cstdlib>
#include <ctime>


PickColorAction::PickColorAction(ApplicationManager* pApp):Action(pApp)
{
}


void PickColorAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input  Interfaces
	Input* pIn = pManager->GetInput();
		pIn->GetPointClicked(HIDE.x,HIDE.y);
		if(HIDE.y <= UI.ToolBarHeight)
		{	
			//zero is an arbitrary flag for the click on the icon of the game
			if(HIDE.x >= UI.MenuItemWidth && HIDE.x<= 2*UI.MenuItemWidth)
				HIDE.x = HIDE.y =  0;
			// one in a arbitrary representing a click on the tool bar which will terminate the game
			else
				HIDE.x = HIDE.y = 1;
		}
}


void PickColorAction::HideFigure(CFigure** list, CFigure* ShapePtr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(list[i] == ShapePtr)
		{
			list[i] = NULL;
		}
	}
}

void PickColorAction::Execute()
{		
	// variables to store the count of each shape
	int RedCount = 0, GreenCount = 0, BlueCount = 0, WhiteCount = 0, BlackCount = 0, NonFilledCount = 0, ShapeCount = 0;
	// stores the number of figures in the figure list before any manipulations
	int InitFigCnt = pManager->GetFigureCount();
	//random number for randomly chosen shapecolor
	int RandShapeColor;
	// need the output pointer to print messages on the status bar
	Output* pOut = pManager->GetOutput();
	//check if there is figures from the beginning
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
	// loop to count each color of shapes
	for (int i = 0; i < InitFigCnt; i++)
	{
		switch (Copy[i]->GetFillColor())
		{
		case CRED:
			RedCount++;
			break;
		case CWHITE:
			WhiteCount++;
			break;
		case CBLACK:
			BlackCount++;
			break;
		case CBLUE:
			BlueCount++;
			break;
		case CGREEN:
			GreenCount++;
			break;
		default:
			NonFilledCount++;
			break;
		}
	}
	// function to generate a seed for the rand fuction using the current time
	srand(time(NULL));
	// to make sure that the chosen number is for an existing type
	while (true)
	{
		RandShapeColor = rand() % 6 +10 ; // rand between 10->15
		if(RandShapeColor == CRED && RedCount != 0)
		{
			ShapeCount = RedCount;
			break;
		}
		if(RandShapeColor == CWHITE && WhiteCount != 0)
		{
			ShapeCount = WhiteCount;
			break;
		}
		if(RandShapeColor == CBLACK && BlackCount != 0)
		{
			ShapeCount = BlackCount;
			break;
		}
		if(RandShapeColor == CBLUE && BlueCount != 0)
		{
			ShapeCount = BlueCount;
			break;
		}
		if(RandShapeColor == CGREEN && GreenCount != 0)
		{
			ShapeCount = GreenCount;
			break;
		}
		if(RandShapeColor == CNONFILLED && NonFilledCount != 0)	
		{
			ShapeCount = NonFilledCount;
			break;
		}

	}
	// prompt the user to pick all shapes of a randomly chosen certain type
	switch (RandShapeColor)
	{
	case CRED:
		pOut->PrintMessage("Pick all the red shapes. ");
		break;
	case CWHITE:
		pOut->PrintMessage("Pick all the white shapes. ");
		break;
	case CBLACK:
		pOut->PrintMessage("Pick all the black shapes. ");
		break;
	case CBLUE:
		pOut->PrintMessage("Pick all the blue shapes. ");
		break;
	case CGREEN:
		pOut->PrintMessage("Pick all the green shapes. ");
		break;
	default :
		pOut->PrintMessage("Pick all the non filled shapes pick lines also if any exist. ");
		break;
	}

	// to store number of correct and incorrect picks
	int WrongCount = 0;
	int RightCount = 0;

	
	for (int i = 0; i < pManager->GetFigureCount() + 8; i++)
	{	
		ReadActionParameters();
		// if the user pressed on the game icon again 
		if(HIDE.y == 0)
		{
			for (int i = 0; i < InitFigCnt; i++)
			{
				Copy[i] = TempPtr[i];
			}
			pManager->UpdateInterface();
			delete []TempPtr;
			Execute();
			return;
		}
		// if he pressed anywhere eles on the tool bar terminates the game
		if(HIDE.y == 1)
			break;

		CFigure* PickedFigure = pManager->GetFigure(HIDE.x, HIDE.y);
		if(PickedFigure == NULL )
		{
			pOut->PrintMessage("You should pick all the existing figures of the type specified.");

		}
		else if(PickedFigure->GetFillColor() == RandShapeColor)
		{
			HideFigure(Copy, PickedFigure, InitFigCnt);
			RightCount++;
			ShapeCount--;
			pOut->PrintMessage("Well done!");	
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
	// if the user didn't press on the toolbar
	if(HIDE.y !=1 && HIDE.y != 0)
	{
		pOut->PrintMessage("number of wrong picks : " + to_string(WrongCount)+"   number of right picks : " + to_string(RightCount) + ", Press anywhere to continue");
		ReadActionParameters();	 // picked figure in this line is found but not necessary but i used this function inorder not to declare another variable of type input
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("Pick by type has terminated, Please choose an icon from the tool bar.");
	// giving the shapes back to the figlist
	for (int i = 0; i < InitFigCnt; i++)
	{
		Copy[i] = TempPtr[i];
	}
	// releasing memory
	delete []TempPtr;
	pManager->UnSelect(pManager->GetSelected());

}



PickColorAction::~PickColorAction(void)
{
	
}

