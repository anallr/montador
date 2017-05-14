#include <cinttypes>
#include <cstring>
#include "operation_decoder.h"
int16_t OperationDecoder::decodeOpcode(char *opcode) {
  if (!strcmp(opcode, ("exit")))          return 0x0000;  //0  | 0 operandos
  else if (!strcmp(opcode, ("loadi")))    return 0x0800;  //1  | 1 operando
  else if (!strcmp(opcode, ("storei")))   return 0x1000;  //2  | 2 operando(imediato)
  else if (!strcmp(opcode, ("add")))      return 0x1800;  //3  | 2 operandos
  else if (!strcmp(opcode, ("subtract"))) return 0x2000;  //4  | 2 operandos
  else if (!strcmp(opcode, ("multiply"))) return 0x2800;  //5  | 2 operandos
  else if (!strcmp(opcode, ("divide")))   return 0x3000;  //6  | 2 operandos
  else if (!strcmp(opcode, ("jump")))     return 0x3800;  //7  | 2 operandos(memoria)
  else if (!strcmp(opcode, ("jmpz")))     return 0x4000;  //8  | 2 operandos(memoria)
  else if (!strcmp(opcode, ("jmpn")))     return 0x4800;  //9  | 2 operandos(memoria)
  else if (!strcmp(opcode, ("move")))     return 0x5000;  //10 | 2 operandos
  else if (!strcmp(opcode, ("load")))     return 0x5800;  //11 | 2 operandos
  else if (!strcmp(opcode, ("store")))    return 0x6000;  //12 | 2 operandos
  else if (!strcmp(opcode, ("loadc")))    return 0x6800;  //13 | 2 operandos
  else if (!strcmp(opcode, ("clear")))    return 0x7000;  //14 | 1 operando
  else if (!strcmp(opcode, ("negate")))   return 0x7800;  //15 | 2 operandos
  else if (!strcmp(opcode, ("push")))     return 0x8000;  //16 | 1 operando
  else if (!strcmp(opcode, ("pop")))      return 0x8800;  //17 | 1 operando
  else if (!strcmp(opcode, ("addi")))     return 0x9000;  //18 | 2 operandos(memoria)
  else if (!strcmp(opcode, ("call")))     return 0x9800;  //19 | 1 operando (especial)bits n usados no inicio
  else if (!strcmp(opcode, ("return")))   return 0xA000;  //20 | 0 operandos
  return 0;
}
