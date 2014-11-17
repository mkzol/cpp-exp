#include <string.h>
#include <stdio.h>
#include "kv.hpp"

//#define D(x,...) printf(x)
#define D(x,...)

/*
const char *get_nth_value(
	const char *msg,
	const unsigned int msg_size,
	const unsigned int n) {
const char *cur_p = msg;
 unsigned int idx=0;
 unsigned short len_v;
 printf("%d<%d %d<%d\n", cur_p - msg + 4, msg_size, idx,n);
 while ((cur_p - msg + 4 < msg_size) && idx < n) {
   cur_p += 2;
   len_v = *((short *)cur_p);
   D("len @ %p = %d\n",cur_p, len_v);
   cur_p += 2 + len_v;
   idx++;
 }
 if (msg_size < cur_p - msg +4) {
   D("null 1\n");
   return nullptr;
 }
 cur_p += 2;
 len_v = *((short *)cur_p);
 if (cur_p - msg + len_v + 2 > msg_size) {
   D("null 2\n");
   return nullptr;
 }
 D("yo\n");
 return cur_p;
}
*/


char *add_rec(const char *data, char *dst) {
  printf("%p ",dst);
  unsigned short len=0x1234;
  memcpy(dst, &len,sizeof(len));
  dst+=2;
  len=strlen(data);
  memcpy(dst+2,data,len);
  memcpy(dst,&len,sizeof(len));
  dst += len + 2;
  printf("-(%d)->%p\n",len,dst);
  return dst;
}

int main() {
  char tab[1000], *p;
  const char *z;
  unsigned short l;

  p = tab;
  p = add_rec("aaaaaaaa",p);
  p = add_rec("bbbbbbb",p);
  p = add_rec("ccccccccc",p);
  p = add_rec("dddddddddddd",p);
  p = add_rec("eeeeeeee",p);
  z = add_rec("ffffffff",p);
  l = z - tab;
  printf("0: %p / %d\n", tab,l);
  z = get_nth_value( tab, l, 4);
  printf("4: %p\n", z);
  z = get_nth_value( tab, l, 7);
  printf("7: %p\n", z);
  
}
