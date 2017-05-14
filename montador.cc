#include <cstdio>
#include <cstring>
#include "operand_decoder.h"
#include "symbol_table.h"
#include "instruction.h"
#include "assembler.h"
using namespace std;
int main(int argc, char *args[]) {
  //Avaliação dos parametros
  enum arg_type {o, v, outname, inname, noarg};
  arg_type args_type[5];
  for (int i = 0; i < 5; ++i)
    args_type[i] = inname;
  bool verbose = false;
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(args[i], "-v")) {
      verbose = true;
      args_type[i] = v;
    } else if (!strcmp(args[i], "-o")) {
      args_type[i] = o;
      args_type[i + 1] = outname;
    }
  }
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
  //printf("IN FILE: %s\n", in_filename);
  //printf("OUT FILE: %s\n", out_filename);
  //Processo de montagem
  Assembler assembler(in_filename, out_filename);
  assembler.firstPass();
  assembler.secondPass();
  if (verbose) assembler.printLabels();
  return 0;
}
