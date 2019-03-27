#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo, int id );
	Point GetC1();
	Point GetC2();
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int ,int);
	virtual int GetFillColor();
	virtual void SetPostion(int p);

	void PrintInfo(Output* pOut);
	virtual void save(ofstream&);



};



#endif