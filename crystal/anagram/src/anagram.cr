# Please implement your solution to anagram in this file
module Anagram
  def self.find(word : String, list : Array)
    comparator = word.downcase.split(//).sort
    result = [] of String
    list.each do |words|
      temp = words.downcase.split(//).sort
      if temp == comparator && words.downcase != word.downcase
        result.push(words)
      end
    end
    result
  end
end
