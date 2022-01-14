#include <iostream>
#include "calculator.cpp"
#include <stdio.h>
using namespace std;

int main()
{
  Calculator<double> cal;
  char Infix[MAX_EXP_LEN], Postfix[MAX_EXP_LEN];
  gets(Infix);
  double sum;

  cal.Infix2Postfix(Infix, Postfix);
  sum = cal.Calculation(Postfix);
  printf("最终计算结果为：%f\n\n", sum);
  return 0;
}