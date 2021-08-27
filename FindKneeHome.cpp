//============================================================================
// Name        : FindKneeHome.cpp
// Author      : Pedro Fabriz
// Version     : v1
// Description : Find Knee Zero position
//============================================================================

#include <iostream>
#include "Definitions.h"
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/times.h>
#include <sys/time.h>

typedef void* HANDLE;
typedef int BOOL;

using namespace std;

const string g_programName = "SherlockHoming";

#ifndef MMC_SUCCESS
	#define MMC_SUCCESS 0
#endif

#ifndef MMC_FAILED
	#define MMC_FAILED 1
#endif

//LogError: print the error if exists.
void LogError(string functionName, int Result, unsigned int ErrorCode)
{
	cerr << g_programName << ": " << functionName << " failed (result=" << Result << ", errorCode=0x" << std::hex << ErrorCode << ")"<< endl;
}

//OpenEPOS: recognizes the EPOS connected to the microcontroler.
int OpenEPOS(unsigned int *ErrorCode)
{
    int Result = MMC_FAILED;
    unsigned int *ErrorCode = 0;
    char *DeviceName = "EPOS4";
    char *ProtocolStackName = "MAXON SERIAL V2";
    char *InterfaceName = "USB";
    char *PortName = "USB0";
    void* KeyHandle = 0;

    KeyHandle = VCS_OpenDevice(DeviceName, ProtocolStackName, InterfaceName, PortName, ErrorCode);

    if (*ErrorCode == 0){
        Result = MMC_SUCCESS;
        cout << "Your EPOS is connected!!!" << "\n";
    }

    return Result;
}

//FindLimits: Search for the limit of the prosthesis and them asks for distance in (°) desired for homing
int FindLimits(unsigned int *ErrorCode)
{

}

int main(int argc, char** argv) {

    int lResult = MMC_FAILED;
	unsigned int ErrorCode = 0;

    if((lResult = OpenEPOS(&ErrorCode))!=MMC_SUCCESS)
    {
        LogError("OpenDevice", lResult, ErrorCode);
        return lResult;
    }

    if((lResult = FindLimits(&ErrorCode))!=MMC_SUCCESS)
    {
        LogError("OpenDevice", lResult, ErrorCode);
        return lResult;
    }

    cout << "Sherlock is done!" << "\n";
    return lResult;


}
