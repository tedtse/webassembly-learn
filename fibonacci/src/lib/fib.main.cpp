#include <iostream>
#include <ctime>
#include "fib.lib.cpp"

using namespace std;

int main()
{
  int start, end, result;
  start = clock();
  result = fib(40);
  end = clock();
  cout << "result: " << result << "\n"
       << (double)(end - start) / 1000 << endl;
  return 0;
}