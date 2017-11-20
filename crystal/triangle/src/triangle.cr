# Please implement your solution to triangle in this file

class Triangle
  def initialize(array : Array(Int32))
    @sides = array
  end

  def equilateral?
    return false unless valid_check
    @sides.all? { |x| x == @sides[0] }
  end

  def isosceles?
    return false unless valid_check
    @sides.uniq.size <= 2
  end

  def scalene?
    return false unless valid_check
    @sides.uniq.size == 3
  end

  private def valid_check
    return false unless @sides.all? { |x| x > 0 }
    return false unless @sides[0..1].sum > @sides[2]
    return false unless @sides[1..2].sum > @sides[0]
    return false unless @sides[0] + @sides[2] > @sides[1]
    true
  end
end
