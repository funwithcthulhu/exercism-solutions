# Please implement your solution to leap in this file
class Year
  def self.leap?(year : Int): Bool
    century?(year) ? (year % 400).zero? : div_by_4?(year)
  end

  def self.div_by_4?(year : Int): Bool
    (year % 4).zero?
  end

  def self.century?(year : Int): Bool
    (year % 100).zero?
  end
end
