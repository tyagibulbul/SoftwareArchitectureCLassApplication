#pragma once
#include "AutomationBindingExports.h"
#include "ICADObject.h"

namespace AutomationAPI
{
	/// <summary>
	/// CADObject comment
	/// </summary>
	class CADObject : ICADObject
	{
		public:
			int GetGuid() override;

	};
}
