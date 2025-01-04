#ifndef CCLOX_CHUNK_H
#define CCLOX_CHUNK_H

#include <vector>

// Forward declarations
enum class OpCode;

// Temporary typedef
typedef double Value;

/**
 * Represents a sequence of bytecode instructions for the virtual machine.
 *
 * The Chunk class is responsible for storing and managing bytecode
 * instructions, which can be either raw bytes or predefined opcodes. It offers
 * methods to append instructions and maintains an internal storage mechanism
 * for efficient handling.
 */
class Chunk {
public:
  /**
   * Appends a raw byte instruction to the chunk.
   *
   * This method adds a single byte representing a raw instruction for the
   * virtual machine to the internal storage and records the corresponding
   * source code line.
   *
   * @param instruction The raw byte instruction to append.
   * @param line The source code line number associated with the instruction.
   */
  void write(uint8_t instruction, int line);

  /**
   * Appends an opcode instruction to the chunk.
   *
   * This method adds a high-level operation code to the internal storage,
   * casting it to `uint8_t` before storing, and records the corresponding
   * source code line.
   *
   * @param opcode The opcode to append.
   * @param line The source code line number associated with the opcode.
   * @overload
   */
  void write(OpCode opcode, int line);

  /**
   * Returns a reference to the internal bytecode vector.
   *
   * Provides access to the vector of bytecode instructions stored in the
   * `Chunk` object. Modifications to the returned vector directly affect the
   * stored bytecode.
   *
   * @return Reference to the chunk's bytecode vector.
   */
  std::vector<uint8_t>& code();

  /**
   * Retrieves a constant value from the chunk's constant pool.
   *
   * This function returns the constant stored at the given index in the
   * `constants_` vector.
   *
   * @param index Index of the constant to retrieve.
   * @return The constant value at the given index.
   */
  Value constant(size_t index) const;

  /**
   * Adds a constant value to the chunk's constant pool.
   *
   * This function appends a new constant to the `constants_` vector and returns
   * its index, which can be used as a reference in bytecode instructions.
   *
   * @param value The constant value to add.
   * @return The index of the added constant in the constant pool.
   */
  size_t addConstant(Value value);

  int line(size_t offset) const;

private:
  /**
   * The chunk's bytecode instructions.
   *
   * This vector contains the sequence of bytecode instructions added to the
   * chunk.
   */
  std::vector<uint8_t> code_;

  /**
   * Stores constants referenced by the chunk's bytecode.
   *
   * This vector stores values used as operands in the bytecode instructions.
   */
  std::vector<Value> constants_;

  /**
   * Maps bytecode offsets to their corresponding source code lines.
   *
   * This vector stores line numbers for each byte in the bytecode, enabling
   * error reporting and debugging by associating bytecode instructions with
   * their source locations.
   */
  std::vector<int> lines_;
};

#endif  // CCLOX_CHUNK_H
