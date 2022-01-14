import { useState } from "react";
import { createFFmpeg, fetchFile } from "@ffmpeg/ffmpeg";
import "./App.css";

function App() {
  const [videoSrc, setVideoSrc] = useState();
  const ffmpeg = createFFmpeg({ log: true });
  const doTransCode = async () => {
    const [source, target] = ["video-3s.avi", "video-3s.mp4"];
    // const [source, target] = ["tiaoyinshi.mkv", "tiaoyinshi.mp4"];
    await ffmpeg.load();
    ffmpeg.FS("writeFile", source, await fetchFile("/videos/video-3s.avi"));
    await ffmpeg.run("-i", source, target);
    const data = ffmpeg.FS("readFile", target);
    setVideoSrc(
      URL.createObjectURL(new Blob([data.buffer], { type: "video/mp4" }))
    );
  };

  return (
    <div className="App">
      <header className="App-header">
        <p>Hello Vite + React!</p>
        <p>
          <video src={videoSrc} autoPlay controls></video>
        </p>
        <p>
          <button type="button" onClick={doTransCode}>
            start
          </button>
        </p>
      </header>
    </div>
  );
}

export default App;
