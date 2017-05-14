#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cinttypes>
#include <cstdint>
#include "symbol_table.h"
#include "operand_decoder.h"
using namespace std;
OperandDecoder::OperandDecoder(SymbolTable symbolTable,
    SymbolTable dataTable, unsigned int end_instructions) {
  this->end_instructions = end_instructions;
  this->symbolTable = symbolTable;
  this->dataTable = dataTable;
}
int OperandDecoder::is_label(char *op) {
  return !(is_reg(op) || is_immediate(op));
}
int OperandDecoder::is_immediate(char *operand) {
  return operand[0] == '0';
}
int OperandDecoder::is_reg(char *operand) {
  if (!strcmp(operand, "AL"))  return 1;
  else if (!strcmp(operand, "AH"))  return 1;
  else if (!strcmp(operand, "AX"))  return 1;
  else if (!strcmp(operand, "BH"))  return 1;
  else if (!strcmp(operand, "BL"))  return 1;
  else if (!strcmp(operand, "BX"))  return 1;
  else if (!strcmp(operand, "CL"))  return 1;
  else if (!strcmp(operand, "CH"))  return 1;
  else if (!strcmp(operand, "CX"))  return 1;
  return 0;
}
int8_t OperandDecoder::getOperandsType(char *operand1, char *operand2) {
  if      (operand1 == NULL   && operand2 == NULL)        return 0;
  else if (operand2 == NULL   && is_reg(operand1))        return 1;
  else if (operand2 == NULL   && is_label(operand1))      return 2;
  else if (is_reg(operand1)   && is_label(operand2))      return 3;
  else if (is_label(operand1) && is_reg(operand2))        return 4;
  else if (is_reg(operand1)   && is_reg(operand2))        return 5;
  else if (is_label(operand1) && is_immediate(operand2))  return 6;
  else if (is_reg(operand1)   && is_immediate(operand2))  return 7;
  else if (operand2 == NULL   && is_immediate(operand1))  return 8;
  return 9;
}
int16_t OperandDecoder::decodeOperand(char *operand) {
  if (is_label(operand))
    if (operand[0] == '_')
      return symbolTable.getLabelPosition(*(new string(operand)));
    else
      return dataTable.getLabelPosition(*(new string(operand)));
  else if (operand[0] == '0')       return stringToInt(operand);
  else if (!strcmp(operand, "AL"))  return 0;
  else if (!strcmp(operand, "AH"))  return 1;
  else if (!strcmp(operand, "AX"))  return 2;
  else if (!strcmp(operand, "BH"))  return 3;
  else if (!strcmp(operand, "BL"))  return 4;
  else if (!strcmp(operand, "BX"))  return 5;
  else if (!strcmp(operand, "CL"))  return 6;
  else if (!strcmp(operand, "CH"))  return 7;
  else if (!strcmp(operand, "CX"))  return 8;
  return 0;
}
int16_t OperandDecoder::stringToInt(char *op) {
  int16_t value;
  sscanf(op, "%" SCNx16, &value);
  return value;
}
