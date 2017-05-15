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
    string label;
    char *operand1;
    int posicao;
  private:
    int label_decoded;
    int opcode_decoded;
    string instruction_text;
    static const int max_label_length = 100;
    int label_length;
    char *operand2;
    unsigned int size;
};
#endif
