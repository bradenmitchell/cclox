#ifndef CCLOX_OPCODE_H
#define CCLOX_OPCODE_H

#include <ostream>

/** Bytecode instruction set for the Lox virtual machine. */
enum class Opcode {
  CONST,
  RETURN,
};

/** Defines opcode string representation in streams. */
inline std::ostream& operator<<(std::ostream& os, const Opcode opcode) {
  switch (opcode) {
    case Opcode::CONST: os << "CONST"; break;
    case Opcode::RETURN: os << "RETURN"; break;
  }

  return os;
}

#endif  // CCLOX_OPCODE_H
