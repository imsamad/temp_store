import NextAuth, { NextAuthOptions } from 'next-auth';
import GoogleProvider from 'next-auth/providers/google';
import CredentialsProvider from 'next-auth/providers/credentials';

const show = !false;

export const authOptions: NextAuthOptions = {
  providers: [
    GoogleProvider({
      clientId: process.env.GOOGLE_ID,
      clientSecret: process.env.GOOGLE_SECRET,
    }),
    // CredentialsProvider({
    //   name: 'Credentials',
    //   credentials: {
    //     username: { label: 'Username', type: 'text', placeholder: 'jsmith' },
    //     password: { label: 'Password', type: 'password' },
    //   },
    //   // @ts-ignore
    //   async authorize(credentials, req) {
    //     console.log(credentials);
    //     // Return null if user data could not be retrieved
    //     return { name: 'abduss Samd ', credentials: 'credentials' };
    //   },
    // }),
  ],
  theme: {
    colorScheme: 'light',
  },
  // secret: process.env.NEXTAUTH_SECRET,
  callbacks: {
    async redirect(props) {
      //  It is called if not signin
      console.log('0.0 redirect');
      if (show) console.log(props);
      const { url, baseUrl } = props;
      if (url.startsWith('/')) return `${baseUrl}${url}`;
      if (new URL(url).origin === baseUrl) return url;
      return baseUrl;
    },

    async signIn(props) {
      const { user, account, profile, email, credentials } = props;
      console.log('0.1 signIn');
      if (show) console.log(props);
      return true;
    },

    async jwt(props) {
      const { token, user, account, profile, isNewUser, trigger } = props;
      console.log('2 jwt');
      if (show) console.log(props);

      token.userRole = 'admin';
      token.addedFromJwt = 'addedFromJwt';
      return token;
    },

    async session(props) {
      const { session, user, token } = props;
      console.log('3 session');
      if (show) console.log(props);
      return { ...session, hello: 'helli' };
    },
  },
};

export default NextAuth(authOptions);

