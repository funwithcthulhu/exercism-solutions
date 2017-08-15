class Raindrops
  def self.convert(number)
    answer = []
    answer << 'Pling' if (number % 3).zero?
    answer << 'Plang' if (number % 5).zero?
    answer << 'Plong' if (number % 7).zero?
    answer.empty? ? number.to_s : answer.join
  end
end

module BookKeeping
  VERSION = 3
end
