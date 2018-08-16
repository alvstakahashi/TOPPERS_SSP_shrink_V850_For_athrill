TOPPERS_SSPシュリンク版　V850移植

TOPPERS_SSP_shrink_V850_For_athrill


TOPPERS_SSPシュリンク版をV850に移植する。
ターゲットは、athrill という仮想マシン。

本リポジトリは、athrillのberametalコードから
TOPPERS_SSPシュリンクに移植していきます。
完成後、どのように変更したかが見えるかと思います。

2018.8.16現在、baremetalコードをタイマー割り込みのみ
追加したコードから開始します。

なぜか、表示文字が　

ttiimmeerr__iinntteerrrruupptt__hhaannddlleerr!!!!

のように　2重にプリントされる問題がありますが、
とりあえずやっていきます。


開発環境

Windows10 64bit
MinGW 32bit
V850 gcc KPIT

実行環境　athrill2  Windows版

目的（余談）
Raspberry piでのJTAGデバッグはあれはあれで意味があると思いますが
もっと簡単にOSを実行できる環境があったほうがいいと思ったからです。
CubeSuite+とかでRXでも可能ですが、あまりメーカーよりじゃなく
すべてオープンソースのほうがいいし、
athrillのほうが高機能でデバッグできそうな感じです。
まだよく使いこなせていません。　