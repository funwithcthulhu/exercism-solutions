# classic wheat and chessboard problem
module Grains
  def self.square(location)
    raise ArgumentError unless location.between?(1, 64)
    wheat = 1
    (location - 1).times do
      wheat *= 2
    end
    wheat
  end

  def self.total
    total = 0
    wheat = 1
    64.times do
      total += wheat
      wheat *= 2
    end
    total
  end
end

module BookKeeping
  VERSION = 1
end
