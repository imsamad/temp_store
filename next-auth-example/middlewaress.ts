import { withAuth } from "next-auth/middleware";
import { authOptions } from "./pages/api/auth/[...nextauth]";

// More on how NextAuth.js middleware works: https://next-auth.js.org/configuration/nextjs#middleware
export default withAuth({
  // @ts-ignore
  jwt: { decode: authOptions.jwt },
  callbacks: {
    authorized({ req, token }) {
      console.log("logg from mdlwr authorised ", { req, token });
      if (req.nextUrl.pathname === "/admin") {
        return token?.userRole === "admin";
      }
      // `/me` only requires the user to be logged in
      return !!token;
    },
  },
});

export const config = { matcher: ["/admin", "/me"] };
