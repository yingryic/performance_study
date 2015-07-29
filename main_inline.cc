#include "./TestVec.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./test.cpp"

int main() {
  float tInline=0;
  TestTimings< TestVector4_Inline >();
  for (int i=0; i<100; ++i)
    tInline += TestTimings< TestVector4_Inline >();
  printf( "time use by using inline function call for one iteration: %.3f ms\n", tInline/100*1000);
}
