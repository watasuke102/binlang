# binlang - basic bit operation with interactive terminal

`TODO.md`を参照すること

## example
```
>> OR(NOT(8), 16)
23
```

## 構文

すべてはexpであること

OR(NOT(8), 16) => code(code(IMM),IMM)


```
exp  = val
val  = IMM | code(val[,val]*)
IMM  = 0-9*
code = AND | OR | XOR | NOT
```

## LICENSE
MIT LICENSE
