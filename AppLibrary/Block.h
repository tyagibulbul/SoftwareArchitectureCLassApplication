#pragma once
#include "AppFeaturesOpsExports.h"
#include "Feature.h"

#include <iostream>
#include <fstream>


void ProcessBlock(std::ifstream& streamObject);

namespace Application
{
	class APPLIBRARY_API Block : public Application::Feature
	{
		public:
			Block() = delete;
			Block(int guid) : Feature(guid)
			{

			}
	};
}

