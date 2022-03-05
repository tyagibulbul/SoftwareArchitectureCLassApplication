#pragma once
#include "AutomationBindingExports.h"
namespace AutomationAPI
{
	class WireBuilder;
	class Wire;

	class AUTOMATIONBINDING_API RoutingCollection
	{
		public:
			RoutingCollection(int guid);

			virtual ~RoutingCollection();

			WireBuilder* CreateWireBuilder(Wire* wire);


		private:
			int m_guid;
	};
}
