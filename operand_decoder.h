#ifndef _OPERAND_DECODER_H_
#define _OPERAND_DECODER_H_
#include <string>
#include <cinttypes>
#include "symbol_table.h"
using namespace std;
class OperandDecoder {
  public:
    OperandDecoder(SymbolTable symbolTable, SymbolTable dataTable,
        unsigned int end_instructions);
    int16_t decodeOperand(char *operand);
    int8_t getOperandsType(char *operand1, char *operand2);
  private:
    int end_instructions;
    int is_immediate(char *op);
    int is_label(char *op);
    int is_reg(char *op);
    int16_t stringToInt(char *op);
    SymbolTable symbolTable;
    SymbolTable dataTable;
};
#endif
