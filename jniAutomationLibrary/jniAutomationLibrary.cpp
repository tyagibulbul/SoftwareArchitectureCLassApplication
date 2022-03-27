// jniAutomationLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "jniAutomationLibrary.h"
#include "..\FakeAutomationJava\FakeAutomationJava.h"
#include "..\AppPartOps\PartOps.h"
#include "..\Core\CoreUtils.h"
#include <string>
#include <iostream>

JNIEXPORT jstring JNICALL Java_FakeAutomationJava_DoSomeStuff
(JNIEnv* env, jobject obj, jint intVal, jstring strVal)
{
	jstring retVal = nullptr;

	std::string stringToBuild;

	int val = (int)intVal;

	stringToBuild = std::to_string(val);
	stringToBuild += " ";
	const char* nameCharPointer = env->GetStringUTFChars(strVal, NULL);
	stringToBuild += nameCharPointer;

	// TO give a sample of what we woudl call

	PartFile* partFile = Journaling_OpenPart(BasePath() + "\\SampleVersionUp.prt");

	int guid = partFile->GetGuid();


	retVal = env->NewStringUTF(stringToBuild.c_str());

	std::cout << "From Native " << stringToBuild << std::endl;

	return retVal;
}
