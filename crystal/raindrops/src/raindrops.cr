# Please implement your solution to raindrops in this file
class Raindrops
  def self.drops(drop : Int32)
    sound = String.build do |sound|
      sound << "Pling" if mult_of_3(drop)
      sound << "Plang" if mult_of_5(drop)
      sound << "Plong" if mult_of_7(drop)
    end
    sound.blank? ? drop.to_s : sound
  end

  def self.mult_of_3(drop)
    (drop % 3).zero?
  end

  def self.mult_of_5(drop)
    (drop % 5).zero?
  end

  def self.mult_of_7(drop)
    (drop % 7).zero?
  end
end
