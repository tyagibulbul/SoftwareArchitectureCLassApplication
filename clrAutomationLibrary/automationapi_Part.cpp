#include "automationapi_Part.h"
#include "..\AppPartOps\PartOps.h"
#include "..\AppPartOps\Journaling_Part.h"

extern void Part_Save(int guid)
{

	Application::PartFile* part = dynamic_cast<Application::PartFile*>(GuidObjectManager::GetGuidObjectManager().GetObjectFromGUID(guid));
	if (part == nullptr)
	{
		throw std::exception("not able to retrieve Part Object");
	}
	else
	{
		Journaling_Part_Save(part);
	}

}