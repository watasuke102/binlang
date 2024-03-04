///
/// @file opecode.h
/// @brief opecode type and CallOpecode
/// @author watasuke
///
/// binlang - basic bit operation with interactive terminal
/// This program is released under MIT License.
///

#ifndef _BINLANG_OPECODE_H_
#define _BINLANG_OPECODE_H_

#include "result.h"

typedef enum {
  OPECODE_AND,
  OPECODE_OR,
  OPECODE_XOR,
  OPECODE_NOT,
  OPECODE_LEN,
} Opecode;

extern Result CallOpecode(char *opecode_str, char *command);

#endif
