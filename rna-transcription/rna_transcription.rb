# Translates DNA strand into complementary RNA strand
class Complement
  def self.of_dna(dna_strand)
    return '' unless dna_strand.gsub(/[GCAT]/, '').empty?
    dna_strand.gsub(/[GCAT]/, DICT)
  end

  DICT =
    {
      'G' => 'C',
      'C' => 'G',
      'A' => 'U',
      'T' => 'A'
    }.freeze
end

module BookKeeping
  VERSION = 4
end
