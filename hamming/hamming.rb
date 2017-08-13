class Hamming
  def self.compute(strand_a, strand_b)
    raise ArgumentError if strand_a.length != strand_b.length
    (0..strand_a.length).count do |index|
      strand_a[index] != strand_b[index]
    end 
  end
end

module BookKeeping
  VERSION = 3
end