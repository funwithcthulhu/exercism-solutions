class LinkedList {
  
}

class Node {
  constructor(item, prev, next) {
    this.item = item;
    this.prev = prev || item;
    this.next = next || item;
  }
}


module.exports = LinkedList;