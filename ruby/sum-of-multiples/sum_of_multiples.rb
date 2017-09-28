# Determines sum of multiples for limit
class SumOfMultiples
  def initialize(*multiples)
    @multiples = *multiples
  end

  def divisible?(value)
    @multiples.any? { |multiple| (value % multiple).zero? }
  end

  def to(limit)
    return 0 if @multiples.empty?
    (0...limit).select { |n| divisible?(n) }.reduce(:+)
  end
end

module BookKeeping
  VERSION = 1
end
