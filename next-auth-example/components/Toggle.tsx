import { useSession } from "next-auth/react";
import React from "react";

const Toggle = () => {
  const { data, ...rest } = useSession();
  console.log(JSON.stringify(rest));
  return <pre>{JSON.stringify(data, null, 4)}</pre>;
};

export default Toggle;
