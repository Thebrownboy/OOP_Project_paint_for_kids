#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "CutAction.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Cline.h"
CutAction::CutAction(ApplicationManager * PApp):Action(PApp)
{
}


CutAction::~CutAction(void)
{
}
void CutAction::Execute()
{
	//before any cut operation I will make the clipboard be in its pperivious color 
	//this for if the user cut a figure then doesn't  paste it the clipboard will be retun to its fill color and the 
	//next cutted figure will become the clipboard
	CFigure*selcted =pManager->GetSelected() ;// firstly you  I  get the selected figure then  I will make actions on it .. 
	CFigure *clipo=NULL;
	GfxInfo Ginfo;// A figure that will store the clipboard ..
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
			clipo=new CTriangle(p1,p2,p3,pManager->GetSelected()->GetFiginfo(),pManager->GetFigureCount() + 1) ;
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
			clipo=new CLine(p1,p2,pManager->GetSelected()->GetFiginfo(),pManager->GetFigureCount() + 1) ;
		}
		else if (dynamic_cast<CRhombus*>(selcted))
		{
			p1=static_cast<CRhombus*>(pManager->GetSelected())->GetCenter();
			clipo=new CRhombus(p1,pManager->GetSelected()->GetFiginfo(),pManager->GetFigureCount() + 1) ;
		}
		else 
		{
			pManager->GetOutput()->PrintMessage("No figure was selected.");
			return ;
		}
		// the first cut /copy .. 
		if (pManager->GetClipboard() == NULL)//for the first time or after pasting  
		{
			// inserting the figure with its figinfo in the clipo 
			clipo->ChngDrawClr((pManager->GetSelected())->GetFiginfo().DrawClr);
			if (pManager->GetSelected()->GetFiginfo().isFilled == true)
				clipo->ChngFillClr((pManager->GetSelected())->GetFiginfo().FillClr);
			pManager->SetClipboard(clipo);
			(pManager->GetSelected())->ChngDrawClr(GRAY);
			(pManager->GetSelected())->ChngFillClr(GRAY);
			pManager->UnSelect(pManager->GetSelected());
			return;
		}
		for (int i =0 ;i<pManager->GetFigureCount();i++)		
		{
			// then it will loop on the figure list   to find  if the pervious operation was copy or cut  ..
			if (pManager->GetFigure(i)->GetFiginfo().DrawClr==GRAY||(pManager->GetFigure(i))->GetFiginfo().FillClr==GRAY)
			{

				/*if the figure contain a  gray figure  and the user click on cut or copy it will give the gray figure
				its perivous colors */
				if(pManager->GetSelected()->GetFiginfo().FillClr != GRAY)
				{ 
					// if the selected figure was ont the perivous cuteed figure 
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
					clipo->ChngDrawClr((pManager->GetSelected())->GetFiginfo().DrawClr) ;
					if (pManager->GetSelected()->GetFiginfo().isFilled == true)
						clipo->ChngFillClr(pManager->GetSelected()->GetFiginfo().FillClr) ;
					pManager->SetClipboard(clipo);// set the clipbodrd 
					(pManager->GetSelected())->ChngDrawClr(GRAY) ;// change its colors into gray 
					(pManager->GetSelected())->ChngFillClr(GRAY) ;
					pManager->UnSelect(pManager->GetSelected());
					return ;
				}
				else 
				{
					// if the selcted was gray don't do any thing 
					pManager->UnSelect(pManager->GetSelected());// unselcte the figure 
					return;
				}
			}
		}
		// if the figure list has no gray color  that means the clipboard was copied 
		clipo->ChngDrawClr((pManager->GetSelected())->GetFiginfo().DrawClr) ;
		if (pManager->GetSelected()->GetFiginfo().isFilled==true)
			clipo->ChngFillClr((pManager->GetSelected())->GetFiginfo().FillClr) ;
		pManager->SetClipboard(clipo) ;// set the clipbodrd 
		(pManager->GetSelected())->ChngDrawClr(GRAY) ;// change its cloros into gray 
		(pManager->GetSelected())->ChngFillClr(GRAY) ;
		pManager->UnSelect(pManager->GetSelected());// un selcet the figure 
	}

void CutAction::ReadActionParameters(){}
