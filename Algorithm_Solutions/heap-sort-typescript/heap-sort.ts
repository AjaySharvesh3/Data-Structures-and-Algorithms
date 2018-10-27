import { MinBinaryHeap } from "./minBinaryHeap";

declare var process: {
  argv: string[];
};

const heapSort = (...args) => {
  if (args.length <= 0) {
    return [];
  }
  const tree = new MinBinaryHeap<number>();
  args.map((n: number) => tree.insert(n));
  const sorted = [];
  while (tree.getMin() !== null) {
    sorted.push(tree.extractMin());
  }
  return sorted;
};

const inputs = process.argv.slice(2).map((s: string) => Number(s));
console.log("inputs", inputs);
console.log("sorted", heapSort(...inputs));

// Tests
console.log("Additional test cases");
console.log(heapSort());
console.log(heapSort(1));
console.log(heapSort(1, 3, 5));
console.log(heapSort(5, 3, 1));
console.log(heapSort(5, -3, 5, -2, 4));
