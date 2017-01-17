//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#include "CNTKLibrary.h"
#include <functional>
#include "Common.h"

using namespace CNTK;

void TrainCifarResnet();

int main()
{
#if defined(_MSC_VER)
    // in case of asserts in debug mode, print the message into stderr and throw exception
    if (_CrtSetReportHook2(_CRT_RPTHOOK_INSTALL, HandleDebugAssert) == -1) {
        fprintf(stderr, "_CrtSetReportHook2 failed.\n");
        return -1;
    }
#endif

    if (IsGPUAvailable())
    {
        fprintf(stderr, "Run test on a GPU device.\n");
        // Lets disable automatic unpacking of PackedValue object to detect any accidental unpacking
        // which will have a silent performance degradation otherwise
        Internal::SetAutomaticUnpackingOfPackedValues(/*disable =*/ true);

        TrainCifarResnet();
    }
    else
    {
        fprintf(stderr, "Cannot run TrainCifarResnet test on a CPU device.\n");
    }

    fprintf(stderr, "\nCNTKv2Library-CifarResNet tests: Passed\n");
    fflush(stderr);

#if defined(_MSC_VER)
    _CrtSetReportHook2(_CRT_RPTHOOK_REMOVE, HandleDebugAssert);
#endif
}
