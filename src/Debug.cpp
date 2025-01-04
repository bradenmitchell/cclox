#include "Debug.h"

#include <iomanip>
#include <iostream>

#include "Chunk.h"
#include "OpCode.h"

/**
 * Processes a constant instruction.
 *
 * Retrieves the constant index from the bytecode, then formats and prints the
 * opcode, index and corresponding constant value for debugging. Increments
 * offset by 2 to account for the opcode and index byte.
 *
 * @param chunk The chunk containing the bytecode and constants.
 * @param opcode The opcode of the instruction being processed.
 * @param offset The current offset of the instruction in the chunk.
 * @return The offset of the next instruction in the chunk.
 */
static size_t constantInstruction(Chunk& chunk, const OpCode opcode,
                                  const size_t offset) {
  const int index = chunk.code()[offset + 1];
  std::cout << std::left << std::setfill(' ') << std::setw(16) << opcode
            << std::right << std::setw(6) << index << "  ("
            << chunk.constant(index) << ')';

  return offset + 2;
};

/**
 * Processes a simple instruction with no additional operands.
 *
 * @param opcode The opcode of the instruction to process.
 * @param offset The current offset of the instruction in the chunk.
 * @return The offset of the next instruction in the chunk.
 */
static size_t simpleInstruction(OpCode opcode, const size_t offset) {
  std::cout << opcode;
  return offset + 1;
};

// -----------------------------------------------------------------------------
void Debug::disassembleChunk(Chunk& chunk, const std::string_view chunkName) {
  std::cout << "Disassembly: " << chunkName << "\n";

  for (size_t offset = 0; offset < chunk.code().size();) {
    offset = disassembleInstruction(chunk, offset);
    std::cout << "\n";
  }
  std::cout << "\n";
}

// -----------------------------------------------------------------------------
size_t Debug::disassembleInstruction(Chunk& chunk, const size_t offset) {
  // Format instruction offset
  std::cout << std::setw(4) << std::setfill('0') << offset << "  ";

  // Format source line no.
  if (offset > 0 && chunk.line(offset) == chunk.line(offset - 1)) {
    std::cout << "  |  ";
  } else {
    std::cout << std::right << std::setfill(' ') << std::setw(3)
              << chunk.line(offset) << "  ";
  }

  switch (auto opcode = static_cast<OpCode>(chunk.code()[offset])) {
    case OpCode::CONST: return constantInstruction(chunk, opcode, offset);
    case OpCode::RETURN: return simpleInstruction(opcode, offset);

    default:
      std::cout << "Error: Unknown opcode: " << static_cast<int>(opcode);
      return offset + 1;
  };
}
