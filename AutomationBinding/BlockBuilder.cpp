#include "BlockBuilder.h"
#include "CADObject.h"



AutomationAPI::CADObject* AutomationAPI::BlockBuilder::Commit()
{
	return nullptr;
}

void AutomationAPI::BlockBuilder::SetType(BlockBuilderTypes type)
{
}

AutomationAPI::BlockBuilder::BlockBuilderTypes AutomationAPI::BlockBuilder::GetType()
{
	return AutomationAPI::BlockBuilder::TypesOriginAndEdgeLengths;
}

void AutomationAPI::BlockBuilder::SetHeight(int h)
{
}

int AutomationAPI::BlockBuilder::GetHeight()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetWidth(int w)
{
}

int AutomationAPI::BlockBuilder::GetWidth()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetDepth(int d)
{
}

int AutomationAPI::BlockBuilder::GetDepth()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetOrigin(int x, int y, int z)
{
}

void AutomationAPI::BlockBuilder::GetOrigin(int& x, int& y, int& z)
{
}
