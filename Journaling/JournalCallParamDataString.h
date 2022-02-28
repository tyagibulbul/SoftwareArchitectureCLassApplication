#pragma once

#include <string>
#include "JournalCallParamData.h"


class JournalCallParamDataString : public JournalCallParamData
{
public:


	JournalCallParamDataString(std::string paramName,
		ParameterMetaType paramType, std::string value);

	void Journal() override;

private:
	JournalCallParamDataString() = delete;
	JournalCallParamDataString(const JournalCallParamDataString&) = delete;
	JournalCallParamDataString& operator=(const JournalCallParamDataString&) = delete;
	std::string m_value;
};