# translates a strand of dna into it's complement rna
class Complement
  def self.of_dna(dna_strand)
    rna_strand = dna_strand.split('').map do |nucleotide|
      case nucleotide
      when 'G' then 'C'
      when 'C' then 'G'
      when 'A' then 'U'
      when 'T' then 'A'
      else return ''
      end
    end
    rna_strand.join('')
  end
end

module BookKeeping
  VERSION = 4
end
