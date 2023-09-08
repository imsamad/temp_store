import { useEffect } from "react";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import About from "./compo/About";
import Home from "./compo/Home";
import Share from "./compo/Share";

const App = () => {
  return (
    <BrowserRouter>
      <Routes>
        <Route exact path="/" element={<Home />} />
        <Route exact path="/about" element={<About />} />
        <Route exact path="/share" element={<Share />} />
      </Routes>
    </BrowserRouter>
  );
};

export default App;
