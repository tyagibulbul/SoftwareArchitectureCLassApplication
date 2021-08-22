#pragma once
#include "AutomationBinding.h"
namespace AutomationAPI
{
	class CADObject;

	class AUTOMATIONBINDING_API IBuilder
	{
		/**
		* Commit the builder
		*/
		virtual CADObject * Commit() = 0;
	};
}
