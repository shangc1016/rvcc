#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "%s : invalid number of arguments\n", argv[0]);
    return 1;
  }

  // p保存算式的string
  char *p = argv[1];

  // 声明一个全局main段，同时也是程序的入口
  printf("  .global main\n");
  // main段开始的标签
  printf("main:\n");

  // strtol(): string to long
  //第一步：解析"1+2-3"中的第一个数字
  printf("  li a0, %ld\n", strtol(p, &p, 10));

  // 循环，解析后面的带符号的部分
  while (*p) {
    if (*p == '+') {
      p++;
      printf("  addi a0, a0, %ld\n", strtol(p, &p, 10));
      continue;
    }

    // note:
    // riscv中没有subi(减立即数)，所以如果是减法、也就是加上一个有符号的数字
    // riscv支持addi的操作数为有符号数字，直接前面加个负号就行了
    if (*p == '-') {
      p++;
      printf("  addi a0, a0, -%ld\n", strtol(p, &p, 10));
    }
  }

  // 最后一步，return
  printf("  ret\n");

  return 0;
}