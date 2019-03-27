#include "FrontBackAction.h"
#include"..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
	

FrontBackAction::FrontBackAction(ApplicationManager *pApp):Action(pApp)	
{
}


void FrontBackAction:: ReadActionParameters()
{

}
void FrontBackAction:: Execute() 
{
	//get input/output and declaring some variables 
	Input *pIn=pManager->GetInput();
	Output *pOut=pManager->GetOutput();
	CFigure *S;
	CFigure *D=pManager->GetSelected();
	CFigure **FS= pManager->GetFigures();
	CFigure *Temp;
	int index;

	pOut->PrintMessage("Select an overlab to bring to back or send to front");
	// check whether a there is a selected shape or no
	if(!pManager->GetSelected())
	{
		pOut->PrintMessage("No shape was selected please select a shape then try again, Choose another icon from the tool bar");
		return;
	}
	//check if the selected figure is  front or  back and if it front make it back and if it back make it front 
	if(D!=NULL)
	if(D->GetPostion()==1)
	{
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		if(FS[i] != NULL)
			if(FS[i]==D)
			{	
				S=FS[i];
				index=i;
				break;
			}

				
	}
	if(S!=NULL)
	{
		pOut->PrintMessage("Send to Front ");
		Temp=S;
		FS[index]=FS[pManager->GetFigureCount()-1];
		FS[pManager->GetFigureCount()-1]=S;
		D->SetPostion(0);

	}
	}
	else if(D->GetPostion()==0)
	{
		for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		if(FS[i] != NULL)
			if(FS[i]==D)
				{
					S=FS[i];
					index=i;
				}
	}

		if(S!=NULL)
		{
		pOut->PrintMessage("Bring to Back ");

			Temp=S;
		FS[index]=FS[0];
			FS[0]=S;
			D->SetPostion(1);
		}

	}
	if(D!=NULL)
		pManager->UnSelect(D);
		S=NULL;
		D=NULL;
		return ;




}



FrontBackAction::~FrontBackAction(void)
{
}
