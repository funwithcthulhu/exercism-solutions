class Sieve
  def initialize(num)
    @num = num
  end

  def primes
    @primes = (0..@num).to_a
    @primes[0] = @primes[1] = nil
    @primes.each do |number|
      next unless number
      break if number * number > @num 
      (number*number).step(@num, number) { |val| @primes[val] = nil }
    end 
    @primes.compact 
  end
end

module BookKeeping
  VERSION = 1
end