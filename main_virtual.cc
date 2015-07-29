#include "./TestVec.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./test.cpp"


int main() {
  float tVirt =0;
  TestTimings< TestVector4_Virtual >();

  for (int i=0; i<100; ++i)
    tVirt += TestTimings< TestVector4_Virtual >();

  printf( "time use by using virtual function call for one iteration: %.3f ms\n", tVirt/100*1000 );
}
