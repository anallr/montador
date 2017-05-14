#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_
#include <string>
#include <map>
using namespace std;
class SymbolTable {
  public:
    SymbolTable();
    void insert(string label, int position);
    int getLabelPosition(string label);
    void printLabels();
    void setShift(int shift);
  private:
    map<string, int> labels_map;
    unsigned int shift;
};
#endif
