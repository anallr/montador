#ifndef _SB_ASSEMBLER_H_
#define _SB_ASSEMBLER_H_
#include <fstream>
#include <vector>
#include <cstdio>
#include "symbol_table.h"
#include "instruction.h"
#include "operation_decoder.h"
#include "operand_decoder.h"
class Assembler {
  public:
    Assembler(string input, string output);
    ~Assembler();
    void firstPass();
    void secondPass();
    void printLabels();
  private:
    SymbolTable labelTable;
    SymbolTable dataTable;
    OperationDecoder operationDecoder;
    OperandDecoder *operandDecoder;
    ifstream *input_file;
    FILE *output_file;
    vector<Instruction *> instructions;
};
#endif
