class Complement

  def self.of_dna(dna_strand)
    switch = true
    rna_strand = dna_strand.split('').map do |nucleotide|
      case
      when nucleotide == 'G'
        'C'
      when nucleotide == 'C'
        'G'
      when nucleotide == 'A'
        'U'
      when nucleotide == 'T'
        'A'
      when nucleotide != 'G' || 'C' || 'A' || 'T'
        switch = false
      end
    end
    return switch ? rna_strand.join('') : ''
  end
end

module BookKeeping
  VERSION = 4
end