class Hamming
  def self.compute(strand1, strand2)
    unless strand1.length == strand2.length
      raise LengthError,
      "Strands must be same length: #{strand1.length}, #{strand2.length}"
    end
    strand1.chars.zip(strand2.chars).count { |n1, n2| n1 != n2 }
  end
end

class LengthError < ArgumentError; end

module BookKeeping
  VERSION = 3
end
