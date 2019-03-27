#include "CopyAction.h"
class CopyAction ;
#include "..\ApplicationManager.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\Cline.h"

CopyAction::CopyAction(ApplicationManager * PApp):Action(PApp)
{
}


CopyAction::~CopyAction(void)
{
}
void CopyAction::Execute()
{
	CFigure*selcted =pManager->GetSelected() ;// firstly you  I  get the selected figure then  I will make actions on it .. 
	CFigure *clipo;// A figure that will store the clipboard ..
	Point p1,p2,p3;// the max Num of points that can  a figure take ..
	// firstly  knowing what is the sort of the selected figure .. 
	/* here that coordinates of the selected figure will be taken
	a new figure will be inserted in the clipboard.. */
	if (dynamic_cast<CRectangle*>(selcted))
	{
		
		p1 =static_cast<CRectangle*>(pManager->GetSelected())->GetC1();
		p2=static_cast<CRectangle*>(pManager->GetSelected())->GetC2();
		clipo=new CRectangle(p1,p2,pManager->GetSelected()->GetFiginfo(),pManager->GetFigureCount() + 1) ;	
	}
	else if (dynamic_cast<CTriangle*>(selcted))
	{
		p1=static_cast<CTriangle*>(pManager->GetSelected())->GetV1();
		p2=static_cast<CTriangle*>(pManager->GetSelected())->GetV2();
		p3=static_cast<CTriangle*>(pManager->GetSelected())->GetV3();
		clipo = new CTriangle(p1, p2, p3, pManager->GetSelected()->GetFiginfo(), pManager->GetFigureCount() + 1);
	}
	else if (dynamic_cast<CEllipse*>(selcted))
	{
		p1=static_cast<CEllipse*>(pManager->GetSelected())->GetCenter();
		clipo=new CEllipse(p1,pManager->GetSelected()->GetFiginfo(),pManager->GetFigureCount() + 1) ;
	}
	else if (dynamic_cast<CLine*>(selcted))
	{
		p1=static_cast<CLine*>(pManager->GetSelected())->Getstart();
		p2=static_cast<CLine*>(pManager->GetSelected())->Getend();
		clipo = new CLine(p1, p2, pManager->GetSelected()->GetFiginfo(), pManager->GetFigureCount() + 1);
	}
	else if (dynamic_cast<CRhombus*>(selcted))
	{
		p1=static_cast<CRhombus*>(pManager->GetSelected())->GetCenter();
		clipo=new CRhombus(p1,pManager->GetSelected()->GetFiginfo(),pManager->GetFigureCount() + 1) ;
	}
	else 
	{
		pManager->GetOutput()->PrintMessage("No figure was selected.");// if the selected figure == NULL 
		return ;
	}
	// the first cut /copy .. 
	if (pManager->GetClipboard()==NULL)
	{
		clipo->ChngDrawClr((pManager->GetSelected())->GetFiginfo().DrawClr) ;//it take the Draw 
		if (pManager->GetSelected()->GetFiginfo().isFilled != true);
			clipo->ChngFillClr((pManager->GetSelected())->GetFiginfo().FillClr) ;
			pManager->SetClipboard(clipo);
		// it has no action in the copy but it has action it the the cut 
		pManager->UnSelect(pManager->GetSelected());
		return ;
	}
	else 
	{
		// then it will loop on the figure list   to find  if the pervious operation was copy or cut  ..
		for (int i =0 ;i<pManager->GetFigureCount();i++)		
		{
			if (pManager->GetFigure(i)->GetFiginfo().DrawClr==GRAY||(pManager->GetFigure(i)->GetFiginfo().FillClr==GRAY))
			{
				/*if the figure contain a  gray figure  and the user click on cut or copy it will give the gray figure 
				  its perivous colors */ 
				pManager->GetFigure(i)->ChngDrawClr(pManager->GetClipboard()->GetFiginfo().DrawClr) ; 
				if (pManager->GetClipboard()->GetFiginfo().isFilled == false)
				{
					// if the clipboard was not filled the figure will take the BAckground clolor  it will be haneld in the drawing 
					pManager->GetFigure(i)->ChngFillClr(UI.BkGrndColor);
				}
				else 
				{
					pManager->GetFigure(i)->ChngFillClr(pManager->GetClipboard()->GetFiginfo().FillClr);
					// it will take its pervoius fill color 
				}
				clipo->ChngDrawClr((pManager->GetSelected())->GetFiginfo().DrawClr) ;// then the new clipbord will be inserted 
				if (pManager->GetSelected()->GetFiginfo().isFilled==true)
					clipo->ChngFillClr(pManager->GetSelected()->GetFiginfo().FillClr) ;
				pManager->SetClipboard(clipo) ;// set the clipboard 
				pManager->UnSelect(pManager->GetSelected());// un select the selcted figure 
				return ;
			}
		}
	}
	// this code  for (if  it exits form the loop without finding the any gray figure ) 
	clipo->ChngDrawClr((pManager->GetSelected())->GetFiginfo().DrawClr) ;
	if (pManager->GetSelected()->GetFiginfo().isFilled==true)
		clipo->ChngFillClr((pManager->GetSelected())->GetFiginfo().FillClr) ;
	pManager->SetClipboard(clipo) ;
	pManager->UnSelect(pManager->GetSelected());
}
void CopyAction::ReadActionParameters(){}
