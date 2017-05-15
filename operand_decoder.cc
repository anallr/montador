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
  if (!strcmp(operand, "R0"))  return 1;
  else if (!strcmp(operand, "R1"))  return 1;
  else if (!strcmp(operand, "R2"))  return 1;
  else if (!strcmp(operand, "R3"))  return 1;
  else if (!strcmp(operand, "R4"))  return 1;
  else if (!strcmp(operand, "R5"))  return 1;
  else if (!strcmp(operand, "R6"))  return 1;
  else if (!strcmp(operand, "R7"))  return 1;
  else if (!strcmp(operand, "R8"))  return 1;
  else if (!strcmp(operand, "R9"))  return 1;
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
  else if (!strcmp(operand, "R0"))  return 1;
  else if (!strcmp(operand, "R1"))  return 1;
  else if (!strcmp(operand, "R2"))  return 1;
  else if (!strcmp(operand, "R3"))  return 1;
  else if (!strcmp(operand, "R4"))  return 1;
  else if (!strcmp(operand, "R5"))  return 1;
  else if (!strcmp(operand, "R6"))  return 1;
  else if (!strcmp(operand, "R7"))  return 1;
  else if (!strcmp(operand, "R8"))  return 1;
  else if (!strcmp(operand, "R9"))  return 1;
  return 0;
}
int16_t OperandDecoder::stringToInt(char *op) {
  int16_t value;
  sscanf(op, "%" SCNx16, &value);
  return value;
}
