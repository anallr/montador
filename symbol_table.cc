#include "symbol_table.h"
#include <string>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;
SymbolTable::SymbolTable() {
  this->shift = 0;
}
void SymbolTable::insert(string label, int position) {
  this->labels_map.insert(pair<string, int>(label, position));
}
void SymbolTable::setShift(int shift) {
  this->shift = shift;
}
int SymbolTable::getLabelPosition(string label) {
  return this->shift + this->labels_map[label];
}
void SymbolTable::printLabels() {
  for (auto it = labels_map.begin(); it != labels_map.end(); ++it)
    printf("%s %d\n", (*it).first.c_str(), shift + (*it).second);
}
