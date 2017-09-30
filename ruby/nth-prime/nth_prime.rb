# Finds the nth prime
class Prime
  def self.nth(limit)
    raise ArgumentError, 'No zeroth prime' unless limit >= 1
    return 2 if limit == 1
    count = 1
    candidate = 1
    while count < limit
      candidate += 2
      isPrime(candidate) && count += 1
    end
    candidate
  end

  def self.isPrime(n)
    if n == 1
      false
    elsif n < 4
      true
    elsif (n % 2).zero?
      false
    elsif n < 9
      true
    elsif (n % 3).zero?
      false
    else
      r = Math.sqrt(n).floor
      f = 5
      while f <= r
        return false if (n % f).zero?
        return false if (n % (f + 2)).zero?
        f += 6
      end
      true
    end
  end

  private_class_method :isPrime
end

module BookKeeping
  VERSION = 1
end
