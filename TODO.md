上に行くほど優先度が高い

[-] 文字列の読み込み→実行
[-] n進数prefix 0b1010, 0x7F/0x7f
[-] インタプリタ
[ ] NOTの挙動を考える
    普通にやると、64ビット分NOTされてしまう
    → いい感じに下位nビットを取り出さなければならない
    0xf0f0をNOTしたら0x0f0fにする？
    0のNOTは？？
[ ] 変数などの実装
  - システム変数 $INPUT
  - システム関数 RAND(MIN,MAX)
[ ] 自作関数の実装
  - VAL=OR(0x0f, AND($INPUT, 0xf0))
[ ] ()以外の対応
  AND OR XOR 10 , 20 , 15 , 8
  => AND(OR(XOR(10, 20), 15), 8)
  これいる？
[ ] enum result_stat実装（RESULT_SUCCESS, RESULT_WRONG_CHARなど）
[ ] エラー出力を1箇所に
