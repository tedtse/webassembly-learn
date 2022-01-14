#include <iostream>

using namespace std;

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

EM_PORT_API(const char *)
getString()
{
  static const char str[] = "Hello, my name is Li Lei";
  return str;
}

EM_PORT_API(void)
printString(char *str)
{
  cout << "From js: " << str << endl;
}