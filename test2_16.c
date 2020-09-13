#include "crc32c.h"

#include <stdio.h>

int main(int arg, char** argv){
  const uint16_t data[] = {0x3776, 0x0634};
  const uint32_t c = crc32c_sse42_v4(0xffffffff, data, 2);
  switch(c){
    case 0xd4b6d5a4: return 0;
    default:         break;
  }
  fprintf(stderr, "expected: 0xd4b6d5a4. got: %0x\n", c);
  return 1;
}
