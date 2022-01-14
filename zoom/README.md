zoom.cc 程序依赖 `SDL`, 须先配置 `SDL`的 `includePath`

pc: mac
ide: vscode

- 安装 sdl2

```
brew install sdl2
```

- 配置 `includePath` (vscode)

`command+shift+p` 输入或选择 `c/cpp edit configurations...` 生成 c_cpp_properties.json

`includePath` 中添加 `/usr/local/Cellar/sdl2/$version/include`

### 生成 wasm

```
  emcc zoom.cc -Os -o zoom.html
```
