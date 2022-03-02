#pragma once

#include "AutomationBindingExports.h"
#include <string>


namespace AutomationAPI
{

	class FeatureCollection;

	class AUTOMATIONBINDING_API Part
	{
		public :

			/**
			* <summary>Saves the Part File.</summary>  More commetns and details blah blah blah
			*/
			void Save();

			/**
			* <summary>Makes a Widget Feature</summary> Even More commetns and details blah blah blah
			*/
			void MakeWidgetFeature(bool option1, int values);

			/**
			* Returns the Feature collection for the part.
			*/
			FeatureCollection* Features();

			/*
			* Internal Usage only.
			*/
			static Part* CreatePart(int guid);

			virtual ~Part();

		private:
			Part();
			Part(int guid);
			int m_guid;
			FeatureCollection * m_featureCollection;

	};

}
