class MinBinaryHeap<T> {
  heap: T[] = [];

  getMin(): T | null {
    if (this.heap.length === 0) {
      return null;
    }
    return this.heap[0];
  }

  extractMin(): T | null {
    return null;
  }

  decreaseKey() {}

  insert(key: T) {}

  delete(key: T) {}
}
