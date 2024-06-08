#ifndef CCLOX_DEBUG_H
#define CCLOX_DEBUG_H

#include <string>

// Forward declarations
class Chunk;

/**
 * Disassembles a chunk's entire bytecode.
 *
 * @param chunk Chunk to be disassembled.
 * @param name Name of the chunk.
 */
void disassemble_chunk(Chunk& chunk, const std::string_view& name);

/**
 * Disassembles an individual bytecode instruction.
 *
 * @param chunk Chunk containing the instruction.
 * @param offset Offset of the instruction in the bytecode.
 *
 * @return Offset of the next instruction in the bytecode.
 */
int disassemble_instruction(Chunk& chunk, int offset);

#endif  // CCLOX_DEBUG_H
