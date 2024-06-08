#include "chunk.h"
#include "debug.h"
#include "opcode.h"

int main() {
  Chunk chunk;

  const auto index = chunk.add_constant(1.2);
  chunk.write(Opcode::CONST, 123);
  chunk.write(index, 123);

  chunk.write(Opcode::RETURN, 123);

  disassemble_chunk(chunk, "test chunk");

  return EXIT_SUCCESS;
}
