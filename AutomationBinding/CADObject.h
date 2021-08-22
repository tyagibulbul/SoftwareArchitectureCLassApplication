#pragma once
#include "AutomationBinding.h"
#include "ICADObject.h"

namespace AutomationAPI
{
	class CADObject : ICADObject
	{
		public:
			int GetGuid() override;

	};
}
