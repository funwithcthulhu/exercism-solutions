module BookKeeping
  VERSION = 2
end

class Clock
  attr_accessor :mins
  MINS_IN_DAY = 1440

  def initialize(hour, minute)
    @hour = hour
    @minute = minute
    find_mins
  end

  def self.at(hour, minute)
    Clock.new(hour, minute)
  end

  def +(other)
    @minute += other
    find_mins
    self
  end

  def ==(other)
    to_s == other.to_s
  end

  def find_mins
    @mins = (60 * @hour + @minute) % MINS_IN_DAY
  end

  def to_s
    format('%02d:%02d', @mins / 60, @mins % 60)
  end
end
