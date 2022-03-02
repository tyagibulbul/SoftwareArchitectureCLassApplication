#include "MakeWidgetFeature.h"
#include <iostream>
#include "..\AppPartOps\PartOps.h"


void AddWidgetFeatureToPartUI(PartFile* partFile, bool option1, int values)
{
	std::cout << "AddWidgetFeatureToPartUI was called " << option1 << " " << values << std::endl;
	Journaling_Part_MakeWidgetFeature(partFile, option1, values);

}
