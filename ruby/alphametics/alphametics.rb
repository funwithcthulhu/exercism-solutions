module BookKeeping
  VERSION = 4
end

class String
  def numeric?
    Float(self) != nil rescue false
  end
end

# takes 240s total for all tests
module Alphametics
  def self.solve(input_string)
    @key = {}
    @equation = input_string
    self.find_uniq_letters
    self.find_possible_keys
    self.test_combinations
    @key
  end

  def self.find_uniq_letters
    @letters = @equation.gsub(/[^A-Z]/, '').chars.uniq.sort.join
  end

  def self.find_possible_keys
    size = @letters.size
    @poss = (0..9).to_a.permutation(size).to_a.map { |ar| ar.join('') }
  end

  def self.test_combinations
    @eq = ''
    i = 0
    until i >= @poss.size || eval(@eq)
      @eq = @equation.tr(@letters, @poss[i])
      @eq = '1 != 1' if self.detect_leading_zero(@eq)
      self.assemble_key(@letters, @poss[i]) if eval(@eq)
      i += 1
    end
  end

  def self.detect_leading_zero(a)
    a.split(/\s+/).select { |a| a.numeric? }.each do |i|
      return true if i.size > 1 && i.chars.first == '0'
    end
    false
  end

  def self.assemble_key(letters, poss)
    letters.size.times do |i|
      @key[letters[i]] = poss[i].to_i
    end
  end
end