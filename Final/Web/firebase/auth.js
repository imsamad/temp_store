import { initializeApp } from 'firebase/app';
import {
  getAuth,
  createUserWithEmailAndPassword,
  signOut,
  signInWithEmailAndPassword,
} from 'firebase/auth';

initializeApp(config);

const auth = getAuth();

const signUp = () => {
  createUserWithEmailAndPassword(auth, email, password).then((cred) => {});
};

const logout = () => {
  signOut(auth).then((cred) => {});
};

const signIn = () => {
  signInWithEmailAndPassword(auth, email, password).then((cred) => {});
};
