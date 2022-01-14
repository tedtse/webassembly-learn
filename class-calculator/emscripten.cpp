#include "calculator.cpp"

#ifndef EM_PORT_API
#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#if defined(__cplusplus)
#define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#else
#define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#endif
#else
#if defined(__cplusplus)
#define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#else
#define EM_PORT_API(rettype) rettype
#endif
#endif
#endif

struct StructCalc;

EM_PORT_API(struct StructCalc *)
createCalculator()
{
  Calculator<double> *calculator = new Calculator<double>();
  return (struct StructCalc *)calculator;
}

EM_PORT_API(double)
handleCalculation(struct StructCalc *structCalc, char *infix)
{
  char Infix[MAX_EXP_LEN], Postfix[MAX_EXP_LEN];
  strcpy(Infix, infix);
  Calculator<double> *calculator = (Calculator<double> *)structCalc;
  calculator->Infix2Postfix(Infix, Postfix);
  return calculator->Calculation(Postfix);
}