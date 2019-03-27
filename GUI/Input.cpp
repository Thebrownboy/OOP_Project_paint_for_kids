#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT; 
			case ITM_TRI: return DRAW_TRI;
			case ITM_LIN: return DRAW_LINE;
			case ITM_ROM: return DRAW_RHOMBUS;
			case ITM_ELIP: return DRAW_ELLIPSE;
			case ITM_DELETE: return DEL ;
			case ITM_ToDraw: return DRAW_Todrawcolor ;
			case ITM_TOFILL: return DRAW_TOfill ;
			case ITM_CUT: return DRAW_CUT;
			case ITM_COPY: return DRAW_COPY;
			case ITM_PASTE: return DRAW_PASTE;
			case ITM_RESIZE: return DRAW_RESIZE;
			case ITM_SAVE: return SAVE;
			case ITM_SAVETYPE: return SAVE_BY_TYPE;
			case ITM_LOAD: return LOAD;
			case ITM_SWITCH: return TO_PLAY;
			case ITM_SELECT: return SELECT;
			case ITM_VOICE: return Voice;
			case ITM_BACK_FORNT : return BackFront;
			case ITM_EXIT: return EXIT;	
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if ( y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case PLAY_PICK_TYPE: return PICKTYPE;
				case PLAY_PICK_COLOR: return PICKCOLOR;
				case TO_DRAW2: return TO_DRAW;
				case PLAY_EXIT: return EXIT;
				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	
	else if(UI.InterfaceMode==MODE_COLOR)
	{
		if ( y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RED: return CRED;
			case ITM_WHITE: return CWHITE;
			case ITM_BLACK: return CBLACK;
			case ITM_BLUE: return CBLUE;
			case ITM_GREEN: return CGREEN;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		else if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECTANGLE: return DRAW_RECT;
			case ITM_LINE: return DRAW_LINE;
			case ITM_TRIANGLE: return DRAW_TRI;
			case ITM_RHOMBUS: return DRAW_RHOMBUS;
			case ITM_ELLIPSE: return DRAW_ELLIPSE;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		else
		{
			return DRAWING_AREA;
		}

	}
}
/////////////////////////////////
	
Input::~Input()
{
}
