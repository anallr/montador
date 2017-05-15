#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <string>
#include <cinttypes>
using namespace std;
class Instruction {
  public:
    Instruction(string instruction);
    ~Instruction();
    string getLabel();
    int getSize();
    char *getOpcode();
    char *getOperand1();
    char *getOperand2();
    int8_t getOperandsType();
    void decodeLabel();
    void decodeOpcode();
    void decodeOperands();
    string no_label_instruction;
    char opcode[6];
    int label_decoded;
  private:
    int opcode_decoded;
    string instruction_text;
    string label;
    static const int max_label_length = 100;
    int label_length;
    char *operand1;
    char *operand2;
    unsigned int size;
};
#endif
