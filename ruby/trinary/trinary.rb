# class to convert a string input in trinary to base 10
class Trinary
  def initialize(string)
    @trinary = string
  end

  def to_decimal
    return 0 if @trinary =~ /[^012]/
    @trinary.reverse.chars.each_with_index.map do |val, idx|
      val.to_i * 3**idx
    end.inject(:+)
  end
end

module BookKeeping
  VERSION = 1
end
