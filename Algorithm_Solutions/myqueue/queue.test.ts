import { MyQueue } from "./queue";

const q = new MyQueue<string>(5);

console.log(q.isEmpty() === true);
console.log(q.isFull() === false);
console.log(q.size() === 0);
console.log(typeof q.dequeue() === "undefined");
console.log(typeof q.peek() === "undefined");

q.enqueue("a");
console.log(q.isEmpty() === false);
console.log(q.isFull() === false);
console.log(q.size() === 1);
console.log(q.peek() === "a");
console.log(q.dequeue() === "a");
console.log(q.size() === 0);

q.enqueue("a");
q.enqueue("b");
q.enqueue("c");
q.enqueue("d");
q.enqueue("e");

try {
  q.enqueue("f");
} catch (ex) {
  console.log(ex);
}

console.log(q.isEmpty() === false);
console.log(q.isFull() === true);
console.log(q.size() === 5);
console.log(q.peek() === "a");
console.log(q.dequeue() === "a");
console.log(q.size() === 4);
console.log(q.peek() === "b");
console.log(q.dequeue() === "b");
console.log(q.size() === 3);
console.log(q.dequeue() === "c");
console.log(q.dequeue() === "d");
console.log(q.dequeue() === "e");
console.log(q.isEmpty() === true);
console.log(q.size() === 0);
