

#include <stdio.h>

int beeramid(double bonus, double price) {
  int i;
  int b = (double)bonus / price;
  for (i = 0; b >= 0; ++i) {
    b -= i * i;
  }
  return i-2;
}

int main(){
  printf("%d\n", beeramid(5000, 3));
  return 0;
}
