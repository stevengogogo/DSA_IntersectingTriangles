#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_intersects.h"




// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"Create paths", create_paths},
    {NULL, NULL} // Terminate the test
};