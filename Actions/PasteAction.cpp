#include "PasteAction.h"
#include"..\ApplicationManager.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\Cline.h"
PasteAction::PasteAction(ApplicationManager *App):Action(App){}


PasteAction::~PasteAction(void)
{
}
void PasteAction::Execute()
{
	(pManager->GetInput())->GetPointClicked(p1.x,p1.y) ;// the center of the new shape 
	GfxInfo GFinfo;
	CFigure* clipo=pManager->GetClipboard() ;
	Point corner1 ,corner2,corner3,center ;
	 //firstly  it will detect the figure 
	if (dynamic_cast<CRectangle*>(clipo))
	{
		// it get the figure coordinates by the center 
		center.x=((static_cast<CRectangle*>(pManager->GetClipboard())->GetC1()).x+(static_cast<CRectangle*>(pManager->GetClipboard())->GetC2()).x)/2;
		center.y=((static_cast<CRectangle*>(pManager->GetClipboard())->GetC1()).y+(static_cast<CRectangle*>(pManager->GetClipboard())->GetC2()).y)/2;
		int  diffx =(p1.x-center.x);
		int  diffy =(p1.y-center.y);
		corner1.x=((static_cast<CRectangle*>(pManager->GetClipboard())->GetC1()).x)+diffx ;
		corner1.y=((static_cast<CRectangle*>(pManager->GetClipboard())->GetC1()).y)+diffy ;
		corner2.x=((static_cast<CRectangle*>(pManager->GetClipboard())->GetC2()).x)+diffx ;
		corner2.y=((static_cast<CRectangle*>(pManager->GetClipboard())->GetC2()).y)+diffy ;
		if (!Pointcheck(corner1))// check point 
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		if (!Pointcheck(corner2))
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		GFinfo.DrawClr=pManager->GetClipboard()->GetFiginfo().DrawClr ;
		if (pManager->GetClipboard()->GetFiginfo().isFilled!=true)
		{
				GFinfo.isFilled=false ;
		}
		else 
		{
			GFinfo.isFilled=true ;
			GFinfo.FillClr=pManager->GetClipboard()->GetFiginfo().FillClr ;
		}

		CRectangle *R=new CRectangle(corner2,corner1 , GFinfo, pManager->GetFigureCount() + 1);
		pManager->AddFigure(R);
	}
	else if (dynamic_cast<CEllipse*>(clipo))
	{ // the same as the pervious shape 
		GFinfo.DrawClr=pManager->GetClipboard()->GetFiginfo().DrawClr ;
		if (pManager->GetClipboard()->GetFiginfo().isFilled!=true)
			{
				GFinfo.isFilled=false ;
			}
		else 
		{
			GFinfo.isFilled=true ;
			GFinfo.FillClr=pManager->GetClipboard()->GetFiginfo().FillClr ;
		}
		if (!RhoElliPointCheck(p1))
		{
			pManager->GetOutput()->PrintMessage("you can't paste in this place.");
			return ;
		}
		CEllipse*E=new CEllipse(p1,GFinfo, pManager->GetFigureCount() + 1) ;
		pManager->AddFigure(E) ;
	}
	else if (dynamic_cast<CRhombus*>(clipo))
	{
		// the same as the pervious shape 
		GFinfo.DrawClr=pManager->GetClipboard()->GetFiginfo().DrawClr ;
		if (pManager->GetClipboard()->GetFiginfo().isFilled!=true)
			{
				GFinfo.isFilled=false ;
			}
		else 
		{
			GFinfo.isFilled=true ;
			GFinfo.FillClr=pManager->GetClipboard()->GetFiginfo().FillClr ;
		}
		if (!RhoElliPointCheck(p1))
		{
			pManager->GetOutput()->PrintMessage("you can't paste in this place.");
			return ;
		}
		CRhombus*H=new CRhombus(p1,GFinfo, pManager->GetFigureCount() + 1) ;
		pManager->AddFigure(H);
	}
	else if (dynamic_cast<CLine*>(clipo))
	{
		// the same as the pervious shape 
		center.x=((static_cast<CLine*>(pManager->GetClipboard())->Getstart()).x+(static_cast<CLine*>(pManager->GetClipboard())->Getend()).x)/2;
		center.y=((static_cast<CLine*>(pManager->GetClipboard())->Getstart()).y+(static_cast<CLine*>(pManager->GetClipboard())->Getend()).y)/2;
		int  diffx =(p1.x-center.x);
		int  diffy =(p1.y-center.y);
		corner1.x=((static_cast<CLine*>(pManager->GetClipboard())->Getstart()).x)+diffx ;
		corner1.y=((static_cast<CLine*>(pManager->GetClipboard())->Getstart()).y)+diffy ;
		corner2.x=((static_cast<CLine*>(pManager->GetClipboard())->Getend()).x)+diffx ;
		corner2.y=((static_cast<CLine*>(pManager->GetClipboard())->Getend()).y)+diffy ;
		if (!Pointcheck(corner1))
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		if (!Pointcheck(corner2))
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		GFinfo.DrawClr=pManager->GetClipboard()->GetFiginfo().DrawClr ;
		if (pManager->GetClipboard()->GetFiginfo().isFilled!=true)
		{
			GFinfo.isFilled=false ;
		}
		else 
		{
			GFinfo.isFilled=true ;
			GFinfo.FillClr=pManager->GetClipboard()->GetFiginfo().FillClr ;
		}
		CLine * L=new CLine(corner1, corner2, GFinfo, pManager->GetFigureCount() + 1);
		pManager->AddFigure(L);
	}
	else 
	{
		// the same as the pervious shape 
		center.x=((static_cast<CTriangle*>(pManager->GetClipboard())->GetV1().x)+(static_cast<CTriangle*>(pManager->GetClipboard())->GetV2().x)+(static_cast<CTriangle*>(pManager->GetClipboard())->GetV3().x))/3 ;
		center.y=((static_cast<CTriangle*>(pManager->GetClipboard())->GetV1().y)+(static_cast<CTriangle*>(pManager->GetClipboard())->GetV2().y)+(static_cast<CTriangle*>(pManager->GetClipboard())->GetV3().y))/3 ;
		int  diffx =(p1.x-center.x);
		int  diffy =(p1.y-center.y);
		corner1.x=(static_cast<CTriangle*>(pManager->GetClipboard())->GetV1().x)+diffx ;
		corner1.y=(static_cast<CTriangle*>(pManager->GetClipboard())->GetV1().y)+diffy ;
		corner2.x=(static_cast<CTriangle*>(pManager->GetClipboard())->GetV2().x)+diffx ;
		corner2.y=(static_cast<CTriangle*>(pManager->GetClipboard())->GetV2().y)+diffy ;
		corner3.x=(static_cast<CTriangle*>(pManager->GetClipboard())->GetV3().x)+diffx ;
		corner3.y=(static_cast<CTriangle*>(pManager->GetClipboard())->GetV3().y)+diffy ;
		if (!Pointcheck(corner1))
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		if (!Pointcheck(corner2))
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		if (!Pointcheck(corner2))
		{
			pManager->GetOutput()->PrintMessage("you can't paste here ") ;
			return ;
		}
		GFinfo.DrawClr=pManager->GetClipboard()->GetFiginfo().DrawClr ;
		if (pManager->GetClipboard()->GetFiginfo().isFilled!=true)
			{
				GFinfo.isFilled=false ;
			}
		else 
		{
			GFinfo.isFilled=true ;
			GFinfo.FillClr=pManager->GetClipboard()->GetFiginfo().FillClr ;
		}
		CTriangle*T=new CTriangle(corner1,corner2,corner3,GFinfo, pManager->GetFigureCount() + 1) ;
		pManager->AddFigure(T) ;
	}
	for (int i =0 ;i<pManager->GetFigureCount();i++)
	{
		// if the clipbodrd was inserted in cut operetion the grasy figure will removed 
		if((pManager->GetFigure(i))->GetFiginfo().FillClr==GRAY)
		{
			pManager->removeafigure(pManager->GetFigure(i)) ;
			pManager->UnSelect(pManager->GetSelected());
		}
	}
}
void PasteAction::ReadActionParameters(){}

bool PasteAction::Pointcheck(Point p)
{
	if (p.y >= UI.ToolBarHeight && p.y < UI.height - UI.StatusBarHeight)
		return true;
	return false;
}

bool PasteAction::RhoElliPointCheck(Point p)
{
	if ((p.y - 51 >= UI.ToolBarHeight && p.y + 51 < UI.height - UI.StatusBarHeight) && (p.x - 110 >= 0 && p.x + 110< UI.width))
		return true;
	return false;

}
