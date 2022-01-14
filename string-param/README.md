### 生成 wasm

```
emcc str-param.cpp -s EXPORTED_FUNCTIONS='["_malloc", "_free"]' -o str-param.js
```
