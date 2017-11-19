# Outputs all contiguous substrings of input
class Series
  def initialize(input)
    @input = input
  end

  def slices(slice)
    raise ArgumentError unless slice <= @input.size
    @input.chars.each_cons(slice).map(&:join)
  end
end
