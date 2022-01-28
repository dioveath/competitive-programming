

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* add(const char *a, const char *b){
  const char* na;
  const char* nb;
  if(strlen(a) > strlen(b)){
    na = b;
    nb = a;
  } else {
    na = a;
    nb = b;
  }

  char* rs = (char*) malloc(sizeof(char) * strlen(nb)+2);
  rs[strlen(nb)+1] = '\0';
  int off = strlen(nb) - strlen(na);
  int c = 0, i, da, db, ds;
  for(i = strlen(na)-1; i >= 0; i--){
    da = na[i] - '0';
    db = nb[i+off] - '0';
    ds = da + db + c;

    if(ds > 9) {
      c = 1;
      rs[i+off+1] = '0' + (ds % 10);
    } else {
      c = 0;
      rs[i+off+1] = '0' + ds;
    }
  }

  while(off--) {
    ds = c + (nb[off] - '0');
    if(ds > 9) {
      c = 1;
      rs[off+1] = '0' + (ds % 10);
    } else {
      c = 0;
      rs[off+1] = '0' + ds;
    }
  }

  if(c) {
    rs[0] = '0' + c;
  } else {
    char* nrs = malloc(sizeof(char) * strlen(nb)+1);
    memcpy(nrs, rs+1, strlen(nb) + 1);
    return nrs;
  }

  return rs;
}

int main(){

  /* add("199", "99"); */

  printf("%s, %s \n", add("123", "456"),  "579");
  printf("%s, %s \n", add("888", "222"), "1110");
  printf("%s, %s \n", add( "1372", "69"), "1441");
  printf("%s, %s \n", add("12", "456"), "468");
  printf("%s, %s \n", add("101", "100"),  "201");
  printf("%s, %s \n", add("63829983432984289347293874", "90938498237058927340892374089"), "91002328220491911630239667963");  
  return 0;
}


/* printf("%s, %s \n", add( "1372", "69"), "1441");  */
/* prinf("%s, %s \n", add("12", "456"), "468"); */
/* printf("%s, %s \n", add("101", "100"),  "201"); */
/* printf("%s, %s \n", add("63829983432984289347293874", "90938498237058927340892374089"), "91002328220491911630239667963"); */
