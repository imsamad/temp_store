const pro = () => {
  const p1 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The first promise has resolved");

      resolve(10);
    }, 3 * 1000);
  });
  const p2 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The second promise has resolved");
      resolve(20);
    }, 2 * 1000);
  });
  const p3 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The third promise has resolved");
      resolve(30);
    }, 1 * 1000);
  });

  Promise.race([p1, p2, p3]).then((results) => {
    // const total = results.reduce((p, c) => p + c);

    console.log(`Is Type of Results is Array : ${Array.isArray(results)}`);
    console.log(`Type of Results: ${typeof results}`);
    console.log(`Results: ${results}`);
    // console.log(`Total: ${total}`);
  });
};
// pro();

const promiseWithRejection = () => {
  const p1 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The first promise has resolved");
      resolve(10);
    }, 1 * 1000);
  });
  const p2 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The second promise has rejected");
      reject("FailedFromSecond");
    }, 2 * 1000);
  });
  const p3 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The third promise has resolved");
      resolve(30);
    }, 3 * 1000);
  });

  Promise.all([p1, p2, p3])
    .then((val) => {
      console.log("Then");
      console.log(val);
    }) // never execute
    .catch((err) => {
      console.log("Error");
      console.log(err);
    });
};
// promiseWithRejection();

const promiseRaceWithRejection = () => {
  const p1 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The first promise has resolved");
      resolve(10);
    }, 2 * 1000);
  });

  const p2 = new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("The second promise has rejected");
      reject(20);
    }, 1 * 1000);
  });

  Promise.race([p1, p2])
    .then((value) => {
      console.log("Then");
      console.log(`Resolved: ${value}`);
    })
    .catch((reason) => {
      console.log("Catch");
      console.log(`Rejected: ${reason}`);
    });
};
promiseRaceWithRejection();
