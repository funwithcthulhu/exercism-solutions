# Please implement your solution to hamming in this file
class Hamming
  def self.compute(strand1 : String, strand2 : String)
    unless strand1.size == strand2.size
      raise LengthError.new("Strands must be same length")
    end
    strand1.chars.zip(strand2.chars).count { |n1, n2| n1 != n2 }
  end
end

class LengthError < ArgumentError; end
