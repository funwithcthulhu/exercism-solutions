# Transforms scrabble scoring data
module ETL
  def self.transform(old_data)
    {}.tap do |new_data|
      old_data.each_pair do |score, letters|
        letters.each do |letter|
          new_data[letter.downcase] = score
        end
      end
    end
  end
end

module BookKeeping
  VERSION = 1
end
