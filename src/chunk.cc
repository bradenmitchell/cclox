#include "chunk.h"

#include "opcode.h"

void Chunk::write(const uint8_t instruction, int line) {
  _code.push_back(instruction);
  _lines.push_back(line);
}

void Chunk::write(Opcode opcode, int line) {
  write(static_cast<uint8_t>(opcode), line);
}

std::vector<uint8_t>& Chunk::code() {
  return _code;
}

Value Chunk::get_constant(const int index) const {
  return _constants[index];
}

int Chunk::add_constant(const Value value) {
  _constants.push_back(value);
  return static_cast<int>(_constants.size()) - 1;
}

int Chunk::get_line(const int offset) const {
  return _lines[offset];
}
