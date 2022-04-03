#pragma once

#include "AppFeaturesOpsExports.h"
#include "..\Core\GuidObject.h"
#include <iostream>
#include <fstream>

static std::string FeatureToken = "Feature:";
static std::string EndFeatureToken = "EndFeature";


APPLIBRARY_API void ProcessFeature(std::string featureType, std::ifstream& streamObject);

namespace Application
{
	class APPLIBRARY_API Feature : public GuidObject
	{
		public:
			Feature() = delete;
			Feature(int guid) : GuidObject(guid)
			{

			}


	};
}

