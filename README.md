# binlang - basic bit operation with interactive terminal

データ構造とアルゴリズム A（2 年次開講）のレポート課題

## example

See `test.sh`.

```
>> OR(NOT(8), 16)
23
```

## 構文

すべては exp であること

OR(NOT(8), 16) => code(code(IMM),IMM)

```
exp  = val
val  = IMM | code(val[,val]*)
IMM  = 0-9*
code = AND | OR | XOR | NOT
```

## LICENSE

Dual-licensed; MIT (`LICENSE-MIT` or [The MIT License – Open Source Initiative](https://opensource.org/license/mit/)) or MIT SUSHI-WARE LICENSE (`LICENSE-MIT_SUSHI.md`)
