#include <stdio.h>
#include <stdbool.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) {
  if(search_text[0] == '\0') return 0;
  int nt = 0;
  char c, sc;
  for(int i = 0; (c = full_text[i]); i++){
    int j = -1;
    while(sc = search_text[++j]){
      if(sc != full_text[i+j]) break;
    }
    if(sc == '\0') {
      if(!allow_overlap) i += j-1;
      nt++;
    }
  }
  return nt;
}

int main(){
  printf("search_substr: %d, %d\n", search_substr("abcabcabc", "abc", false), 3);
  printf("search_substr: %d, %d\n", search_substr("abcabcabc", "abc", true), 3);
  printf("search_substr: %d, %d\n", search_substr("ababa_ababa_ababa", "aba", false), 3);
  printf("search_substr: %d, %d\n", search_substr("ababa_ababa_ababa", "aba", true), 6);  
}
