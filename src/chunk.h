#ifndef CCLOX_CHUNK_H
#define CCLOX_CHUNK_H

#include <vector>

// Forward declarations
enum class Opcode;

// Temporary typedef
typedef double Value;

/** Represents a sequence of compiled bytecode instructions. */
class Chunk {
public:
  /**
   * Writes a new `instruction` to the bytecode.
   *
   * @param instruction The instruction to be written.
   * @param line Source line number of the instruction.
   */
  void write(uint8_t instruction, int line);

  /**
   * Writes a new `opcode` to the bytecode.
   *
   * @param opcode The opcode to be written.
   * @param line Source line number of the opcode.
   */
  void write(Opcode opcode, int line);

  /**
   * Accesses the chunk's bytecode.
   *
   * @return Reference to the bytecode vector.
   */
  std::vector<uint8_t>& code();

  /**
   * Gets a value from the constant pool.
   *
   * @param index Index of the value in the pool.
   *
   * @return Value at `index` in the pool.
   */
  Value get_constant(int index) const;

  /**
   * Adds a `value` to the constant pool.
   *
   * @param value The value to be added.
   *
   * @return Index of the value in the constant pool.
   */
  int add_constant(Value value);

  /**
   * Gets the source line number of an instruction.
   *
   * @param offset Offset of the instruction in the bytecode.
   * @return Corresponding source line number.
   */
  int get_line(int offset) const;

private:
  /** Bytecode. */
  std::vector<uint8_t> _code;

  /** Constant pool. */
  std::vector<Value> _constants;

  /** Maps source line number for each instruction */
  std::vector<int> _lines;
};

#endif  // CCLOX_CHUNK_H
