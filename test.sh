#!/usr/bin/bash

exec=build/binlang.out

success_score=0
total_test=0

# echo with color
# $1: color, $2: text, $3~: args
echo_color() {
  str="\e[$1m$2\e[m"
  shift 2
  echo -e $@ ${str} 
}

# run test
# $1: detail, $2: expect output, $3~: args
test() {
  echo_color "30;46" "===== [test] '$1'"
  shift
  expect=$1
  shift

  echo_color "34" "[running] " -n
  echo "'${exec} $@'"
  
  result=$(${exec} "$@")
  
  echo_color "34" "[expect] " -n
  echo "'${expect}'"

  echo_color "34" "[result] " -n
  echo "'${result}'"
  if [[ "${expect}" ==  "${result}" ]]; then
    echo_color "32" "Success!"
    success_score=$((++success_score))
  else
    echo_color "31" "Failed"
  fi
  total_test=$((++total_test))
  # expr is too slow
}

# expression
test "lots of space" "0" "XOR(  63 ,   63)"
test "separator" "44290" "AND(0xff_0f, 0b1010_1101_1111_0010)"
test "Whats this express?" "255" "OR(0 x f0 ) 0b 0000 1111,"

# immediate
test "immediate: HEX" "255" "0xFf"
test "immediate: DEC" "100" "100"
test "immediate: BIN" "8" "0b1000"
test "immediate: OCT1" "62" "076"
test "immediate: OCT2" "34" "0o42"
test "out of range: HEX" "Invalid character in immediate value" "0xg"
test "out of range: DEC" "Invalid character in immediate value" "a00"
test "out of range: BIN" "Invalid character in immediate value" "0b2022"
test "out of range: OCT" "Invalid character in immediate value" "0o8"

# error check
test "wrong XOR statement" "Unexpected NULL character" "XOR(127"

# opecode
test "simple AND" "5" "AND(0b1101, 0b0111)"
test "simple  OR" "15" "OR(0b0101, 0b1010)"
test "simple XOR" "0" "XOR(63, 63)"
# test "simple NOT" "0" "NOT(15)"


echo_color "30;42" "test done! (${success_score}/${total_test}) "
