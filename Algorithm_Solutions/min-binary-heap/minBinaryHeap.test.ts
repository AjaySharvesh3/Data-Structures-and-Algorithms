import { MinBinaryHeap } from "./minBinaryHeap";

const h = new MinBinaryHeap<number>();

h.insert(3);
h.insert(2);
h.delete(1);
h.insert(15);
h.insert(5);
h.insert(4);
h.insert(45);
// 2 4 5 15 45
console.log(h.extractMin() === 2);
// 4 15 5 45
console.log(h.getMin() === 4);
h.decreaseKey(2, 1);
// 4 15 1 45 -> 1 15 4 45
console.log(h.getMin() === 1);

const h2 = new MinBinaryHeap<number>();
h2.insert(1);
h2.insert(9);
h2.insert(22);
h2.insert(17);
h2.insert(11);
h2.insert(33);
h2.insert(27);
h2.insert(21);
h2.insert(19);
console.log(h2.toString() === "[1,9,22,17,11,33,27,21,19]");
h2.delete(5);
console.log(h2.toString() === "[1,9,19,17,11,22,27,21]");
console.log(h2.extractMin() === 1);
console.log(h2.toString() === "[9,11,19,17,21,22,27]");
console.log(h2.getMin() === 9);
console.log(h2.extractMin() === 9);
console.log(h2.toString() === "[11,17,19,27,21,22]");
console.log(h2.getMin() === 11);
h2.insert(15);
console.log(h2.toString() === "[11,17,15,27,21,22,19]");

const h3 = new MinBinaryHeap<number>();
h3.insert(1);
h3.insert(5);
h3.insert(6);
h3.insert(9);
h3.insert(11);
h3.insert(8);
h3.insert(15);
h3.insert(17);
h3.insert(21);
h3.delete(1);
console.log(h3.toString() === "[1,9,6,17,11,8,15,21]");
h3.delete(2);
console.log(h3.toString() === "[1,9,8,17,11,21,15]");
console.log(h3.getMin() === 1);
console.log(h3.extractMin() === 1);

const h4 = new MinBinaryHeap<number>();
h4.insert(9);
console.log(h4.extractMin() === 9);
console.log(h4.extractMin() == null);
