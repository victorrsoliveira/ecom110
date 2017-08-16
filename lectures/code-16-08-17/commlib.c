#include "commlib.h"

static void (*_open)();
static void (*_write)(uint8_t data);
static uint8_t (*_read)();
static void (*_close)();

void driverInit(void (*open)(), void (*write)(uint8_t data), uint8_t (*read)(), void (*close)()) {
  _open = open;
  _write = write;
  _read = read;
  _close = close;
}

void commandSet(Command *cmd, uint16_t addr, uint8_t * data, uint8_t size) {
  cmd->address.full = addr;
  cmd->data.content = data;
  cmd->data.size = size;
}

void commandWrite(Command *cmd) {
  _open();
  _write(cmd->address.byte.high);
  _write(cmd->address.byte.low);
  _write(WRITE);
  for (uint8_t i = 0; i < cmd->data.size; i++) {
    _write(cmd->data.content[i]);
  }
  _close();
}

void commandRead(Command *cmd) {
  _open();
  _write(cmd->address.byte.high);
  _write(cmd->address.byte.low);
  _write(READ);
  for (uint8_t i = 0; i < cmd->data.size; i++) {
    cmd->data.content[i] = _read();
  }
  _close();
}
