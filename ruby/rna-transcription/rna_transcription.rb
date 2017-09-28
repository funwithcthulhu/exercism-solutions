# Translates DNA strand into complementary RNA strand
class Complement
  def self.of_dna(dna_strand)
    return '' if dna_strand.match?(/[^GCAT]/)
    dna_strand.tr('GCAT', 'CGUA')
  end
end

module BookKeeping
  VERSION = 4
end
