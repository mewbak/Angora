/*
  Test:
  Simple add for different type.
  Our goal is to check that infer type function is works.
  variable bb should has byte offsets 0-1, 4-7, 10-13, 14-17.
 */

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char **argv) {
  if (argc < 2)
    return 0;

  FILE *fp;
  char buf[255];
  size_t ret;

  fp = fopen(argv[1], "rb");

  if (!fp) {
    printf("st err\n");
    return 0;
  }

  int len = 20;

  ret = fread(buf, sizeof *buf, len, fp);
  fclose(fp);
  if (ret < len) {
    printf("input fail \n");
    return 0;
  }

  uint16_t x = 0;
  int32_t y = 0;
  int32_t z = 0;
  uint32_t a = 0;

  memcpy(&x, buf + 1, 2);  // x 0 - 1
  memcpy(&y, buf + 4, 4);  // y 4 - 7
  memcpy(&z, buf + 10, 4); // 10 - 13
  memcpy(&a, buf + 14, 4); // 14 - 17

  uint32_t bb = x + y + z + a;
  if (bb == 213) {
    printf("hey, you hit it \n");
    abort();
  }
  return 0;
}
