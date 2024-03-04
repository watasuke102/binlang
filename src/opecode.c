///
/// @file opecode.h
/// @brief function of binary operation
/// @author watasuke
///
/// binlang - basic bit operation with interactive terminal
/// This program is released under the MIT or MIT SUSHI-WARE License.
///

#include "opecode.h"
#include "value.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

Result OpecodeAnd(char *command) {
  const Result left = Value(command);
  if (!left.success)
    return left;
  const Result right = Value(left.command);
  if (!right.success)
    return right;
  return (Result){true, left.value & right.value, "", right.command};
}
Result OpecodeOr(char *command) {
  const Result left = Value(command);
  if (!left.success)
    return left;
  const Result right = Value(left.command);
  if (!right.success)
    return right;
  return (Result){true, left.value | right.value, "", right.command};
}
Result OpecodeXor(char *command) {
  const Result left = Value(command);
  if (!left.success)
    return left;
  const Result right = Value(left.command);
  if (!right.success)
    return right;
  return (Result){true, left.value ^ right.value, "", right.command};
}
Result OpecodeNot(char *command) {
  const Result val = Value(command);
  if (!val.success)
    return val;
  return (Result){true, ~val.value, "", val.command};
}

static Result (*const bin_operate[OPECODE_LEN])(char *) = {
    [OPECODE_AND] = OpecodeAnd,
    [OPECODE_OR] = OpecodeOr,
    [OPECODE_XOR] = OpecodeXor,
    [OPECODE_NOT] = OpecodeNot,
};
//! Supported opecode list
static const char *opecode[OPECODE_LEN] = {
    [OPECODE_AND] = "AND",
    [OPECODE_OR] = "OR",
    [OPECODE_XOR] = "XOR",
    [OPECODE_NOT] = "NOT",
};

/// @fn CallOpecode(char*, char*)
/// @brief Call specified opecode. see below (opecode[])
///
/// @param opecode_str opecode strings.
/// @param command command strings.
///
/// @return Success: Result{true,  any, "", any} <br>
///         Failed:  Result{false, 0, error_message, any}
Result CallOpecode(char *opecode_str, char *command) {
  for (int i = 0; i < OPECODE_LEN; ++i) {
    if (strcmp(opecode_str, opecode[i]) == 0) {
      return (*bin_operate[i])(command);
    }
  }
  return (Result){false, 0, "Invalid opecode", command};
}
