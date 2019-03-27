#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1450;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 64;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = OLDLACE;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////
void  Output::createcolorwindow()
{
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1250;
	UI.height = 650;
	UI.wx =5;
	UI.wy =5;
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 65;
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.VoiceMode=SoundON;
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	CreatecolorToolBar() ;
	CreateStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////
Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";     //icon for drawing rectangle 
  	MenuItemImages[ITM_ROM]="images\\MenuItems\\Menu_RHO.jpg";         //icon for drawing  rohoumbs 
	MenuItemImages[ITM_ELIP]="images\\MenuItems\\Menu_ELI.jpg";        //icon for drawing  elipse 
	MenuItemImages[ITM_TRI]="images\\MenuItems\\Menu_TRi.jpg";         //icon for drawing  triangle 
	MenuItemImages[ITM_LIN]="images\\MenuItems\\Menu_LIN.jpg";         //icon for drawing line
	MenuItemImages[ITM_ToDraw]="images\\MenuItems\\changedrawcolor.jpg";   //icon for  to change draw color 	
	MenuItemImages[ITM_TOFILL]="images\\MenuItems\\changefillcolor.jpg";  //icon for  to change fill color 
	MenuItemImages[ITM_CUT]="images\\MenuItems\\cut.jpg";              //icon for cutting 
	MenuItemImages[ITM_COPY]="images\\MenuItems\\copy.jpg";            //icon for copping
	MenuItemImages[ITM_PASTE]="images\\MenuItems\\paste.jpg";          //icon for  paste
 	MenuItemImages[ITM_SAVE]="images\\MenuItems\\savegraph.jpg";       //icon for saving
 	MenuItemImages[ITM_SAVETYPE]="images\\MenuItems\\savebytype.jpg";       //icon for saving
 	MenuItemImages[ITM_LOAD]="images\\MenuItems\\load.jpg";       //icon for saving
	MenuItemImages[ITM_DELETE]="images\\MenuItems\\delete.jpg";        //icon for deleting 
	MenuItemImages[ITM_RESIZE]="images\\MenuItems\\resize.jpg";        //icon for resizing the shapes 
	MenuItemImages[ITM_SWITCH]="images\\MenuItems\\toplay.jpg";        //icon for swithching between playing  mode and drawing mode  
	MenuItemImages[ITM_SELECT]="images\\MenuItems\\select.jpg";        //icon for selecting
	if(UI.VoiceMode==SoundON)
	MenuItemImages[ITM_VOICE]="images\\MenuItems\\SOUND.jpg";        //icon for voice on 
	else
	MenuItemImages[ITM_VOICE]="images\\MenuItems\\MUTE.jpg";        //icon for voice off 
	MenuItemImages[ITM_BACK_FORNT]="images\\MenuItems\\BackFront.jpg";        //icon to send back and bring front
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";          //icon for exit 
	// Prepare images for each menu item and add it to the list (DONE)
	//Draw menu item one image at a time
	pWind->SetPen(BLACK,2);
	for(int i=0; i<DRAW_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		//draw a line between each element in the toolbar
		pWind->DrawLine(i*UI.MenuItemWidth, 0, i*UI.MenuItemWidth, UI.ToolBarHeight);	
	}
	//draw a line after last element in the toolbar
	pWind->DrawLine(DRAW_ITM_COUNT * UI.MenuItemWidth, 0, DRAW_ITM_COUNT * UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatecolorToolBar() const
{
	UI.InterfaceMode = MODE_COLOR ;
	string MenuItemImages[COLOR_count ];
	MenuItemImages[ITM_RED]="images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_WHITE]="images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_BLACK]="images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_BLUE]="images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_GREEN]="images\\MenuItems\\green.jpg";
	pWind->SetPen(BLACK,2);
	for(int i=0; i<COLOR_count; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		//drawing a line between each element in the toolbar
		pWind->DrawLine(i*UI.MenuItemWidth, 0, i*UI.MenuItemWidth, UI.ToolBarHeight);	
	}
	//drawing a line after last element in the toolbar
	pWind->DrawLine(COLOR_count * UI.MenuItemWidth, 0, COLOR_count * UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////
void Output::CreateChooseFigToolBar() const
{
	UI.InterfaceMode = MODE_CHOOSE_FIG;

	string MenuItemImages[ITEM_COUNT];
	MenuItemImages[ITM_RECTANGLE] = "images\\MenuItems\\Menu_Rect.jpg";     //icon for drawing rectangle 
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_RHO.jpg";         //icon for drawing  rohoumbs 
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_ELI.jpg";        //icon for drawing  elipse 
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_TRi.jpg";         //icon for drawing  triangle 
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_LIN.jpg";         //icon for drawing line 
																		  //Draw menu item one image at a time
	pWind->SetPen(BLACK, 2);
	for (int i = 0; i<ITEM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		//draw a line between each element in the toolbar
		pWind->DrawLine(i*UI.MenuItemWidth, 0, i*UI.MenuItemWidth, UI.ToolBarHeight);
	}
	//draw a line after last element in the toolbar
	pWind->DrawLine(ITEM_COUNT * UI.MenuItemWidth, 0, ITEM_COUNT * UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PLAY_PICK_TYPE] = "images\\MenuItems\\pick.jpg";
	MenuItemImages[PLAY_PICK_COLOR] = "images\\MenuItems\\pickcolor.jpg";
	MenuItemImages[TO_DRAW2] = "images\\MenuItems\\todraw.jpg";
	MenuItemImages[PLAY_EXIT] = "images\\MenuItems\\exit.jpg";
	// Prepare images for each menu item and add it to the list (DONE)
	//Draw menu item one image at a time
	pWind->SetPen(BLACK,2);
	for(int i=0; i<PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		//drawing a line between each element in the toolbar
		pWind->DrawLine(i*UI.MenuItemWidth, 0, i*UI.MenuItemWidth, UI.ToolBarHeight);	
	}
	//drawing a line after last element in the toolbar
	pWind->DrawLine(PLAY_ITM_COUNT * UI.MenuItemWidth, 0, PLAY_ITM_COUNT * UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
/////////////////////////////////////////////////////////////////////////////
void Output:: DrawLine(Point P1, Point P2, GfxInfo LINEGfxInfo, bool selected) const{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LINEGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style = FRAME;	

	
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
	
}
/////////////////////////////////////////////////////////////////////////////
void Output:: DrawTri(Point P1, Point P2,Point P3, GfxInfo TRIGfxInfo, bool selected) const{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = TRIGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (TRIGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(TRIGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	
}
/////////////////////////////////////////////////////////////////////////////
void Output:: DrawElipse(Point P1, GfxInfo ELPSGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = ELPSGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (ELPSGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(ELPSGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	pWind->DrawEllipse(P1.x+100, P1.y+50, P1.x-100, P1.y-50, style);
}
////////////////////////////////////////////////////////////////////////////
void Output:: DrawRhombus(Point P1, GfxInfo RhomGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RhomGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RhomGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RhomGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	int *Px=new int [4];
	int *Py=new int [4];
	Px[0]=P1.x-100;
	Px[1]=P1.x;
	Px[2]=P1.x+100;
	Px[3]=P1.x;
	Py[0]=P1.y;
	Py[1]=P1.y-50;
	Py[2]=P1.y;
	Py[3]=P1.y+50;
	pWind->DrawPolygon(Px,Py,4, style);
	delete [] Px;
	delete [] Py;
}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

