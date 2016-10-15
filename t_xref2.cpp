#include <list>

struct I
{
  virtual void d() const =0;
};

struct B : I
{
  typedef I* Tpi; 
  Tpi pa;
  inline void d() const;
};

void B::d() const
{
  if (pa) pa -> d();
}

struct A : I
{
  typedef std::list<B> Tlb;
  Tlb lb;
  inline void d() const;
};

void A::d() const
{
  for(Tlb::const_iterator ib = lb.begin(); ib != lb.end(); ++ib)
  {
    ib -> d();
  }
}

void z()
{
  A a; B b;
  a.d();
  b.d();
}
