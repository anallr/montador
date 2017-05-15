#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cinttypes>
#include "assembler.h"
#include "operation_decoder.h"
#include "operand_decoder.h"
Assembler::Assembler(string input, string output) {
  input_file = new ifstream(input);
  output_file = fopen(output.c_str(), "w");
}
Assembler::~Assembler() {
  input_file->close();
  fclose(output_file);
}
void Assembler::firstPass() {
  unsigned int position = 0;
  unsigned int data_position = 0;
  fwrite(&position, 2, 1, output_file);//acho q n precisa
  string instruction;
  while (getline(*input_file, instruction)) {
    if (instruction.empty()) continue;// nunca acontece
    int i = 0;
    while (instruction[i] == ' ') ++i;
    //Salta as instruções que são só comentário
    if (instruction[i] == ';') continue;
    Instruction *ins = new Instruction(instruction);
    instructions.push_back(ins);
    ins->decodeLabel();
    ins->decodeOpcode();
    if (ins->no_label_instruction.find(".data") != string::npos) {
      instructions.pop_back();
      ins->decodeOperands();
      dataTable.insert(ins->getOperand1(), data_position++);
      valorImediato[*(new string(ins->label_decoded))] = Instruction->operand1;
    } else {
      if (!ins->getLabel().empty())
        labelTable.insert(ins->getLabel(), position);
      position += ins->getSize();
    }
  }
  dataTable.setShift(position);
  operandDecoder = new OperandDecoder(labelTable, dataTable, position);
}

void Assembler::secondPass() {
  for (auto it = instructions.begin(); it != instructions.end(); ++it) {
    (*it)->decodeOperands();
    char *opcode = (*it)->getOpcode(),
         *operand1 = (*it)->getOperand1(),
         *operand2 = (*it)->getOperand2();
    int16_t first_halfword = operationDecoder.decodeOpcode(opcode)
      + operandDecoder->getOperandsType(operand1, operand2);
    fwrite(&first_halfword, 2, 1, output_file);
    if (operand1) {
      int second_halfword = operandDecoder->decodeOperand(operand1);
      fwrite(&second_halfword, 2, 1, output_file);
    }
    if (operand2) {
      int third_halfword = operandDecoder->decodeOperand(operand2);
      fwrite(&third_halfword, 2, 1, output_file);
    }
  }
}
void Assembler::printLabels() {
  printf("LABELS:\n");
  labelTable.printLabels();
  printf("VARIABLES:\n");
  dataTable.printLabels();
}
