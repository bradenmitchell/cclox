#include "Chunk.h"
#include "Debug.h"
#include "OpCode.h"

int main() {
  Chunk chunk;

  const auto index = chunk.addConstant(1.2);
  chunk.write(OpCode::CONST, 123);
  chunk.write(index, 123);

  chunk.write(OpCode::RETURN, 123);

  Debug::disassembleChunk(chunk, "test chunk");

  return EXIT_SUCCESS;
}
