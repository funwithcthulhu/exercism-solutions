# word count object
class Phrase
  def initialize(phrase)
    @phrase = phrase
    @dict = Hash.new(0)
  end

  def word_count
    @phrase.split(/[^[[:word:]]']+/).each do |word|
      word.delete!("''") if word.count("''") > 1
      @dict[word.downcase] += 1
    end
    @dict
  end
end

module BookKeeping
  VERSION = 1
end
