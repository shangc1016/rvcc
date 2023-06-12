#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s : invalid number of arguments\n", argv[0]);
        return 1;
    }

    // 声明一个全局main段，同时也是程序的入口
    printf("  .global main\n");
    // main段开始的标签
    printf("main:\n");
    // li(load instance)为addi的别名指令，加载立即数
    printf("  li a0, %d\n", atoi(argv[1]));
    // ret指令是jalr x0, x1, 0 指令的别名，用于子程序的返回
    printf("  ret\n");

    return 0;
}