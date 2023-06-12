#!/bin/bash


# 声明函数
assert() {
    # 程序运行的期待值为参数1
    expected="$1"

    # 输入值为参数2
    input="$2"
    
    # 运行程序，传入期待值，将生成结果写入到tmp.s汇编文件
    # 如果运行不成功，则会执行exit退出，成功时这鬼短路exit操作
    ./rvcc $input > tmp.s || exit

    # 编译rvcc产生的汇编文件
    # clang -o tmp tmp.s
    riscv64-unknown-elf-gcc tmp.s -o tmp

    # 运行生成出来的目标文件
    # ./tmp
    qemu-riscv64-static tmp

    # 获得程序的返回值，存入实际值
    actual="$?"

    # 判断实际值是不是等于预期值
    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}


# 调用`assert <期待值> <传入值>`


#  commit1: 简单的返回一个数字
assert 0 0
assert 42 42


# commit2: 实现简单的加减运算(1-2+3)
assert 234 123-234+345

echo OK
