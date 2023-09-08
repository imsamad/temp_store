import React from "react";

const cb = () => {
  let token = `eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJuYW1lIjoiYSBzYW1hZCIsImVtYWlsIjoiYXNkZXZscHIxMjA2QGdtYWlsLmNvbSIsInBpY3R1cmUiOiJodHRwczovL2xoMy5nb29nbGV1c2VyY29udGVudC5jb20vYS9BQWNIVHRmdjlwUmIxc1ZySFliNDNXalByNkljc0M2RDNvbmUwMHgzeGhobDJWcz1zOTYtYyIsInN1YiI6IjY0Y2Y1MGQ2ODhkYTFmNjJjZWM4MWVjZCIsInVzZXJSb2xlIjoiYWRtaW4iLCJhZGRlZEZyb21Kd3QiOiJhZGRlZEZyb21Kd3QiLCJpYXQiOjE2OTEzMDgyNDZ9.K1-45DuAcscjku3m7svIqr3L6BEFCq2izewTufI75Mc`;

  return <h1>cb :- {token.split(".").length}</h1>;
};

export default cb;
