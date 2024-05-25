#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "test.h"

int compareArrays(uint8_t a[32], uint8_t b[32])
{
  for (int i=0; i<32; i++)
  {
      if (a[i] != b[i])
      {
          return -1;
      }
  }
  return 0;
}

int main() {
    uint8_t header[80] = { 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0xcc,0xa6,0x6a,
        0x44,0xf8,0xbd,0x55,0x45,0xc3,0x16,0x4a,0x3a,0x76,0xda,0x50,0x39,0x53,0x28,0xc9,0x07,0x56,0x33,0x77,
        0x5b,0xc4,0xc8,0x79,0x8f,0xd6,0x77,0x2b,0x70,0x0d,0x21,0x5c,0xf0,0xff,0x0f,0x1e,0x00,0x00,0x00,0x00 };
    uint8_t hash[32] = { 0x2e, 0x4f, 0x85, 0x7a, 0xa8, 0x10, 0x08, 0xc4, 0xd1, 0xfe, 0x9a, 0xcd, 0x74, 0x89, 0xe8, 0x4d, 0x3b, 0xc5, 0x5b, 0x70, 0x54, 0xe6, 0xc0, 0x2b, 0x2c, 0x0e, 0x1b, 0x76, 0xcc, 0xa0, 0xda, 0x7b };
    uint8_t result[32];
    flex_hash((void*)header,(void*)result);
    if(compareArrays(&result, &hash) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    int i;
    printf("Expected: ");
    for (i=0; i<32; i++)
        printf("0x%02hhx ",hash[i]);
    printf("\n");
    printf("Result: ");
    for (i=0; i<32; i++)
        printf("0x%02hhx ",result[i]);
    return 0;
}