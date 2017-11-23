# Transforms scrabble scoring data
module ETL
  def self.transform(old_data)
    old_data.flat_map do |value, letters|
      letters.map(&:downcase).product([value])
    end.to_h
  end
end

module BookKeeping
  VERSION = 1
end


