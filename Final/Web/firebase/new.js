import { initializeApp } from 'firebase/app';
import {
  getFirestore,
  collection,
  getDocs,
  getDoc,
  addDoc,
  doc,
  deleteDoc,
  onSnapshot,
  query,
  where,
  orderBy,
  serverTimestamp,
  updateDoc,
} from 'firebase/firestore';
const config = {};
const createdAt = serverTimestamp();

initializeApp(config);
// firebase.initializeApp(config);

const db = getFirestore();
//const db=firestore.firestore()

let collRef = collection(db, 'xyz');
// const collRef=db.collection('xyz)

if (qu)
  collRef += query(collRef, where('city', '===', 'petrick'), orderBy('city'));

// Get coll data
const docsRef = getDocs(collRef).then((snapshot) => snapshot.docs);
// const docsRef=collRef.get().then(snapshot=>snapshot.docs)

const docs = docsRef.map((doc) => ({ data: doc.data(), id: doc.id }));

addDoc(collRef, { ...data }).then(() => {});
// collRef.add({...data}).then

const singleDocRefById = doc(dbRef, 'colName', 'docId');
// let singleDocRefById = xyzCollRef.doc('docId');

const singleDoc = getDoc(singleDocRefById).then((doc) => ({
  data: doc.data(),
  id: doc.id,
}));
//const singleDoc= singleDocRefById.get()
// Real Time the single Doc
onSnapshot(singleDocRefById, (doc) => {
  return {
    data: doc.data(),
    id: doc.id,
  };
});

updateDoc(docsRef, { ...newData }).then(() => {});

deleteDoc(singleDocRefById).then(() => {});
// singleDocRefById.delete()

const docsRef = onSnapshot(collRef).then((snapshot) => {
  return snapshot.docs;
  //   const changes = snapshot.onChanges();
  //   changes.forEach((change) => {
  //     const changeType = change.type;
  //     const doc = { data: change.doc.data(), id: change.doc.id };
  //   });
});
const docs = docsRef.map((doc) => ({ data: doc.data(), id: doc.id }));
