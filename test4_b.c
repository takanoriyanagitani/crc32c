#include "crc32c.h"

#include <stdio.h>
#include <stdbool.h>

int main(int arg, char** argv){
  FILE* f = fopen("/dev/zero", "rb");
  switch(NULL==f){
    case true: return 1;
    default:   break;
  }
  uint32_t buf[1024] = {0};
  uint32_t c         = 0xffffffff;
  size_t   s         = 1024;
  const uint32_t maxi = 1048576;
  for(uint32_t i=0; i<maxi && 1024 == s; i++){
    s = fread(buf, 4, 1024, f);
    switch(s){
      case 0:    break;
      case 1024: break;
      default:
	fclose(f);
        return 1;
    }
    c = crc32c_sse42_v5(c, buf, 1024);
  }
  printf("bytes: %ld\n", (uint64_t)maxi * 4 * 1024);
  fclose(f);
  return 0;
}
