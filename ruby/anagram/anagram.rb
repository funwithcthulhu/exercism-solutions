module BookKeeping
  VERSION = 2
end

class Anagram
  def initialize(word)
    @comparator = word
  end

  def match(list)
    list.select do |word|
      word_arr = word.downcase.chars.sort
      key = @comparator.downcase.chars.sort
      word_arr == key && word.downcase != @comparator.downcase
    end
  end
end
