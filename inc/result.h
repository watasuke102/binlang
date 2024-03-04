///
/// @file result.h
/// @brief result data-type
/// @author watasuke
///
/// binlang - basic bit operation with interactive terminal
/// This program is released under the MIT or MIT SUSHI-WARE License.
///

#ifndef _BINLANG_MAIN_H_
#define _BINLANG_MAIN_H_

#include <stdbool.h>
#include <stdint.h>

/// @struct Result
/// @brief Value's result type. Included success status, <br>
/// pointer to command strings, and value.
typedef struct {
  //! If failed, this will be false.
  bool success;
  //! contained parse result. but if failed, this will be 0.
  uint64_t value;
  //! It has an error message.
  char message[64];
  //! pointer to command strings (indicate current position)
  char *command;
} Result;

#endif
