# Finds prime factors of a natural number
module PrimeFactors
  def self.for(number)
    @number = number
    @factors = []
    @divisor = number
    find_factors
  end

  def self.find_factors
    until @divisor == 1
      (2..@number).each do |x|
        next unless (@divisor % x).zero?
        @factors << x
        @divisor /= x
        break
      end
    end
    @factors
  end
end
