'use strict'

const primeFactors =  {
  for: function(input) {
    let factors = [];
    let largest_factor = input;
    let candidate = 2;
    while (largest_factor > 1) {
      while (largest_factor % candidate == 0) {
        factors.push(candidate);
        largest_factor /= candidate;
      }
      candidate += 1;
    }
    return factors
  }
}



module.exports = primeFactors;