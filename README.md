MiniGame_49
项目简介
一个基于C语言的控制台迷宫游戏，展示分支管理、协作开发等工程化能力。

游戏功能
控制角色 @ 在迷宫中移动

支持WASD键盘操作

跨平台兼容

快速开始
编译运行
cd src
gcc main.c game.c -o minigame
./minigame
操作说明
W - 上    A - 左
S - 下    D - 右
Q - 退出游戏
项目结构

src/
main.c     # 程序入口
game.c     # 游戏逻辑
game.h     # 头文件
分支说明
main - 稳定版本

dev - 开发分支

feature-ui - 界面功能

feature-core - 核心逻辑

许可证
MIT License
