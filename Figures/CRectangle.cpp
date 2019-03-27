#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	
	Corner1 = P1;
	Corner2 = P2;
	ID = id;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle:: SetPostion(int P)
{
	Postion=P;

}


Point CRectangle::GetC1()
{
	return Corner1;
}
Point CRectangle::GetC2()
{
	return Corner2;
}


bool CRectangle::IsInside(int x,int y)
{
	if((Corner1.x>x&&Corner2.x<x||Corner1.x<x&&Corner2.x>x)&&(Corner1.y>y&&Corner2.y<y||Corner1.y<y&&Corner2.y>y))
		{
			return true;
		}
		return false;
}

int CRectangle::GetFillColor()
{
	if(FigGfxInfo.isFilled == false)
		return CNONFILLED;
	if(FigGfxInfo.FillClr == BLACK)
		return CBLACK;
	if(FigGfxInfo.FillClr == RED)
		return CRED;
	if(FigGfxInfo.FillClr == GREEN)
		return CGREEN;
	if(FigGfxInfo.FillClr == WHITE)
		return CWHITE;
	return CBLUE;

}

void CRectangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The Rectangle ID is "+to_string(ID)+",  height is "+to_string(abs(Corner1.y-Corner2.y))+", Width is "+to_string(abs(Corner1.x-Corner2.x))+".");
}
void CRectangle::save(ofstream& file) {
	string Fillcolour;
	string Drawcolour;

	if (FigGfxInfo.FillClr == BLACK)
		Fillcolour = "CBLACK";
	if (FigGfxInfo.FillClr == RED)
		Fillcolour = "CRED";
	if (FigGfxInfo.FillClr == GREEN)
		Fillcolour = "CGREEN";
	if (FigGfxInfo.FillClr == WHITE)
		Fillcolour = "CWHITE";
	if (FigGfxInfo.FillClr == BLUE)
		Fillcolour = "CBLUE";
	if (FigGfxInfo.FillClr == MAGENTA)
		Fillcolour = "CMAGENTA";
	if (FigGfxInfo.isFilled == false)
		Fillcolour = "CNONFILLED";
	if (FigGfxInfo.DrawClr == BLACK)
		Drawcolour = "CBLACK";
	if (FigGfxInfo.DrawClr == RED)
		Drawcolour = "CRED";
	if (FigGfxInfo.DrawClr == GREEN)
		Drawcolour = "CGREEN";
	if (FigGfxInfo.DrawClr == WHITE)
		Drawcolour = "CWHITE";
	if (FigGfxInfo.DrawClr == BLUE)
		Drawcolour = "CBLUE";
	file << "RECT " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Drawcolour << " " << Fillcolour << endl;
}






