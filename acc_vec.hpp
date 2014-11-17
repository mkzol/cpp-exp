// Accelerated C++, Koening & Moo, A&W, 2000, chap XI
#include <memory>

template <class T>
class Vec {
  public:
    typedef const T* const_iterator;
    typedef T* iterator;
    typedef T value_type;
    typedef size_t size_type;

    iterator begin() { return data; };
    const_iterator begin() const { return data; };
    iterator end() { return avail; };
    const_iterator end() const {return avail; };
    size_type size() const { return avail - data; };
    void push_back(const value_type e) {
      if (avail == limit)
        grow();
      unchecked_append(e);
    };
#ifdef VEC_STATS
  unsigned int get_n_copy() const { return n_copy; }
  unsigned int get_n_create() const { return n_create; }
  unsigned int get_n_destroy() const { return n_destroy; }
  unsigned int get_n_assign() const { return n_assign; }
  unsigned int get_n_grow() const { return n_grow; }
#endif

    Vec() { create();
#ifdef VEC_STATS
  n_create++;
#endif
}
    explicit Vec(const size_t n, const value_type elt0 = T()) {
      create(n, elt0);
#ifdef VEC_STATS
  n_create++;
#endif
};
    Vec(const Vec& v) { create(v); 
#ifdef VEC_STATS
  n_copy++;
#endif
}
    Vec& operator=(const Vec& v)
    {
      if (&v != this) {
        uncreate();
        create(v);
      }
#ifdef VEC_STATS
      n_assign++;
#endif
      return *this;
    };

    ~Vec() { uncreate();
#ifdef VEC_STATS
  n_destroy++;
#endif
};

    value_type operator[](size_type n) { return data[n]; }
    const value_type operator[](size_type n) const { return data[n]; }

  private:
#ifdef VEC_STATS
  static unsigned int n_copy = 0;
  static unsigned int n_assign = 0;
  static unsigned int n_create = 0;
  static unsigned int n_destroy = 0;
  static unsigned int n_grow = 0;
#endif
    iterator data;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;
    void create();
    void create(const size_t n, const value_type elt0);
    void create(const_iterator beg, const_iterator end);
    void uncreate();
    void unchecked_append(const value_type e);
    void grow();
};

template <class T>
void Vec<T>::create() { data = avail = limit = 0; }

template <class T>
void Vec<T>::create(const size_t n, const value_type elt0) 
{
  data = alloc.allocate(n);
  avail = limit = data + n;
  uninitialized_fill(data, avail, elt0);
}

template <class T>
void Vec<T>::create(const_iterator beg, const_iterator end)
{
  data = alloc.allocate(end - beg);
  avail = limit = uninitialized_copy(beg, end, data);
}

template <class T>
void Vec<T>::uncreate()
{
  if (data) {
    iterator it = avail;
    while (it != data)
      alloc.destroy(--it);
  alloc.deallocate(data, limit = data);
  }
  data = limit = avail = 0;
}
/*
*/
template <class T>
void Vec<T>::unchecked_append(const value_type e)
{
  alloc.construct(avail++, e);
}

template <class T>
void Vec<T>::grow()
{
  size_type new_size = max(std::ptrdiff_t(1),(limit - data) * 2);
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = uninitialized_copy(data, avail, new_data);
  uncreate();
  data = new_data;
  avail = new_avail;
  limit = data + new_size;
#ifdef VEC_STATS
  n_grow++;
#endif
}
