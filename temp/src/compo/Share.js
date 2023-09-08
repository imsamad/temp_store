import { useEffect } from "react";

const IFRAME_LOADED_ORIGIN = `IFRAME_LOADED_ORIGIN`;
const Share = () => {
  const isRenderInIframe = window.top != window.self;

  useEffect(() => {
    console.log(`window.top `, window.top);
    console.log(`window.top.0 `, window.top["0"]);
    console.log(`window.self `, window.self);
    if (isRenderInIframe) {
      console.log("set pre-emptively");
      window.localStorage.setItem(
        IFRAME_LOADED_ORIGIN,
        window.self.location.ancestorOrigins[0]
      );
      console.log("set pre-emptively end");
    }
    if (!isRenderInIframe) return;
    console.log(`iframeLoadedListener was called`);

    window.addEventListener("message", function (e) {
      console.log(
        e.source.location.ancestorOrigins,
        `from iframeLoadedListener`,
        e.source.location.ancestorOrigins[0]
      );

      this.window.localStorage.setItem(
        IFRAME_LOADED_ORIGIN,
        e.source.location.ancestorOrigins[0]
      );

      console.log(`origin was saved in localStorage`);
    });
  }, []);
  const sendOriginBack = () => {
    console.log(`sendOriginBack was called`);
    if (!isRenderInIframe) return;
    const origin = localStorage.getItem(IFRAME_LOADED_ORIGIN);
    console.log("origin of iframe in localStorage ", origin);
    // if (origin)
    window.parent.postMessage("I m close", origin);
    console.log(`origin was sent back`);
  };
  return (
    <>
      {isRenderInIframe && (
        <button
          onClick={() => sendOriginBack()}
          style={{
            padding: "1rem 2rem",
            border: 0,
            outline: "none",
            margin: "2rem auto",
            backgroundColor: "aqua",
          }}
        >
          Close
        </button>
      )}
      <h1>Hello From Share Page</h1>
    </>
  );
};

export default Share;
