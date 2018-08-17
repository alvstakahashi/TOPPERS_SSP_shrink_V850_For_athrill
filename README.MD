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

8/17 追記---------------------------------------------------------
* タスク2つ　動作　印字がおかしいまま　Revisionでいったん完成

以下のように出ればOKです
D:\DEV\V850-SSP-HM\GIT\TOPPERS_SSP_shrink_V850_For_athrill\V850-SSP-SHR>athrill -i -d device_config.txt -m memory.txt test_main.elf
core id num=0
ROM : START=0x0 SIZE=512
RAM : START=0x6ff7000 SIZE=512
WARNING: unknown memory type=MMAP
Elf loading was succeeded:0x0 - 0x2f2f : 11.815 KB
Elf loading was succeeded:0x2f30 - 0x4340 : 0.0 KB
Elf loading was succeeded:0x4340 - 0x4740 : 1.0 KB
ELF SYMBOL SECTION LOADED:index=17
ELF SYMBOL SECTION LOADED:sym_num=194
ELF STRING TABLE SECTION LOADED:index=18
search_region:not found error:addr=0x7ff0000
[DBG>
HIT break:0x0
[NEXT> pc=0x0 vector.S 9
c
[CPU>WARNING: Found invalid data write on not variable region(addr=0x6ff75f2 size=1) : bss_clear(0x144e)@stack_data
WARNING: Found invalid data write on not variable region(addr=0x6ff75f3 size=1) : bss_clear(0x144e)@stack_data
WARNING: Found invalid data write on not variable region(addr=0x6ff83fe size=1) : bss_clear(0x144e)@stack_data
WARNING: Found invalid data write on not variable region(addr=0x6ff83ff size=1) : bss_clear(0x144e)@stack_data
task1-----------------
task2 RUNNING-----------------------------------------------------
TASK2
task1-----------------
TASK2 OFF
task1-----------------
TASK2
task1-----------------
task1-----------------
TASK2 OFF
task1-----------------
TASK2
task1-----------------
TASK2 OFF
task1-----------------
task1-----------------
TASK2
task1-----------------
TASK2 OFF
task1-----------------

---------------------------------------------------------------
task何某が0.5秒くらいで表示が増えていけばOKです。
文字が2重になる問題は、atrhillをビルドしなおしたら治りました。



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