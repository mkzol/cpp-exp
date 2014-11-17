#include <stdio.h>
int f(int &r) {
 r+=1;
 return 0;
}

int main() {
  int x=0;
  printf("%d\n",x);
  f(x);
  printf("%d\n",x);
}
