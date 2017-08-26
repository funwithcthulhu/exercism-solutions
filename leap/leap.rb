# determines if year is a leap year or not
module Year
  def self.leap?(year)
    return false if (year % 100).zero? && !(year % 400).zero?
    return true if (year % 4).zero?
  end
end

module BookKeeping
  VERSION = 3
end
