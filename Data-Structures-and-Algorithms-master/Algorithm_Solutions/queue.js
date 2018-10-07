// remember:
// In a queue, the first item in,
// is the first item out (FIFO)!

let data = [];

const queue = function(data) {
  return {
    add: function(v) {
      data.push(v);
      return data;
    },
    remove: function() {
      data.shift();
      return data;
    }
  }
}

data = queue(data).add('item1');
data = queue(data).add('item2');
data = queue(data).add('item3');
data = queue(data).remove();
