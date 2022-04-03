#include "Journaling_BlockBuilder.h"
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"


void Journaling_BlockBuilder_SetType(Application::BlockBuilder* blockBuilder, JournalBlockBuilderTypes type)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("SetType", blockBuilder);
		JournalIntInParam(type, "type");
	}

	blockBuilder->SetType(type);

	if (IsJournaling())
	{
		JournalEndCall();
	}

}
