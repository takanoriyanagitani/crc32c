#include "crc32c.h"

#include <stdio.h>

int main(int arg, char** argv){
  const uint32_t data[] = {0x37760599, 0x06340333};
  const uint32_t c = crc32c_sse42_v5(0xffffffff, data, 2);
  switch(c){
    case 0x7aeaf5d9: return 0;
    default:         break;
  }
  fprintf(stderr, "expected: 0x7aeaf5d9. got: %0x\n", c);
  return 1;
}
