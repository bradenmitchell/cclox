#ifndef CCLOX_DEBUG_H
#define CCLOX_DEBUG_H

#include <string>

// Forward references
class Chunk;

/**
 * Provides utilities for inspecting and debugging the contents of a Chunk,
 * including disassembling bytecode and individual instructions for
 * human-readable analysis.
 */
class Debug {
public:
  /**
   * Disassembles all instructions in a given Chunk.
   *
   * Loops through a Chunk's bytecode and coordinate disassembly of each
   * individual instruction.
   *
   * @param chunk The Chunk to disassemble.
   * @param chunkName The name of the Chunk.
   */
  static void disassembleChunk(Chunk& chunk, std::string_view chunkName);

  /**
   * Disassembles a single instruction in a Chunk.
   *
   * @param chunk The Chunk containing the instruction to disassemble.
   * @param offset The offset of the instruction within the Chunk.
   * @return The offset for the start of the next instruction.
   */
  static size_t disassembleInstruction(Chunk& chunk, size_t offset);
};

#endif  // CCLOX_DEBUG_H
