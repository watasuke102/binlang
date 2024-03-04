///
/// @file main.c
/// @brief program entry
/// @author watasuke
///
/// binlang - basic bit operation with interactive terminal
/// This program is released under MIT License.
///

#include "result.h"
#include "value.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print(Result r) {
  if (r.success)
    printf("%lu\n", r.value);
  else
    printf("%s\n", r.message);
}

/// @fn main(int, char**)
/// @brief entry point. If it exists command-line argument, <br>
/// program runs that command and exit. <br>
/// If it is empty, start interpreter-like terminal.
int main(int args, char **argv) {
  if (args >= 2) {
    print(Value(argv[1]));
    return 0;
  }

  // put greeting message and break *twice*
  puts("================================\n"
       " binlang terminal\n"
       " (type :q to exit)\n"
       "================================\n");

  char command[512] = {0};
  while (true) {
    printf(">> ");
    fgets(command, 512, stdin);
    if (command[0] == ':' && command[1] == 'q')
      break;
    print(Value(command));
  }
  puts("exit");
  return 0;
}
