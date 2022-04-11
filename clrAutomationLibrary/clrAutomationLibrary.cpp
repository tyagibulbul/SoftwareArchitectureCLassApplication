// clrAutomationLibrary.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "clrAutomationLibrary.h"

#include <windows.h>
#include <stdio.h>
#include <iostream>

extern float PrintOutStuff(char**& inputParams, int* numInputParams)
{
	std::cout << "PrintOutStuff called" << std::endl;

	for (int i = 0; i < *numInputParams; i++)
	{
		std::cout << "[unmanaged print]" << inputParams[i] << std::endl;
	}
	return 314;
}