// Post sign in flow
// signIn -> redirect -> jwt -> session
/*
all data of sign_in passed down to jwt ={ ...signIn, isNewUser, token==signIn.user{but id rename to sub and image is rename to picture}};

*/
/*0.1 signIn  {
  user: {
    id: '106790236276250654157',
    name: 'Abdus Samad',
    email: 'imsamad00@gmail.com',
    image: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c'
  },
  account: {
    provider: 'google',
    type: 'oauth',
    providerAccountId: '106790236276250654157',
    access_token: 'ya29.a0AWY7CknZtIZ6nZ6S5QDpYQg9VBVmIaiZmZ58SV7mR9Ci-xxaIdIHHj9heIF54EBCM2_LNUYoxAK1mu3zwPk6BrOx00nmJsnfexljakLWMEHroq9TLsg3x6PgtdQaQWvFmtBmAi2oS_XI9KBLMGs2sxvuf0DbaCgYKAZMSARASFQG1tDrpJYSqGgTogH9arOyqHxB-9Q0163',
    expires_at: 1685974376,
    scope: 'openid https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile',
    token_type: 'Bearer',
    id_token: 'eyJhbGciOiJSUzI1NiIsImtpZCI6IjYwODNkZDU5ODE2NzNmNjYxZmRlOWRhZTY0NmI2ZjAzODBhMDE0NWMiLCJ0eXAiOiJKV1QifQ.eyJpc3MiOiJodHRwczovL2FjY291bnRzLmdvb2dsZS5jb20iLCJhenAiOiI2OTk4OTgzODQ3NC1wa25mcTE3ZTB2bXVwbzBvZDR1dG1paDRocmg4ODVnaS5hcHBzLmdvb2dsZXVzZXJjb250ZW50LmNvbSIsImF1ZCI6IjY5OTg5ODM4NDc0LXBrbmZxMTdlMHZtdXBvMG9kNHV0bWloNGhyaDg4NWdpLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwic3ViIjoiMTA2NzkwMjM2Mjc2MjUwNjU0MTU3IiwiZW1haWwiOiJpbXNhbWFkMDBAZ21haWwuY29tIiwiZW1haWxfdmVyaWZpZWQiOnRydWUsImF0X2hhc2giOiJ5TDRRUFJ0bXBYbmJWNkRZRnR5cEhBIiwibmFtZSI6IkFiZHVzIFNhbWFkIiwicGljdHVyZSI6Imh0dHBzOi8vbGgzLmdvb2dsZXVzZXJjb250ZW50LmNvbS9hL0FBY0hUdGNKWUpiX1YzeTNGc0ZTUDNyTVhHRlY1YnQ1U2JGaWN6ZHdIb0w0PXM5Ni1jIiwiZ2l2ZW5fbmFtZSI6IkFiZHVzIiwiZmFtaWx5X25hbWUiOiJTYW1hZCIsImxvY2FsZSI6ImVuLUdCIiwiaWF0IjoxNjg1OTcwNzc3LCJleHAiOjE2ODU5NzQzNzd9.uZVpnu1VjGSdn3VlelTX8ASKtIHBN4KX8K6kqqhkYdNr74ASg_AIXrEQ8q3aGbEUawFlY8Yen4YfefNpMoy8nsOzUVMMLuoLt4I3cqIwkjIlU1fVxOR5AMP68LBP6KadXQz3Ky8UW6BCmH3j66-tied45qpzqByw1PsJ4C5j0wKh-1WOqbk7rWR4SRsKnlE0YQmMilkDzMnsHjIyG_rDa5KOpKhol5UcgpFGBdIhFAVLAAWhTLCM38hnbQT0oCQhtpiE_s1Y9Tm0V4eFMF19RRhTMFg7igLvP7swLZPvcs0mnLOzQfwOUc6nb7nRFCVIi0iG-7rzIWfxY5ogfOFiXg'
  },
  profile: {
    iss: 'https://accounts.google.com',
    azp: '69989838474-pknfq17e0vmupo0od4utmih4hrh885gi.apps.googleusercontent.com',
    aud: '69989838474-pknfq17e0vmupo0od4utmih4hrh885gi.apps.googleusercontent.com',
    sub: '106790236276250654157',
    email: 'imsamad00@gmail.com',
    email_verified: true,
    at_hash: 'yL4QPRtmpXnbV6DYFtypHA',
    name: 'Abdus Samad',
    picture: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c',
    given_name: 'Abdus',
    family_name: 'Samad',
    locale: 'en-GB',
    iat: 1685970777,
    exp: 1685974377
  }
}

*/

