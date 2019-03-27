#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Postion=0;
}



bool CFigure::IsSelected() const
{	return Selected; }

void CFigure:: SetSelected(bool s)
{
	Selected=s;
}
int CFigure:: GetPostion()const
{
	return Postion;
}



void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	if (Fclr!=UI.BkGrndColor)
		FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
GfxInfo CFigure:: GetFiginfo() 
{
	return FigGfxInfo ;


}

void CFigure::setFillmode(bool x ) 
{
	FigGfxInfo.isFilled = x ;

}
