# Module for conversion between decimal and binary numbers
module Binary
  def self.to_decimal(binary)
    raise ArgumentError, 'Invalid input' if binary.to_s =~ /[^01]/
    binary.to_s.reverse.chars.each_with_index.map do |val, idx|
      val.to_i * 2**idx
    end.inject(:+)
  end

  def self.to_binary(decimal)
    raise ArgumentError, 'Invalid input' if decimal.to_s =~ /[^0-9]/
    decimal = decimal.to_i
    binary_n = []
    until decimal < 1
      binary_n.unshift(decimal % 2)
      decimal /= 2
    end
    binary_n.join.to_i
  end
end

module BookKeeping
  VERSION = 3
end
