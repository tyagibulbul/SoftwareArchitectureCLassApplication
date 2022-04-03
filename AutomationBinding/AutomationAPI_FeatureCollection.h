#pragma once
#include "AutomationBindingExports.h"
namespace AutomationAPI
{
	class BlockBuilder;
	class Block;
	/// <summary>
	/// FeatureCollection comment
	/// </summary>
	class AUTOMATIONBINDING_API FeatureCollection
	{
		public:
			FeatureCollection(int guid);

			virtual ~FeatureCollection();

			BlockBuilder* CreateBlockBuilder(Block* block);


		private:
			int m_guid;
	};
}
