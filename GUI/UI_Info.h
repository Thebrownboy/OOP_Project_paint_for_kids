#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR, //the mode to select the color of the drawing or filling 
	MUTE,
	SoundON,
	MODE_CHOOSE_FIG  // to choose a figure in save by type

};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,         //Recangle item in menu
	ITM_LIN,          //line  item in menu
	ITM_TRI,          //TRiangle item in menu 
 	ITM_ROM,          //Rohoumbs item in menu
	ITM_ELIP,         //Elipse item in menu
	ITM_ToDraw ,      //to select a color item in menu
	ITM_TOFILL,       //to fill a color  item in menu
	ITM_SELECT,       //to select shape  item in menu
	ITM_CUT,          //to cut item in menu
	ITM_COPY,         //copy  item in menu
	ITM_PASTE,        //paste  item in menu
	ITM_SAVE,         //save  item in menu
	ITM_SAVETYPE,	  //save item by type
	ITM_LOAD,         //load a graph from a file
	ITM_DELETE,       //delete item in menu
	ITM_RESIZE,       //Resize item in menu
	ITM_SWITCH,       //switch item in menu
	ITM_VOICE,		  //voice on
	ITM_BACK_FORNT,	  //bring back and front
	ITM_EXIT,         //Exit item
	DRAW_ITM_COUNT	  //no. of menu items ==> This should be the last line in this enum
	
};
enum colormenuITEM
{
	ITM_RED,      //to select the red color in the color's menu
  	ITM_WHITE,    //to select the white color in the color's menu
	ITM_BLACK,    //to select the Black  color in the color's menu
	ITM_BLUE,     //to select the Blue color in the color's menu
	ITM_GREEN,    //to select the Green  color in the color's menu
    COLOR_count , // the number of the colors in the color's menu
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	//TODO: Add more items names here
	PLAY_PICK_TYPE, //to pick a shape from the playing area by color
	PLAY_PICK_COLOR, //to pick a shape from the playing area by type 
	TO_DRAW2,       //to to return to drawing area  from the playing mode 
	PLAY_EXIT,      //to Exit from the program  
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};
enum ChooseFigureItem
{
	ITM_RECTANGLE,        //Recangle item in menu 
	ITM_LINE,     //line  item in menu
	ITM_TRIANGLE,          //TRiangle item in menu 
	ITM_RHOMBUS,          //Rohoumbs item in menu
	ITM_ELLIPSE,		  // Ellipse item in meu
	ITEM_COUNT
};
__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	GUI_MODE VoiceMode;
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI



#endif