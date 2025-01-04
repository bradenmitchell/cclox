#include "Chunk.h"

void Chunk::write(const uint8_t instruction, const int line) {
  code_.push_back(instruction);
  lines_.push_back(line);
}

void Chunk::write(OpCode opcode, const int line) {
  write(static_cast<uint8_t>(opcode), line);
}

std::vector<uint8_t>& Chunk::code() {
  return code_;
}

Value Chunk::constant(const size_t index) const {
  return constants_[index];
}

size_t Chunk::addConstant(const Value value) {
  constants_.push_back(value);
  return constants_.size() - 1;
}

int Chunk::line(const size_t offset) const {
  return lines_[offset];
}
