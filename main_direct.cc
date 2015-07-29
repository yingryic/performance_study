#include "./TestVec.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./test.cpp"


int main() {
  float tDirect=0;
  TestTimings< TestVector4_Direct >();
  TestTimings< TestVector4_Direct >();
  for (int i=0; i<100; ++i)
    tDirect += TestTimings< TestVector4_Direct >();
  printf( "time use by using direct function call for one iteration: %.3f ms\n", tDirect/100*1000 );
}
