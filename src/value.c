///
/// @file value.c
/// @brief parse and get value
/// @author watasuke
///
/// binlang - basic bit operation with interactive terminal
/// This program is released under MIT License.
///

#include "opecode.h"
#include "result.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/// @fn Value(char*)
/// @brief Parse command and return value.
///
/// @param command command strings.
///
/// @return Result Success: Result{true,  any, "",            any} <br>
///                Failed:  Result{false, 0,   error_message, any}
Result Value(char *command) {
  if (*command == '\0')
    return (Result){false, 0, "Unexpected NULL character", command};

  char buf[512] = {0};
  int i = 0;
  while (*command != '\0') {
    const char c = *command;
    ++command;
    switch (c) {
    case ' ':
    case '_':
    case '\n':
      break;

    case '(':
      return CallOpecode(buf, command);

    case ')':
    case ',':
      goto end_of_read;
    default:
      buf[i] = c;
      ++i;
    }
    // buf[511] must be NUL
    if (i >= 511)
      return (Result){false, 0, "Too long command", command};
  }
end_of_read:;
  // uint from string
  int8_t base = 10, num_begin = 0;
  if (buf[0] == '0')
    switch (buf[1]) {
    case 'x':
      // 0x1234
      //   ^ this index is 2
      num_begin = 2;
      base = 16;
      break;
    case 'b':
      num_begin = 2;
      base = 2;
      break;
    case 'o':
      num_begin = 2;
      base = 8;
      break;
    default:
      // 0765
      //  ^ this index is 1
      num_begin = 1;
      base = 8;
      break;
    }
  unsigned long long int weight = 1, result = 0, value = 0;
  // buf[i] is \0 now
  --i;
  for (; i >= num_begin; --i) {
    // check invalid character
    // not A~F && not a~f && not 0~9 => Invalid
    if ((buf[i] < 'A' || buf[i] > 'F') && (buf[i] < 'a' || buf[i] > 'f') &&
        (buf[i] < '0' || buf[i] > '9')) {
      return (Result){false, 0, "Invalid character in immediate value"};
    }
    switch (base) {
    case 16:
      if (buf[i] >= 'a')
        value = 10 + (buf[i] - 'a');
      else if (buf[i] >= 'A')
        value = 10 + (buf[i] - 'A');
      else
        value = buf[i] - '0';
      break;

    case 10:
      if (buf[i] < '0' || buf[i] > '9')
        return (Result){false, 0, "Invalid character in immediate value"};
      value = buf[i] - '0';
      break;

    case 8:
      if (buf[i] < '0' || buf[i] > '7')
        return (Result){false, 0, "Invalid character in immediate value"};
      value = buf[i] - '0';
      break;

    case 2:
      if (buf[i] < '0' || buf[i] > '1')
        return (Result){false, 0, "Invalid character in immediate value"};
      value = buf[i] - '0';
      break;
    }
    result += value * weight;

    weight *= base;
  }
  return (Result){true, result, "", command};
}
