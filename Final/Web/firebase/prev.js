firebase.initializeApp(config);

const db = firebase.firestore();

let xyzCollRef = db.collection('xyz');

if (query) {
  xyzDocsRef += xyzDocsRef.where('city', '===', 'Agra');
}
if (orderBy) {
  xyzDocsRef += xyzCollRef.orderBy('name');
}

xyzCollRef.onSnapshot((snapshot) => {
  const changes = snapshot.docChanges();
  changes.forEach((change) => {
    const changeType = change.type; //added|removed
    const doc = { data: change.doc.data(), id: change.doc.id };
  });
});

let xyzDocsRef = xyzCollRef.get().then((snapshopt) => {
  return snapshot.docs;
});

let xyzDocs = xyzDocsRef.map((doc) => ({ data: doc.data(), id: doc.id }));

xyzCollRef.add({
  one: 'one',
  two: two,
});

let singleDocById = xyzCollRef.doc('docId');

//Delete
singleDocById.delete();
