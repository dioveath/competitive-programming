#include <cstdio>
#include <stdlib.h>

typedef unsigned long long ull;

ull memo[20000] = {}; // memo = { 123123412, 1, 1, 2, 3, 5, ... }
int msz = 0;


ull fib(int n, ull memo[]){
  if(n <= 2) return 1;  
  if(n <= msz) {
    return memo[n];
  }
  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
  msz = n;
  return memo[n];
}

ull perimeter(int n) {
  ull s = 0;
  for(int i = 1; i <= n+1; i++){
    s += fib(i, memo);
  }

  printf("msz: %d\n", msz);
  for(int i = 0; i <= msz; i++){
    printf("memo[%d]: %d\n", i, memo[i]);
  }

  return s * 4;
}


int main(){
  printf("%d", perimeter(5));
  return 0;
}
