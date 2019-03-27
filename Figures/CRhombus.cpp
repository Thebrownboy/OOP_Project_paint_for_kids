#include "CRhombus.h"


CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	ID = id;
	center = P1;
	
}
Point CRhombus::GetCenter()
{
	return center;
}
void CRhombus:: SetPostion(int P)
{
	Postion=P;

}





void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a line on the screen	
	pOut->DrawRhombus(center, FigGfxInfo, Selected);
}

double CRhombus::area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool CRhombus::IsInside(int x, int y)
{
	double A=area(center.x-100,center.y,center.x,center.y+50,center.x+100,center.y)*2;
			double A1=area(x,y,center.x,center.y+50,center.x+100,center.y);
			double A2=area(x,y,center.x,center.y+50,center.x-100,center.y);
			double A3=area(x,y,center.x,center.y-50,center.x+100,center.y);
			double A4=area(x,y,center.x,center.y-50,center.x-100,center.y);
			if(A==(A1+A2+A3+A4))
			 return true ;
			return false;
}

int CRhombus::GetFillColor()
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

void CRhombus::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The Rhombus ID is "+to_string(ID)+", Center is at("+to_string(center.x)+", "+to_string(center.y)+"), Height is 100, Width is 200.");
}
void CRhombus::save(ofstream& file) {
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
	if (FigGfxInfo.isFilled == false)
		Fillcolour = "CNONFILLED";
	if (FigGfxInfo.FillClr == MAGENTA)
		Fillcolour = "CMAGENTA";
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
	file << "RHOM " << ID << " " << center.x << " " << center.y << " " << Drawcolour << " " << Fillcolour << endl;
}