#include "debug.h"

#include "chunk.h"
#include "opcode.h"

#include <iomanip>
#include <iostream>

/**
 * Disassembles a simple instruction.
 *
 * Simple instructions comprise an Opcode only (1 byte).
 *
 * @param opcode Opcode of the instruction.
 * @param offset Offset of the instruction in the bytecode.
 *
 * @return Offset of the next instruction.
 */
static int simple_instruction(const Opcode opcode, const int offset) {
  std::cout << opcode;
  return offset + 1;
}

/**
 * Disassembles a constant instruction.
 *
 * Constant instructions comprise an Opcode and the index of the constant
 * in the constant pool (2 bytes).
 *
 * @param chunk Chunk containing the instruction.
 * @param opcode Opcode of the instruction.
 * @param offset Offset of the instruction in the bytecode.
 *
 * @return Offset of the next instruction.
 */
static int constant_instruction(Chunk& chunk, const Opcode opcode,
                                const int offset) {
  const int index = chunk.code()[offset + 1];
  std::cout << std::left << std::setfill(' ') << std::setw(16) << opcode
            << std::right << std::setw(6) << index << "  ("
            << chunk.get_constant(index) << ')';

  return offset + 2;
}

void disassemble_chunk(Chunk& chunk, const std::string_view& name) {
  std::cout << "====== Disassembly: " << name << " ======\n";

  // Loop through each instruction and hand control to disassemble_instruction()
  // that, in turn, increments `offset` by returning the offset of the next
  // OpCode in the bytecode
  int offset = 0;
  while (offset < chunk.code().size()) {
    offset = disassemble_instruction(chunk, offset);
    std::cout << '\n';
  }
  std::cout << '\n';
}

int disassemble_instruction(Chunk& chunk, const int offset) {
  // Format offset
  std::cout << std::setw(4) << std::setfill('0') << std::right << offset
            << "  ";

  // Format source line number
  if (offset > 0 && chunk.get_line(offset) == chunk.get_line(offset - 1)) {
    std::cout << "  |  ";
  } else {
    std::cout << std::right << std::setfill(' ') << std::setw(3)
              << chunk.get_line(offset) << "  ";
  }

  // Defer to specific functions for each instruction type to output remaining
  // disassembly information and calculate offset for next Opcode
  switch (auto opcode = static_cast<Opcode>(chunk.code()[offset])) {
    case Opcode::CONST: return constant_instruction(chunk, opcode, offset);
    case Opcode::ADD:
    case Opcode::SUBTRACT:
    case Opcode::MULTIPLY:
    case Opcode::DIVIDE:
    case Opcode::NEGATE:
    case Opcode::RETURN: return simple_instruction(opcode, offset);

    default: {
      std::cout << "Error: Unknown Opcode: " << static_cast<int>(opcode);
      return offset + 1;
    }
  }
}
