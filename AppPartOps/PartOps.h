#pragma once
#include "AppPartOpsExports.h"
#include <string>
#include "..\Core\GuidObject.h"



class APPPARTOPS_API PartFile : public GuidObject
{
	public:
		static PartFile* CreatePartFile(std::string partFilePath);
		static PartFile* OpenPartFile(std::string partFilePath);
		void SavePart();
		void ClosePart();
		void MakeWidgetFeature(bool option1, int values);

	private:
		PartFile(std::string partFilePath, int guid);
		std::string m_partFilePath;
};

extern APPPARTOPS_API PartFile* Journaling_MakePart(std::string);

extern APPPARTOPS_API PartFile* Journaling_OpenPart(std::string);

extern APPPARTOPS_API void Journaling_Part_Save(PartFile* partFile);

extern APPPARTOPS_API void Journaling_Part_MakeWidgetFeature(PartFile* partFile, bool option1, int values);



