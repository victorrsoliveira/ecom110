#ifndef __COMMLIB_H
#define __COMMLIB_H

#include <stdint.h>

// Registers
#define SLOP  0x0120
#define TAP   0x0130
#define DTAP  0x0140
#define X     0x0150
#define Y     0x0160
#define Z     0x0170
#define SLOP  0x0120

// Read and Write command
#define READ 0x80
#define WRITE 0x00

typedef union {
  uint16_t full;
  struct {
    uint8_t low;
    uint8_t high;
  } byte;
} Address;

typedef struct {
  uint8_t *content;
  uint8_t size;
} Data;

typedef struct {
  Address address;
  Data data;
} Command;

void commandSet(Command *cmd, uint16_t addr, uint8_t * data, uint8_t size);
void commandWrite(Command *cmd);
void commandRead(Command *cmd);
void driverInit(void (*open)(), void (*write)(uint8_t data), uint8_t (*read)(), void (*close)());

#endif
