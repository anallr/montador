#include <string>
#include <cstring>
#include <iostream>
#include <cinttypes>
#include <vector>
#include "instruction.h"
using namespace std;
string Instruction::getLabel() {
  return this->label;
}
int Instruction::getSize() {
  return this->size;
}
char *Instruction::getOpcode() {
  return this->opcode;
}
char *Instruction::getOperand1() {
  return this->operand1;
}
char *Instruction::getOperand2() {
  return this->operand2;
}

int split(const string &text, char sep) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != string::npos) {
        if (end != start) {
          tokens.push_back(text.substr(start, end - start));
        }
        start = end + 1;
    }
    if (end != start) {
       tokens.push_back(text.substr(start));
    }
    return tokens.size();
}

//retira o comentario e guarda a instruçao
Instruction::Instruction(string instruction) {
  string::size_type comment = instruction.find(";");
  if (comment != string::npos)
    this->instruction_text = instruction.substr(0, comment);
  else
    this->instruction_text = instruction;
  label_decoded = 0;
  opcode_decoded = 0;
}
Instruction::~Instruction() {
  if (operand1) free(operand1);
  if (operand2) free(operand2);
}
void Instruction::decodeLabel() {
  label_decoded = 1;
  label_length = -1;
  if (instruction_text[0] == '_') {
    label_length = instruction_text.find(":");
    this->label = instruction_text.substr(0, label_length);
  } else {
    this->label = "";
  }
}
void Instruction::decodeOpcode() {
  if (!label_decoded) decodeLabel();
  opcode_decoded = 1;
  no_label_instruction = instruction_text.substr(label_length + 1);
  sscanf(no_label_instruction.c_str(), "%s", opcode);
  string comparar = opcode;
  if (!strcmp(opcode, "exit") ||
      !strcmp(opcode, "return"))
    this->size = 1;
if(split(no_label_instruction,' ')  == 2 || comparar.compare(".data:") != 0)
    this->size = 2;
  else if (split(no_label_instruction,' ')  == 3)
    this->size = 3;
}

void Instruction::decodeOperands() {
  if (!opcode_decoded) decodeOpcode();
  if (size == 1) {
    operand1 = operand2 = NULL;
  } else if (size == 2) {
    operand2 = NULL;
    operand1 = (char *)malloc(max_label_length*sizeof(char));
    sscanf(no_label_instruction.c_str(), "%*s %s", operand1);
  } else if (size == 3) {
    operand1 = (char *)malloc(max_label_length*sizeof(char));
    operand2 = (char *)malloc(max_label_length*sizeof(char));
    sscanf(no_label_instruction.c_str(), "%*s %s %s",
        operand1, operand2);
  }
}
