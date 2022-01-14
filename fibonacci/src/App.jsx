import { useState, useEffect } from "react";
import "./App.css";
import fibModule from "./lib/fib.wasm";

function App() {
  const [count, setCount] = useState(0);
  useEffect(() => {
    fibModule().then((exports) => {
      console.log(exports);
      const { fibo } = exports;
      console.time("fibonacci env web wasm");
      fibo(40);
      console.timeEnd("fibonacci env web wasm");
    });

    const fib = (n) => {
      if (n == 1 || n == 2) {
        return 1;
      }
      return fib(n - 2) + fib(n - 1);
    };
    console.time("fibonacci env web js");
    fib(40);
    console.timeEnd("fibonacci env web js");
  }, []);

  return (
    <div className="App">
      <header className="App-header">
        <p>Hello Vite + React!</p>
        <p>
          <button type="button" onClick={() => setCount((count) => count + 1)}>
            count is: {count}
          </button>
        </p>
        <p>
          Edit <code>App.jsx</code> and save to test HMR updates.
        </p>
      </header>
    </div>
  );
}

export default App;
