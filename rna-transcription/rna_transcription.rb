class Complement
  def self.of_dna(dna_strand)
    switch = true
    rna_strand = dna_strand.split('').map do |nucleotide|
      if nucleotide == 'G'
        'C'
      elsif nucleotide == 'C'
        'G'
      elsif nucleotide == 'A'
        'U'
      elsif nucleotide == 'T'
        'A'
      else
        switch = false
      end
    end
    switch ? rna_strand.join('') : ''
  end
end

module BookKeeping
  VERSION = 4
end
