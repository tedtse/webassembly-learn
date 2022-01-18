### 生成 wasm

```
cd src/lib

emcc fib.emscripten.cpp -s WASM=1 -s SIDE_MODULE=1 -Os -o fib.wasm
```

### 生成 exe

```
cd src/lib

g++ fib.main.cpp -Os -o fib.exe
```

### 运行结果

| web js  | web wasm | node js | node wasm | c++ native |
| ------- | -------- | ------- | --------- | ---------- |
| 1000ms+ | 600ms+   | 1000ms+ | 400ms+    | 200ms+     |
