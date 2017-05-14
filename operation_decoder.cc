#include <cinttypes>
#include <cstring>
#include "operation_decoder.h"
int16_t OperationDecoder::decodeOpcode(char *opcode) {
  if (!strcmp(opcode, ("MOV")))        return 0x0100;
  else if (!strcmp(opcode, ("ADD")))   return 0x0200;
  else if (!strcmp(opcode, ("SUB")))   return 0x0300;
  else if (!strcmp(opcode, ("MUL")))   return 0x0400;
  else if (!strcmp(opcode, ("DIV")))   return 0x0500;
  else if (!strcmp(opcode, ("AND")))   return 0x0600;
  else if (!strcmp(opcode, ("NOT")))   return 0x0700;
  else if (!strcmp(opcode, ("OR")))    return 0x0800;
  else if (!strcmp(opcode, ("CMP")))   return 0x0900;
  else if (!strcmp(opcode, ("JMP")))   return 0x0A00;
  else if (!strcmp(opcode, ("JZ")))    return 0x0B00;
  else if (!strcmp(opcode, ("JS")))    return 0x0C00;
  else if (!strcmp(opcode, ("CALL")))  return 0x0D00;
  else if (!strcmp(opcode, ("RET")))   return 0x0E00;
  else if (!strcmp(opcode, ("PUSH")))  return 0x0F00;
  else if (!strcmp(opcode, ("POP")))   return 0x1000;
  else if (!strcmp(opcode, ("DUMP")))  return 0x1100;
  else if (!strcmp(opcode, ("READ")))  return 0x1200;
  else if (!strcmp(opcode, ("WRITE"))) return 0x1300;
  else if (!strcmp(opcode, ("HLT")))   return 0x1400;
  return 0;
}
