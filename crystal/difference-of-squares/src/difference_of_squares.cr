# Please implement your solution to difference-of-squares in this file
class Squares
  def self.square_of_sum(number : Int)
    (1..number).sum**2
  end

  def self.sum_of_squares(number : Int)
    (number * (number + 1) * ((2 * number) + 1)) / 6
  end

  def self.difference_of_squares(number : Int)
    square_of_sum(number) - sum_of_squares(number)
  end
end
