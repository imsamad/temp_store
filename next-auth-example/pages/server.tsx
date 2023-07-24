import { getServerSession } from 'next-auth/next';
import { authOptions } from './api/auth/[...nextauth]';
import Layout from '../components/layout';

import type { GetServerSidePropsContext } from 'next';
import type { Session } from 'next-auth';
import { getToken } from 'next-auth/jwt';
import { getProviders } from 'next-auth/react';

export default function ServerSidePage({ session }: { session: Session }) {
  // As this page uses Server Side Rendering, the `session` will be already
  // populated on render without needing to go through a loading stage.

  console.log('session ', session);
  return (
    <Layout>
      <h1>Server Side Rendering</h1>
      <p>
        This page uses the <strong>getServerSession()</strong> method in{' '}
        <strong>getServerSideProps()</strong>.
      </p>
      <p>
        Using <strong>getServerSession()</strong> in{' '}
        <strong>getServerSideProps()</strong> is the recommended approach if you
        need to support Server Side Rendering with authentication.
      </p>
      <p>
        The advantage of Server Side Rendering is this page does not require
        client side JavaScript.
      </p>
      <p>
        The disadvantage of Server Side Rendering is that this page is slower to
        render.
      </p>
      <pre>{JSON.stringify(session, null, 2)}</pre>
    </Layout>
  );
}

// Export the `session` prop to use sessions with Server Side Rendering
export async function getServerSideProps(context: GetServerSidePropsContext) {
  const session = await getServerSession(context.req, context.res, authOptions);
  console.log('session s ', session);
  const token = await getToken({ req: context.req });

  console.log('token ', token);
  const providers = await getProviders();
  console.log('Providers', providers);
  return {
    props: {
      session,
    },
  };
}
