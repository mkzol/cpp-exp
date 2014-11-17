#include <stdio.h>
void f(int& p) {
 p++;
}
int main() {
  int i=5;
  f(i);
  printf("%d\n", i);
  return 0;
}
