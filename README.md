# hn-toolkits-c

![C](https://img.shields.io/badge/Language-C-blue.svg)
![xmake](https://img.shields.io/badge/Build-xmake-orange.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

个人 C 语言练习工具库。使用xmake和clang构建。部分文件使用C23新特性。

## 使用方法

使用xmake

```bash

git clone --depth 1 https://github.com/hnchengzong/hn-toolkits-c.git
cd ./hn-toolkits-c

# 在VSCode中生成配置文件
xmake project -k compile_commands

# 构建(只有主程序)
xmake build

# 构建并运行主程序main.c
xmake run

# 构建并运行指定测试
xmake run test_name # e.g. xmake run test_simple_sort

# 切换到构建/调试模式
xmake f -m debug
xmake f -m release

# 构建动态链接库，在build/lib中
xmake build hn-toolkits-lib

```

## 项目结构

`include`存放各种头文件；`src/lib`是对头文件的实现；`tests`是相应库的测试文件。
默认构建到`build`中，`tests`的文件被构建到`build/tests`中，分为`debug`和`release`两个文件夹。构建的动态链接库在`build/lib`中。
