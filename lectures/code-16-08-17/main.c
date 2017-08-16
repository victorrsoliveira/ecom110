#include "commlib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>




void open() {
  printf("Communication started...\n");
}

void write(uint8_t data) {
  printf("Write data: %02X\n", data);
}

uint8_t read() {
  uint8_t data = (uint8_t) rand();
  printf("Read data: %02X\n", data);
  return data;
}

void close() {
  printf("Stop communication!\n");
}
int main() {
  // random number initilization
  srand(time(NULL));
  driverInit(open, write, read, close);
  Command cmd;
  uint8_t data = 0xA0;
  commandSet(&cmd, SLOP, &data, sizeof(data));
  commandWrite(&cmd);
}
