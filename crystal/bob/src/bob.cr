# Please implement your solution to bob in this file
class Bob
  def self.hey(phrase)
    response Phrase.new(phrase)
  end

  def self.response(phrase)
    if phrase.silent?
      "Fine. Be that way!"
    elsif phrase.yell?
      "Whoa, chill out!"
    elsif phrase.question?
      "Sure."
    else
      "Whatever."
    end
  end
end

class Phrase
  def initialize(phrase : String)
    @phrase = phrase
  end

  def yell?
    @phrase == @phrase.upcase && @phrase =~ /[A-Z]/
  end

  def question?
    @phrase.ends_with?("?")
  end

  def silent?
    @phrase.blank?
  end
end
