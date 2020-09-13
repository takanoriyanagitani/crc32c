#include "crc32c.h"

#include <stdio.h>

int main(int arg, char** argv){
  const uint32_t c = crc32c_sse42_s(0xffffffff, "Hello world");
  switch(c){
    case 0x72b51f78: return 0;
    default:         break;
  }
  fprintf(stderr, "expected: 0x72b51f78. got: %0x\n", c);
  return 1;
}
