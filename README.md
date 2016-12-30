# Tmlang
LOCAL学生部総大会2016 自作言語ハッカソンで作った誰得言語です。

## 特徴

- アセンブラを彷彿とさせる面倒くさい構文

## Usage
bin/tmlang.bin [source]

## functions

命令 | 動作
--- | ---
put [文字列] | 文字列を出力
print | メモリの値を出力
int [変数名] | 変数を作成
set [値] | メモリに値をセット
load [変数名] | 変数の値をメモリに読み込む
save [変数名] | メモリの値を変数に保存
上記にない命令 | 🍣を出力

## 構文

```
[命令] [対応する引数]
```

または

```
[命令]([対応する引数])
```

## Hello,world

```
put Hello,world
```

## 利点
ありません
