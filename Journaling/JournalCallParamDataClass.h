#pragma once
#include <string>
#include "JournalCallParamData.h"

class GuidObject;

class JournalCallParamDataClass : public JournalCallParamData
{
public:


	JournalCallParamDataClass(std::string paramName,
		ParameterMetaType paramType, GuidObject* classObject, std::string className);

	void Journal() override;

private:
	JournalCallParamDataClass() = delete;
	JournalCallParamDataClass(const JournalCallParamDataClass&) = delete;
	JournalCallParamDataClass& operator=(const JournalCallParamDataClass&) = delete;
	GuidObject* m_classObject;
	std::string m_paramName;
	std::string m_className;
};

