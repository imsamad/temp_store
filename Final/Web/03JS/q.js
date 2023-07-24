const Queue = function () {
  this.data = [];
};
Queue.prototype.enqueue = function (e) {
  return this.data.push(e);
};

Queue.prototype.dequeue = function () {
  return this.data.shift();
};
Queue.prototype.isEmpty = function () {
  return this.data.length === 0;
};
Queue.prototype.peek = function () {
  return this.isEmpty() ? undefined : this.data[0];
};
Queue.prototype.length = function () {
  return this.data.length;
};
const Q = new Queue();
for (let i = 0; i < 5; i++) {
  Q.enqueue((i + 1) * 10);
}
console.log("Peek ", Q.peek());
console.log("Length ", Q.length());
console.log("Dequeue ", Q.dequeue());
console.log("Peek ", Q.peek());
console.log("Length ", Q.length());
