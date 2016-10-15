#include <list>

struct A;
struct B
{
  typedef A* Tpa; 
  Tpa pa;
  inline void d() const;
};

struct A
{
  typedef std::list<B> Tlb;
  Tlb lb;
  inline void d() const;
};

void B::d() const
{
  if (pa) pa -> d();
}

void A::d() const
{
  for(Tlb::const_iterator ib = lb.begin(); ib != lb.end(); ++ib)
  {
    ib -> d();
  }
}
