var DnaTranscriber = function() {
}

DnaTranscriber.prototype.toRna = function(dna) {
  if (dna.match(/[^ACTG]/)) {
    throw Error("Invalid input");
  }
  let rna = dna.replace(/G/g, 'D')
               .replace(/C/g, 'G')
               .replace(/D/g, 'C')
               .replace(/A/g, 'U')
               .replace(/T/g, 'A')
  return rna;
}

module.exports = DnaTranscriber;