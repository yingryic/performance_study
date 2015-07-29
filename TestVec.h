class TestVector4_Virtual
{
 public:
  virtual float GetX() const;
  virtual float SetX( float in );
  virtual float GetY() const;
  virtual float SetY( float in );
  virtual float GetZ() const;
  virtual float SetZ( float in );
  virtual float GetW() const;
  virtual float SetW( float in );
 private:
  float x,y,z,w;
};

class TestVector4_Direct
{
 public:
  __attribute__((noinline)) float GetX() const;
  __attribute__((noinline)) float SetX( float in );
  __attribute__((noinline)) float GetY() const;
  __attribute__((noinline)) float SetY( float in );
  __attribute__((noinline)) float GetZ() const;
  __attribute__((noinline)) float SetZ( float in );
  __attribute__((noinline)) float GetW() const;
  __attribute__((noinline)) float SetW( float in );
 private:
  float x,y,z,w;
};

class TestVector4_Inline
{
 public:
  inline float GetX() const;
  inline float SetX( float in );
  inline float GetY() const;
  inline float SetY( float in);
  inline float GetZ() const;
  inline float SetZ( float in );
  inline float GetW() const;
  inline float SetW( float in);
 private:
  float x,y,z,w;
};

inline float TestVector4_Inline::GetX() const
{
  return x;
}
inline float TestVector4_Inline::SetX( float in )
{
  return x = in;
}

inline float TestVector4_Inline::GetY() const
{
  return y;
}
inline float TestVector4_Inline::SetY( float in )
{
  return y = in;
}

inline float TestVector4_Inline::GetZ() const
{
  return z;
}
inline float TestVector4_Inline::SetZ( float in )
{
  return z = in;
}

inline float TestVector4_Inline::GetW() const
{
  return w;
}
inline float TestVector4_Inline::SetW( float in )
{
  return w = in;
}
