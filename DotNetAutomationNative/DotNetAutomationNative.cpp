// DotNetAutomationNative.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "DotNetAutomationNative.h"

#include <string>
#include "../AppPartOps/Journaling_Session.h"



extern void DotNet_automationapi_Session_InitializeSession(void)
{
	// TODO 
}



extern int DotNet_automationapi_Session_MakePart(char* partPath)
{
	std::string partFilePath = std::string(partPath);
	int guid = 0;

	Application::PartFile* partFile = Journaling_Session_MakePart(partFilePath);

	guid = partFile->GetGuid();

	return guid;
}

void DotNet_automationapi_Part_Save(int guid)
{
	
}
