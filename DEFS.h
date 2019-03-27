#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		    //Draw Rectangle
	DRAW_LINE,		    //Draw Line
	DRAW_TRI,		    //Draw Triangle
	DRAW_RHOMBUS,	    //Draw Rhombus
	DRAW_ELLIPSE,       //Draw Ellipse
	CHNG_DRAW_CLR,	    //Change the drawing color
	CHNG_FILL_CLR,	    //Change the filling color
	DEL,			    //Delete a figure(s)
	DRAW_Todrawcolor,   // to to choose the color of drawing  
	DRAW_TOfill ,       //to to choose the color of filling 
	CRED,           // to select the red color 
	CWHITE,         // to select the white color 
	CBLACK,         // to select the black color 
	CBLUE,          // to select the blue color 
	CGREEN,         // to select the green color 
	CNONFILLED,     // represents the shape is non filled
	DRAW_CUT,           // to cut a shape it will be highlited  and the last shape cutted which wil be pasted 
	DRAW_COPY,          // to  copy a shape then it will be pasted but the last shape copied which will be pasted 
	DRAW_PASTE,         // after coping a shape  it will be coped 
	DRAW_RESIZE,        // to give the shape new size 
	SELECT,             //  to select a shape 
	SAVE,			    //Save the whole graph to a file
	SAVE_BY_TYPE,	    //Save the all the figures that have a specific type
	LOAD,			    //Load a graph from a file
	EXIT,			    //Exit the application
	DRAWING_AREA,	    //A click on the drawing area
	PLAYING_AREA,		//A click on the playin area
	STATUS,			    //A click on the status bar
	EMPTY,			    //A click on empty place in the toolbar
	PICKTYPE,           //to pick a shape by type
	PICKCOLOR,			//to pick a shape by color
	Voice,				//to control the voice
	BackFront,			//to send to back and bring to front the figures
	TO_DRAW,		    //Switch interface to Draw mode
	TO_PLAY			    //Switch interface to Play mode
	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};


#endif