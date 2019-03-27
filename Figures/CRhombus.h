#pragma once
#include "CFigure.h"
class CRhombus :public CFigure
{
private:
	Point center;
public:
	CRhombus(Point ,GfxInfo FigureGfxInfo, int id);

	Point GetCenter();
	virtual void Draw(Output* pOut) const;
	double area(int , int , int , int , int , int ) ;
	virtual bool IsInside(int ,int);
	virtual int GetFillColor();
	virtual void SetPostion(int p);
	virtual void save(ofstream&);

	void PrintInfo(Output* pOut);

};


