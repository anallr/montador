#include <cstdio>
#include <cstring>
#include "operand_decoder.h"
#include "symbol_table.h"
#include "instruction.h"
#include "assembler.h"
using namespace std;
int main(int argc, char *args[]) {  
  //FILE INPUT AND output
  const char *in_filename = NULL,
             *out_filename = NULL;
  for (int i = 1; i < argc; ++i)
    if (args_type[i] == inname)
      in_filename = args[i];
    else if (args_type[i] == outname)
      out_filename = args[i];
  if (!in_filename) {
    printf("No input file");
    return 0;
  }
  if (!out_filename) {
    string *str = new string(in_filename);
    str->replace(str->find("asm"), 3, "sa");
    out_filename = str->c_str();
  }
  //Processo de montagem
  Assembler assembler(in_filename, out_filename);
  assembler.firstPass();
  assembler.secondPass();
  if (verbose) assembler.printLabels();
  return 0;
}
