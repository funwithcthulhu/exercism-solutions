class Matrix {
  constructor(input) {
    this.rows = Matrix.format(input);
    this.columns = Matrix.transpose(this.rows);
  }

  static format(input) {
    let matrix = input.split("\n")
                      .map(item => item
                      .split(' ')
                      .map( i => parseInt(i)));
    return matrix;
  }

  static transpose(matrix) {
    return matrix.map((col, i) => matrix.map(row => row[i]));
  }
}

module.exports = Matrix;