#include<stdlib.h>


//Function should return an array of c-strings with all possible PINs.
//It must allocate all required meomry, but there are no requirements
//as to how it should be done. It must be possible to free
//allocated memory with a call to free_pins.
//Upon return, count should contain the amount of returned PINs.
const char** get_pins(const char* observed, size_t* count) {
    *count = 1;
    return NULL;
}

//This function will be called once per every call to get_pins
//with a pointer value returned by such call.
void free_pins(const char ** pins) {
    //...do your cleanup, if necessary
}

int main(){


  return 0;
}
