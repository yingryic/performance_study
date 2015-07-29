#define ARRAY_SIZE 1024
#define TEST_ITERATIONS 1000

template <class T>
void InitWithRandom( T *ptr, int num )
{
  while( num > 0 )
    {
      ptr->SetX( (double)rand()/RAND_MAX);
      ptr->SetY( (double)rand()/RAND_MAX);
      ptr->SetZ( (double)rand()/RAND_MAX);
      ptr->SetW( (double)rand()/RAND_MAX);
      ++ptr;
      --num;
    }
}

template <class T>
void SumTest( T * __restrict__ in1, T * __restrict__ in2, T *__restrict__ out, const int num )
{
  for ( int i = 0; i < num ; ++i )
    {
      out[i].SetX( in1[i].GetX() + in2[i].GetX() );
      out[i].SetY( in1[i].GetY() + in2[i].GetY() );
      out[i].SetZ( in1[i].GetZ() + in2[i].GetZ() );
      out[i].SetW( in1[i].GetW() + in2[i].GetW() );
    }
}

template <class T>
float TestTimings( )
{
  // set up input and output and preheat the cache
  T A[ ARRAY_SIZE ];
  T B[ ARRAY_SIZE ];
  T C[ ARRAY_SIZE ];

  InitWithRandom( A , ARRAY_SIZE );
  InitWithRandom( B , ARRAY_SIZE );
  InitWithRandom( C , ARRAY_SIZE );
  clock_t t;

  double retval = 0;
  //CFastTimer t1;
  int dontOptimizeThisLoopToNothing = 0;
  for ( int i = 0 ; i < TEST_ITERATIONS ; ++i )
    {
      t=clock();
      SumTest( A, B, C, ARRAY_SIZE );
      t=clock()-t;
      retval += (float)t/CLOCKS_PER_SEC;
      dontOptimizeThisLoopToNothing  += i;
    }
  // force compiler to actually use the data so it doesn't vanish the loop above
  float ac = 0;
  for ( int i = 0 ; i < ARRAY_SIZE ; ++i )
    {
      ac += C[i].GetX();
      ac += C[i].GetY();
      ac += C[i].GetZ();
      ac += C[i].GetW();
    }
  printf( "%f %dn\n", ac, dontOptimizeThisLoopToNothing); // just ignore these
  return retval ;
}