/*
2 jwt  {
  token: {
    name: 'Abdus Samad',
    email: 'imsamad00@gmail.com',
    picture: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c',
    sub: '106790236276250654157'
  },
  user: {
    id: '106790236276250654157',
    name: 'Abdus Samad',
    email: 'imsamad00@gmail.com',
    image: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c'
  },
  account: {
    provider: 'google',
    type: 'oauth',
    providerAccountId: '106790236276250654157',
    access_token: 'ya29.a0AWY7CknZtIZ6nZ6S5QDpYQg9VBVmIaiZmZ58SV7mR9Ci-xxaIdIHHj9heIF54EBCM2_LNUYoxAK1mu3zwPk6BrOx00nmJsnfexljakLWMEHroq9TLsg3x6PgtdQaQWvFmtBmAi2oS_XI9KBLMGs2sxvuf0DbaCgYKAZMSARASFQG1tDrpJYSqGgTogH9arOyqHxB-9Q0163',
    expires_at: 1685974376,
    scope: 'openid https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile',
    token_type: 'Bearer',
    id_token: 'eyJhbGciOiJSUzI1NiIsImtpZCI6IjYwODNkZDU5ODE2NzNmNjYxZmRlOWRhZTY0NmI2ZjAzODBhMDE0NWMiLCJ0eXAiOiJKV1QifQ.eyJpc3MiOiJodHRwczovL2FjY291bnRzLmdvb2dsZS5jb20iLCJhenAiOiI2OTk4OTgzODQ3NC1wa25mcTE3ZTB2bXVwbzBvZDR1dG1paDRocmg4ODVnaS5hcHBzLmdvb2dsZXVzZXJjb250ZW50LmNvbSIsImF1ZCI6IjY5OTg5ODM4NDc0LXBrbmZxMTdlMHZtdXBvMG9kNHV0bWloNGhyaDg4NWdpLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwic3ViIjoiMTA2NzkwMjM2Mjc2MjUwNjU0MTU3IiwiZW1haWwiOiJpbXNhbWFkMDBAZ21haWwuY29tIiwiZW1haWxfdmVyaWZpZWQiOnRydWUsImF0X2hhc2giOiJ5TDRRUFJ0bXBYbmJWNkRZRnR5cEhBIiwibmFtZSI6IkFiZHVzIFNhbWFkIiwicGljdHVyZSI6Imh0dHBzOi8vbGgzLmdvb2dsZXVzZXJjb250ZW50LmNvbS9hL0FBY0hUdGNKWUpiX1YzeTNGc0ZTUDNyTVhHRlY1YnQ1U2JGaWN6ZHdIb0w0PXM5Ni1jIiwiZ2l2ZW5fbmFtZSI6IkFiZHVzIiwiZmFtaWx5X25hbWUiOiJTYW1hZCIsImxvY2FsZSI6ImVuLUdCIiwiaWF0IjoxNjg1OTcwNzc3LCJleHAiOjE2ODU5NzQzNzd9.uZVpnu1VjGSdn3VlelTX8ASKtIHBN4KX8K6kqqhkYdNr74ASg_AIXrEQ8q3aGbEUawFlY8Yen4YfefNpMoy8nsOzUVMMLuoLt4I3cqIwkjIlU1fVxOR5AMP68LBP6KadXQz3Ky8UW6BCmH3j66-tied45qpzqByw1PsJ4C5j0wKh-1WOqbk7rWR4SRsKnlE0YQmMilkDzMnsHjIyG_rDa5KOpKhol5UcgpFGBdIhFAVLAAWhTLCM38hnbQT0oCQhtpiE_s1Y9Tm0V4eFMF19RRhTMFg7igLvP7swLZPvcs0mnLOzQfwOUc6nb7nRFCVIi0iG-7rzIWfxY5ogfOFiXg'
  },
  profile: {
    iss: 'https://accounts.google.com',
    azp: '69989838474-pknfq17e0vmupo0od4utmih4hrh885gi.apps.googleusercontent.com',
    aud: '69989838474-pknfq17e0vmupo0od4utmih4hrh885gi.apps.googleusercontent.com',
    sub: '106790236276250654157',
    email: 'imsamad00@gmail.com',
    email_verified: true,
    at_hash: 'yL4QPRtmpXnbV6DYFtypHA',
    name: 'Abdus Samad',
    picture: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c',
    given_name: 'Abdus',
    family_name: 'Samad',
    locale: 'en-GB',
    iat: 1685970777,
    exp: 1685974377
  },
  isNewUser: undefined,
  trigger: 'signIn'
}
*/

/*
3 session_cb  {
  session: {
    user: {
      name: 'Abdus Samad',
      email: 'imsamad00@gmail.com',
      image: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c'
    },
    expires: '2023-07-05T13:12:58.580Z'
  },
  token: {
    name: 'Abdus Samad',
    email: 'imsamad00@gmail.com',
    picture: 'https://lh3.googleusercontent.com/a/AAcHTtcJYJb_V3y3FsFSP3rMXGFV5bt5SbFiczdwHoL4=s96-c',
    sub: '106790236276250654157',
    userRole: 'admin',
    addedFromJwt: 'addedFromJwt',
    iat: 1685970777,
    exp: 1688562777,
    jti: '2435a995-7cdc-4d74-8392-12c642f584c5'
  }
}


*/

/*
0 redirect  { url: 'http://localhost:3000/', baseUrl: 'http://localhost:3000' }

*/
