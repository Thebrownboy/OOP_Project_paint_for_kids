#include "CEllipse.h"


CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	Center = P1;
	ID = id;

	
}
Point CEllipse::GetCenter()
{
	return Center;
}


	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::Drawelipse to draw a line on the screen	
	pOut->DrawElipse(Center, FigGfxInfo, Selected);
}

void CEllipse:: SetPostion(int P)
{
	Postion=P;

}




bool CEllipse::IsInside(int x ,int y)
{
	double H=(1.0*(x-Center.x)*(x-Center.x))/(10000)+(1.0*(y-Center.y)*(y-Center.y))/(50*50);
			if(H<=1)
				return true;
			return false ;
}

int CEllipse::GetFillColor()
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


void CEllipse::PrintInfo(Output* pOut)
{
	// need to put the figure id
	pOut->PrintMessage("The Ellipse ID is "+to_string(ID)+", Center is at("+to_string(Center.x)+", "+to_string(Center.y)+"), Height is 100, Width is 200.");
}
void CEllipse::save(ofstream& file) {
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

	file << "ELIP " << ID << " " << Center.x << " " << Center.y << " " << Drawcolour << " " << Fillcolour << endl;
}
