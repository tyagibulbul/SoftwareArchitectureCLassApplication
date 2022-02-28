#pragma once

#include <string>
#include <vector>
#include "JournalingTypes.h"

class GuidObject;
class JournalCallParamData;

class JournalCallData
{
public:

	JournalCallData(std::string methodName, CannedGlobals cannedGlobals);
	JournalCallData(std::string methodName, GuidObject* classObject);
	void AddParameter(JournalCallParamData* param);
	void AddReturnValue(JournalCallParamData* param);

	virtual ~JournalCallData();

	void Journal();

private:
	JournalCallData() = delete;
	JournalCallData(const JournalCallData&) = delete;
	JournalCallData& operator=(const JournalCallData&) = delete;
	std::string m_methodName;
	std::vector<JournalCallParamData*> m_params;
	bool m_isCanned;
	GuidObject* m_classObject;
	CannedGlobals m_cannedGlobal;
	JournalCallParamData* m_retVal; // nulptr is void

};

