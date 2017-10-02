# Please implement your solution to bracket-push in this file
module Brackets
  BRACKETS = {"[" => "]", "{" => "}", "(" => ")"}

  def self.are_valid?(a_string : String)
    stack = [] of String
    a_string.split(//).each do |b|
      if BRACKETS.has_key?(b)
        stack.push(b)
      elsif BRACKETS.has_value?(b)
        return false if stack.empty?
        return false unless BRACKETS[stack.pop] == b
      end
    end
    stack.empty?
  end
end
