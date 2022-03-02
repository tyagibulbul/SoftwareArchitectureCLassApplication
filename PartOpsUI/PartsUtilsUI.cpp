#include "PartsUtilsUI.h"
#include <iostream>
#include "..\AppPartOps\PartOps.h"

void SavePartUI(PartFile* partFile)
{
	std::cout << "SavePartUI was called" << std::endl;
	
	Journaling_Part_Save(partFile);
	
}

PartFile* MakePartUI(std::string s)
{
	std::cout << "MakePartUI was called with args " << s << std::endl;

	return Journaling_MakePart(s);


}

PartFile* OpenPartUI(std::string s)
{
	std::cout << "OpenPartUI was called with args " << s << std::endl;

	return Journaling_OpenPart(s);

}

