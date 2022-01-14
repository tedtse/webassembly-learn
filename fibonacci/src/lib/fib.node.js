const fs = require('fs');

const fib = (n) => {
  if (n == 1 || n == 2) {
    return 1;
  }
  return fib(n - 2) + fib(n - 1);
};

console.time("fibonacci env node js");
fib(40);
console.timeEnd("fibonacci env node js");

const buff = fs.readFileSync('./fib.wasm')
WebAssembly.instantiate(new Uint8Array(buff))
  .then(res => {
    const { fibo } = res.instance.exports
    console.time("fibonacci env node wasm");
    fibo(40);
    console.timeEnd("fibonacci env node wasm");
  })