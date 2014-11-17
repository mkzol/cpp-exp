#include <stdio.h>
void f(const int* p) {
 (*p)++;
}
int main() {
  int i=5;
  f(&i);
  printf("%d\n", i);
  return 0;
}
