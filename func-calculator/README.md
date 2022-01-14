### 生成 wasm

```
emcc emscripten.cpp -s EXPORTED_FUNCTIONS='["_malloc"]' -o calculator.js
```

### 生成 exe

```
g++ main.cpp -o calculator.exe
```
