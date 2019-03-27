#pragma once
#include "CFigure.h"
class CLine : public CFigure
{
private:
	Point start;	
	Point end;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo, int id);
	double GetSlope();
	double GetTHEC();
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int ,int);
	virtual int GetFillColor();
	virtual void SetPostion(int p);
	void PrintInfo(Output* pOut);
	Point Getstart() ;
	Point Getend() ;
	virtual void save(ofstream&);


};