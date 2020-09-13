#pragma once

#include <stdint.h>

#include <string.h>

#include <immintrin.h>

uint32_t crc32c_sse42_u3(const uint32_t prev, const uint8_t  next){ return _mm_crc32_u8 (prev, next); }
uint32_t crc32c_sse42_u4(const uint32_t prev, const uint16_t next){ return _mm_crc32_u16(prev, next); }
uint32_t crc32c_sse42_u5(const uint32_t prev, const uint32_t next){ return _mm_crc32_u32(prev, next); }

uint32_t crc32c_sse42_v3(const uint32_t prev, const uint8_t* data, const uint32_t length){
  uint32_t c = prev;
  for(uint32_t i=0; i<length; i++) c = _mm_crc32_u8(c, data[i]);
  return c ^ 0xffffffff;
}
uint32_t crc32c_sse42_s(const uint32_t prev, const char* data)
{ return crc32c_sse42_v3(prev, (const uint8_t*)data, strlen(data)); }

uint32_t crc32c_sse42_v4(const uint32_t prev, const uint16_t* data, const uint32_t length){
  uint32_t c = prev;
  for(uint32_t i=0; i<length; i++) c = _mm_crc32_u16(c, data[i]);
  return c ^ 0xffffffff;
}

uint32_t crc32c_sse42_v5(const uint32_t prev, const uint32_t* data, const uint32_t length){
  uint32_t c = prev;
  for(uint32_t i=0; i<length; i++) c = _mm_crc32_u32(c, data[i]);
  return c ^ 0xffffffff;
}
