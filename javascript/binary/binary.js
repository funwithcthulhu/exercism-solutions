let Binary = function(binary) {
  if (binary.match(/[^01]/)) {
    this.binary = '0';
  } else {
    this.binary = binary;
  }
}

Binary.prototype.toDecimal = function() {
  let array = this.binary.split('').reverse();
  let decimal = array.map((el, i) => {
    return (parseInt(el) * Math.pow(2, i));
  });
  return decimal.reduce((acc, el) => acc + el);
}

module.exports = Binary;