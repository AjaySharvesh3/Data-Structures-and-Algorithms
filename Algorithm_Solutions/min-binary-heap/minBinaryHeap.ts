export class MinBinaryHeap<T> {
  heap: T[] = [];

  private left(i) {
    return 2 * i + 1;
  }

  private right(i) {
    return 2 * i + 2;
  }

  private parent(i) {
    const idx = i % 2 === 1 ? 1 : 2;
    return (i - idx) / 2;
  }

  private heapSize() {
    return this.heap.length;
  }

  private swap(i: number, j: number) {
    const old = this.heap[i];
    this.heap[i] = this.heap[j];
    this.heap[j] = old;
  }

  // For any node i, its left child is 2i + 1, its right child is 2i + 2
  private minHeapify(i: number) {
    const leftChild = this.left(i);
    const rightChild = this.right(i);

    let smallest = i;
    if (leftChild < this.heapSize() && this.heap[leftChild] < this.heap[i]) {
      smallest = leftChild;
    } else if (
      rightChild < this.heapSize() &&
      this.heap[rightChild] < this.heap[i]
    ) {
      smallest = rightChild;
    }

    if (smallest !== i) {
      this.swap(i, smallest);
      this.minHeapify(smallest);
    }
  }

  getMin(): T | null {
    if (this.heap.length <= 0) {
      return null;
    }
    return this.heap[0];
  }

  extractMin(): T | null {
    if (this.heap.length <= 0) {
      return null;
    }
    const value = this.heap[0];

    // Replace root with last child
    const lastValue = this.heap.pop();
    if (typeof lastValue !== "undefined") {
      this.heap[0] = lastValue;
      this.minHeapify(0);
    }
    return value;
  }

  decreaseKey(i: number, newValue: T) {
    if (newValue >= this.heap[i]) {
      return;
    }
    this.heap[i] = newValue;
    let par = this.parent(i);
    while (i != 0 && this.heap[par] > this.heap[i]) {
      this.swap(i, par);
      i = this.parent(i);
    }
  }

  insert(key: T) {
    this.heap.push(key);
    let i = this.heap.length - 1;
    // Fix the min heap property if it is violated
    let par = this.parent(i);
    while (i != 0 && this.heap[par] > this.heap[i]) {
      this.swap(i, par);
      i = this.parent(i);
    }
  }

  delete(i: number) {
    if (i < this.heapSize()) {
      return;
    }
    const largest = this.heap.pop();
    this.heap[i] = largest;
    this.minHeapify(i);
  }
}
