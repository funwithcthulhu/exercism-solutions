require 'prime'

class Prime
  @prime_array ||= [2, 3]

  def self.nth(input)
    raise ArgumentError unless input >= 1
    succ = @prime_array.last + 2
    while @prime_array.size < input
      @prime_array << succ if succ.prime?
      succ += 2
    end
    @prime_array[input - 1]
  end
end

module BookKeeping
  VERSION = 1
end
