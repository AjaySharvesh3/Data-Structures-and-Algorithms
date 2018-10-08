export class MyQueue<T> {
  items: T[] = [];
  maxSize: number;
  constructor(maxSize = 100) {
    this.maxSize = maxSize;
  }

  enqueue(item: T) {
    if (this.isFull()) {
      throw new Error(
        `Queue is full, it can only accepts ${this.maxSize} items`
      );
    } else {
      this.items = [...this.items, item];
    }
  }

  dequeue(): T | undefined {
    if (this.isEmpty()) {
      return undefined;
    }
    const item = this.items.shift();
    return item;
  }

  isFull(): boolean {
    return this.items.length === this.maxSize;
  }

  isEmpty(): boolean {
    return this.items.length === 0;
  }

  peek(): T | undefined {
    if (this.isEmpty()) {
      return undefined;
    }
    return this.items[0];
  }

  size(): number {
    return this.items.length;
  }
}
