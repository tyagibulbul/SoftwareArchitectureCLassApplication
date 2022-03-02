#pragma once
#include "AutomationBindingExports.h"
#include "ICADObject.h"

namespace AutomationAPI
{
	class CADObject : ICADObject
	{
		public:
			int GetGuid() override;

	};
}
