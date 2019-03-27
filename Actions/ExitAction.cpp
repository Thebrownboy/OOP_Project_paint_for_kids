#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{
}

void ExitAction:: ReadActionParameters()
{
	Output*pOut	=pManager->GetOutput();	
	pOut->PrintMessage("Exit From Paint For Kides Hope You Enjoyed With Us  ");
}
void ExitAction:: Execute() 
{
	ReadActionParameters();
	if(UI.VoiceMode==SoundON)
		PlaySound(TEXT("Goodbye.wav"),NULL,SND_SYNC);


}


ExitAction::~ExitAction(void)
{
}

