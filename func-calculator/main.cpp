#include <iostream>
#include "calculator.cpp"

int main()
{
  std::string input;
  while (true)
  {
    std::cout << "cal-> ";
    std::getline(std::cin, input);
    Interpreter inpr(input);
    inpr.expr().print();
  }
}