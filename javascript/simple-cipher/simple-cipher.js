const mod = (x, n) => (x % n + n) % n

var Cipher = function(key) {
  if (key) {
    if (key.match(/[^a-z]/)) {
      throw Error("Bad key");
    } 
    this.key = key;
  } else if (key == "") {
    throw Error("Bad key");
  } else {
    this.key = makeKey();
  };

  function makeKey() {
    let key = '';
    let library = "abcdefghijklmnopqrstuvwxyz";
    for (let i = 0; i < 101; i++) {
      key += library.charAt(Math.floor(Math.random() * library.length));
    }
    return key;
  }
};


Cipher.prototype.encode = function(plaintext) {
  let size = plaintext.length;
  let encoded = '';
  for (let i = 0; i < size; i++) {
    let c = plaintext.charCodeAt(i) % 97;
    let k = this.key.charCodeAt(i % this.key.length) % 97;
    let n = String.fromCharCode(((c + k) % 26) + 97);
    encoded += n;
  }
  return encoded;
}

Cipher.prototype.decode = function(encoded) {
  let size = encoded.length;
  let decoded = [];
  for (let i = 0; i < size; i++) {
    let c = encoded.charCodeAt(i) % 97;
    let k = this.key.charCodeAt(i % this.key.length) % 97;
    let n = String.fromCharCode((mod((c - k), 26)) + 97);
    decoded.push(n);
  }
  return decoded.join('');
}

module.exports = Cipher;