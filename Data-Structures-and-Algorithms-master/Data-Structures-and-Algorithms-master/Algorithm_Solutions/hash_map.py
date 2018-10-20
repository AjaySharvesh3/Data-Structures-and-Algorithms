from collections import namedtuple


HashMapNode = namedtuple('HashMapNode', ['key', 'value'])


class HashMap:
    def __init__(self, bucket_count=16):
        self.size = 0
        self.bucket_count = bucket_count
        self.buckets = [[] for i in range(bucket_count)]

    def put(self, key, value):
        """Insert an item into the HashMap"""
        bucket_index = self._get_bucket_index(key)
        bucket = self.buckets[bucket_index]
        for index, node in enumerate(bucket):
            if node.key == key:
                bucket[index] = HashMapNode(key, value)
                return
        bucket.append(HashMapNode(key, value))
        self.size += 1

    def get(self, key):
        """Retrieve an item from the HashMap"""
        bucket_index = self._get_bucket_index(key)
        bucket = self.buckets[bucket_index]
        for node in bucket:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        """Remove an item from the HashMap"""
        bucket_index = self._get_bucket_index(key)
        bucket = self.buckets[bucket_index]
        for index, node in enumerate(bucket):
            if node.key == key:
                bucket.pop(index)
                self.size -= 1
                return

    def count(self):
        return self.size

    def _get_bucket_index(self, key):
        """Hash a key and limit the resulting value to the number of buckets"""
        return hash(key) % self.bucket_count

    def display(self):
        """Print out the HashMap to view how values are being stored"""
        print('[')
        for bucket in self.buckets:
            nodes = [str(node) for node in bucket]
            print('\t[{}]'.format(', '.join(nodes)))
        print(']')


if __name__ == '__main__':
    hash_map = HashMap()
    print('Putting {hello: world}')
    hash_map.put('hello', 'world')

    print('Putting {foo: bar}')
    hash_map.put('foo', 'bar')

    print('Putting {foo: baz}')
    hash_map.put('foo', 'baz')

    print('Count: {}'.format(hash_map.count()))
    print('Value for "hello": {}'.format(hash_map.get('hello')))
    print('Value for "foo": {}'.format(hash_map.get('foo')))

    print('Removing "hello"')
    hash_map.remove('hello')

    print('Count: {}'.format(hash_map.count()))
    print('Value for "hello": {}'.format(hash_map.get('hello')))
