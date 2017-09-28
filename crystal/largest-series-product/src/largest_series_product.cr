# Please implement your solution to largest-series-product in this file
class Series
  @num_arr : Array(Int64)
  getter :num_arr

  def initialize(string : String)
    @num_arr = string.chars.map(&.to_i64)
  end

  def valid_input?(number)
    raise ArgumentError.new unless @num_arr.size >= number
    raise ArgumentError.new unless number > 0
  end

  def largest_product(series)
    return 1 if series.zero?
    valid_input?(series)
    @num_arr.each_cons(series).map(&.product).max
  end
end
