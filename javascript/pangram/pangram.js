module.exports = class Pangram {
  constructor(input) {
    this.input = input;
  }

  isPangram() {
    let library = "abcdefghijklmnopqrstuvwxyz";
    for (let i = 0; i < library.length; i++) {
      if (!this.input.toLowerCase().includes(library.charAt(i))) {
        return false;
      }
    }
    return true;
  }
}