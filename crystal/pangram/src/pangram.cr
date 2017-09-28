# Please implement your solution to pangram in this file
class Pangram
  def self.pangram?(string : String)
    library = ("a".."z").to_a
    library.reject! { |c| string.downcase.includes?(c) }
    library.empty?
  end
end
