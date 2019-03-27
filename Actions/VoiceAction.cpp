#include "VoiceAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

VoiceAction::VoiceAction(ApplicationManager *pApp):Action(pApp)
{
}
void VoiceAction::ReadActionParameters()
{
	Output *pOut=pManager->GetOutput();

	if(UI.VoiceMode==SoundON)
		UI.VoiceMode=MUTE;
	else
	UI.VoiceMode=SoundON;
	pOut->CreateDrawToolBar();
}

void VoiceAction::Execute()
{
	ReadActionParameters();
	Output *pOut=pManager->GetOutput();
	if(UI.VoiceMode==SoundON)
		pOut->PrintMessage("Voice:on");
	else
		pOut->PrintMessage("Voice:Muted");
}


VoiceAction::~VoiceAction(void)
{
}
