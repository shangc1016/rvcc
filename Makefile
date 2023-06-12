# 编译参数
# - 使用C11标准
# - 生成debug信息
# - 禁止将未初始化的全局变量放到common段
CFLAGS=-std=c11 -g -fno-common

# 指令C的编译器
CC=clang



# 生成最终的二进制文件
rvcc: main.o
	$(CC) -o rvcc $(CFLAGS) main.o


# 运行测试脚本
# @不会打印这个命令本身
test: rvcc
	@./test.sh


clean:
	rm -f rvcc *.o *.s tmp* a.out