# Transforms scrabble scoring data
module ETL
  def self.transform(old_data)
    old_data.each_with_object({}) do |(score, letters), new_data|
      letters.size.times { |i| new_data[letters[i].downcase] = score }
    end
  end
end

module BookKeeping
  VERSION = 1
end
