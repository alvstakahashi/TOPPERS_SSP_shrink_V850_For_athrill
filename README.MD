DockerHubバージョン対応<br>
issue1の指摘対応<br>

athrill での動作確認済み<br>

#athrill -i -d device_config.txt -m memory.txt test_main.elf<br>
で起動してください。

手順について<br>
Windows10Pro64bit にて確認したためその手順の記載しています。<br>

1.以下のサイトで、athrillを起動してみてください<br>
　TOPPERS/athrillをdockerで利用できるようにするまで<br>
　https://qiita.com/kanetugu2018/items/f1368a6da7bdc773cfd9 <br>

　DockerHUbにてビルド環境およびathrill本体さらにサンプルアプリケーションが<br>
　ビルド済みで組み込まれています。　上記サイトの手順のとおりに<br>
　WSLとDockerのセットアップを行う必要があります。<br>


2.本ソースを取り込んで実行方法<br>
　本ソースをクローンもしくはダウンロードし、例えば<br>
　D:/usr2/  <br>
  にダウンロードしておきます。<br>

　PowerShellから以下を実行<br>
　
　PS C:\WINDOWS\system32> docker run -v /D/usr2:/usr2 -it kanetugu2015/athrill_asp3:ver3.0 <br>
  
  #cd /usr2/TOPPERS_SSP_shrink_V850_For_athrill\V850-SSP-SHR <br>
  #make <br>
  #athrill -i -d device_config.txt -m memory.txt test_main.elf <br>

例)<br>
PS C:\WINDOWS\system32><br>
PS C:\WINDOWS\system32> docker run -v /D/usr2:/usr2 -it kanetugu2015/athrill_asp3:ver3.0 <br>
root@a6b478c50e79:/# cd /usr2 <br>
root@a6b478c50e79:/usr2# cd V850-SSP-SHR <br>
root@a6b478c50e79:/usr2/V850-SSP-SHR# athrill -i -d device_config.txt -m memory.txt  test_main.elf <br>
core id num=0<br>
ROM : START=0x0 SIZE=512<br>
RAM : START=0x6ff7000 SIZE=512<br>
Elf loading was succeeded:0x0 - 0x32e7 : 12.743 KB<br>
Elf loading was succeeded:0x32e8 - 0x41fc : 0.0 KB<br>
Elf loading was succeeded:0x41fc - 0x4afc : 2.256 KB<br>
ELF SYMBOL SECTION LOADED:index=16<br>
ELF SYMBOL SECTION LOADED:sym_num=195<br>
ELF STRING TABLE SECTION LOADED:index=17<br>
[DBG>[NEXT> pc=0x0 vector.S 9<br>
c<br>
[CPU>WARNING: Found invalid data write on not variable region(addr=0x6ff75f2 size=1) : bss_clear(0x166a)@_kernel_stack <br>
WARNING: Found invalid data write on not variable region(addr=0x6ff75f3 size=1) : bss_clear(0x166a)@_kernel_stack <br>
WARNING: Found invalid data write on not variable region(addr=0x6ff7efe size=1) : bss_clear(0x166a)@_kernel_stack <br>
WARNING: Found invalid data write on not variable region(addr=0x6ff7eff size=1) : bss_clear(0x166a)@_kernel_stack <br>
task1----------------- <br>
task2 RUNNING----------------------------------------------------- <br>
TASK2 <br>
task1----------------- <br>
^C <br>
root@a6b478c50e79:/usr2/V850-SSP-SHR# <br>

そのほか：<br>
PCの環境設定は、<br>
Windows10pro64bitの環境設定の説明.txt <br>
を参照ください。<br>

以上　2020.8.12追記 <br>



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

以下のように出ればOKです　<br>
D:\DEV\V850-SSP-HM\GIT\TOPPERS_SSP_shrink_V850_For_athrill\V850-SSP-SHR>athrill -i -d device_config.txt -m memory.txt test_main.elf<br>
core id num=0<br>
ROM : START=0x0 SIZE=512<br>
RAM : START=0x6ff7000 SIZE=512<br>
WARNING: unknown memory type=MMAP<br>
Elf loading was succeeded:0x0 - 0x2f2f : 11.815 KB<br>
Elf loading was succeeded:0x2f30 - 0x4340 : 0.0 KB<br>
Elf loading was succeeded:0x4340 - 0x4740 : 1.0 KB<br>
ELF SYMBOL SECTION LOADED:index=17<br>
ELF SYMBOL SECTION LOADED:sym_num=194<br>
ELF STRING TABLE SECTION LOADED:index=18<br>
search_region:not found error:addr=0x7ff0000<br>
[DBG><br>
HIT break:0x0<br>
[NEXT> pc=0x0 vector.S 9<br>
c<br>
[CPU>WARNING: Found invalid data write on not variable region(addr=0x6ff75f2 size=1) : bss_clear(0x144e)@stack_data<br>
WARNING: Found invalid data write on not variable region(addr=0x6ff75f3 size=1) : bss_clear(0x144e)@stack_data<br>
WARNING: Found invalid data write on not variable region(addr=0x6ff83fe size=1) : bss_clear(0x144e)@stack_data<br>
WARNING: Found invalid data write on not variable region(addr=0x6ff83ff size=1) : bss_clear(0x144e)@stack_data<br>
task1-----------------<br>
task2 RUNNING-----------------------------------------------------<br>
TASK2<br>
task1-----------------<br>
TASK2 OFF<br>
task1-----------------<br>
TASK2<br>
task1-----------------<br>
task1-----------------<br>
TASK2 OFF<br>
task1-----------------<br>
TASK2<br>
task1-----------------<br>
TASK2 OFF<br>
task1-----------------<br>
task1-----------------<br>
TASK2<br>
task1-----------------<br>
TASK2 OFF<br>
task1-----------------<br>

---------------------------------------------------------------<br>
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
