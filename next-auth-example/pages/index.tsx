import { useState } from "react";
import Layout from "../components/layout";
import Toggle from "../components/Toggle";

export default function IndexPage() {
  const [show, setShow] = useState(false);
  return (
    <Layout>
      <h1
        style={{
          border: "1px solid red",
        }}
        onClick={() => {
          setShow((p) => !p);
        }}
      >
        NextAuth.js Example
      </h1>
      {show ? <Toggle /> : null}
      <p>
        This is an example site to demonstrate how to use{" "}
        <a href="https://next-auth.js.org">NextAuth.js</a> for authentication.
      </p>
    </Layout>
  );
}
