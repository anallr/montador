CC=g++
CFLAGS=-c -g -std=c++11 -Wall -Werror -Wextra
main: montador.o operand_decoder.o symbol_table.o instruction.o assembler.o operation_decoder.o
	$(CC) montador.o operand_decoder.o symbol_table.o instruction.o assembler.o operation_decoder.o -o ../montador
montador.o: montador.cc
	$(CC) montador.cc $(CFLAGS)
operand_decoder.o: operand_decoder.cc
	$(CC) operand_decoder.cc $(CFLAGS)
symbol_table.o:	symbol_table.cc
	$(CC) symbol_table.cc $(CFLAGS)
instruction.o: instruction.cc
	$(CC) instruction.cc $(CFLAGS)
assembler.o: assembler.cc
	$(CC) assembler.cc $(CFLAGS)
operation_decoder.o: operation_decoder.cc
	$(CC) operation_decoder.cc $(CFLAGS)
clean:
	rm -f *.o
run:
	./montador tst/fibonacci.asm
