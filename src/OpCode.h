#ifndef CCLOX_OPCODE_H
#define CCLOX_OPCODE_H

#include <ostream>

/**
 * Defines the operation codes (opcodes) for the virtual machine.
 */
enum class OpCode {
  CONST,
  RETURN,
};

/**
 * Overloads the stream insertion operator for OpCode.
 *
 * @param os The output stream where the OpCode will be written.
 * @param opcode The OpCode to be written to the stream.
 * @return A reference to the output stream after appending the OpCode string
 * representation.
 */
inline std::ostream& operator<<(std::ostream& os, const OpCode opcode) {
  switch (opcode) {
    case OpCode::CONST: os << "CONST"; break;
    case OpCode::RETURN: os << "RETURN"; break;
  }
  return os;
}

#endif  // CCLOX_OPCODE_H
