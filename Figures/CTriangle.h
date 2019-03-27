#pragma once
#include "CFigure.h"
class CTriangle :
	public CFigure
{
public:
private:
	Point vertix1;	
	Point vertix2;
	Point vertix3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo, int id);
	Point GetV1();
	Point GetV2();
	Point GetV3();
	
	virtual void Draw(Output* pOut) const;
	double area(int , int , int , int , int , int ) ;
	virtual bool IsInside(int ,int);
	virtual int GetFillColor();
	void PrintInfo(Output* pOut);
	virtual void SetPostion(int p);
	virtual void save(ofstream&);


};


