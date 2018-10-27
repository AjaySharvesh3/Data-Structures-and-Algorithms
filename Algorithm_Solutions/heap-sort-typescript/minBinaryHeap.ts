export class MinBinaryHeap<T> {
  private heap: T[] = [];

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
    if (
      leftChild < this.heapSize() &&
      this.heap[leftChild] < this.heap[smallest]
    ) {
      smallest = leftChild;
    }

    if (
      rightChild < this.heapSize() &&
      this.heap[rightChild] < this.heap[smallest]
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
    if (this.heapSize() > 0) {
      if (typeof lastValue !== "undefined") {
        this.heap[0] = lastValue;
        this.minHeapify(0);
      }
    }
    return value;
  }

  // set node index to newValue
  decreaseKey(index: number, newValue: T) {
    if (newValue >= this.heap[index]) {
      return;
    }
    this.heap[index] = newValue;
    let par = this.parent(index);
    while (index != 0 && this.heap[par] > this.heap[index]) {
      this.swap(index, par);
      index = this.parent(index);
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

  // delete node index
  delete(index: number) {
    const size = this.heapSize();
    if (index >= this.heapSize()) {
      console.log(`${index} is larger or equal to heap size: ${size}`);
      return;
    }
    if (index === size - 1) {
      this.heap.pop();
      return;
    }
    const largest = this.heap.pop();
    this.heap[index] = largest;
    let current = index;
    let parent = this.parent(current);
    if (parent >= 0 && this.heap[parent] > this.heap[current]) {
      while (parent >= 0 && this.heap[parent] > this.heap[index]) {
        this.swap(index, parent);
        current = index;
        parent = this.parent(current);
      }
    } else {
      // bubble down
      let left = this.left(current);
      let right = this.right(current);
      let twoChildren = left < this.heapSize() && right < this.heapSize();
      let oneChild = left < this.heapSize();
      while (oneChild) {
        if (
          twoChildren &&
          this.heap[current] < this.heap[left] &&
          this.heap[current] < this.heap[right]
        ) {
          return;
        } else if (oneChild && this.heap[current] < this.heap[left]) {
          return;
        } else {
          if (twoChildren) {
            if (this.heap[left] < this.heap[right]) {
              this.swap(current, left);
              current = left;
            } else {
              this.swap(current, right);
              current = right;
            }
          } else if (oneChild) {
            if (this.heap[left] < this.heap[current]) {
              this.swap(current, left);
              current = left;
            }
          }
        }

        left = this.left(current);
        right = this.right(current);
        twoChildren = left < this.heapSize() && right < this.heapSize();
        oneChild = left < this.heapSize();
      }
    }
  }

  toString() {
    return JSON.stringify(this.heap);
  }
}
