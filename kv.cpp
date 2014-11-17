#include <stdio.h>

const char *get_nth_value(const char *msg, const unsigned int msg_size,  const unsigned int n) {  const char *p0 = msg,
            *cur_p = p0;
 unsigned int idx=0;
 unsigned short len_v;
 while ((cur_p + 4 - p0 > msg_size) && idx < n) {
   cur_p += 2;
   len_v = *((short *)cur_p);
   printf("len @ %p = %d\n",cur_p, len_v);
   cur_p += 2 + len_v;
   idx++;
 }
 if (cur_p + 4 - p0 > msg_size) {
   return nullptr;
 }
 cur_p += 2;
 len_v = *((short *)cur_p);
 if (cur_p + len_v + 2 - p0 > msg_size) {
   return nullptr;
 }
 return cur_p+2;
}
