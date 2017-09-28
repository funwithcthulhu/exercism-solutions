class Pangram
  def self.pangram?(string)
    library = ('a'..'z').to_a
    library.delete_if { |letter| string.downcase.include? letter }
    library.empty? ? false : true
  end
end

module BookKeeping
  VERSION = 4
end
