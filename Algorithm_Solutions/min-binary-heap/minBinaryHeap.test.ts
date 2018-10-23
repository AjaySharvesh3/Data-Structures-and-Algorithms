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
