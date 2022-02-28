#include "JournalCallParamDataClass.h"
#include "JournalingInternal.h"
#include "JournalFile.h"
#include "..\Core\GuidObject.h"

JournalCallParamDataClass::JournalCallParamDataClass(std::string paramName, ParameterMetaType paramType,
    GuidObject* classObject, std::string className) :
    JournalCallParamData(paramName, paramType, JournalCallParamData::ParameterBasicType::STRING), m_classObject(classObject),
    m_paramName(paramName), m_className(className)
{

}

void JournalCallParamDataClass::Journal()
{


    if (this->m_paramType == JournalCallParamData::ParameterMetaType::INPUT)
    {

        throw new std::exception("NIY ");
    }
    else if (this->m_paramType == JournalCallParamData::ParameterMetaType::OUTPUT)
    {
        throw new std::exception("NIY ");
    }
    else // RETURN
    {
        std::string paramName;

        if (!InGuidToParamMap(this->m_classObject->GetGuid()))
        {
            paramName = GenerateParamaterName(m_paramName);
            AddGuidToParamMap(this->m_classObject->GetGuid(), paramName);

            std::string jnlString = m_className + " * " + paramName + " = ";
            GetActiveJournalFile()->WriteToFile(jnlString);
        }
        else
        {
            paramName = GetGuidToParam(this->m_classObject->GetGuid());
            //from a query method called multiple times

            std::string jnlString = paramName + " = ";
            GetActiveJournalFile()->WriteToFile(jnlString);

        }




    }

}