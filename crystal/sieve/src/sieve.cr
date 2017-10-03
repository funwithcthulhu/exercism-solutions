# Please implement your solution to sieve in this file
class Primes
  def self.sieve(n)
    sieve = [] of Int32
    return sieve if n < 2
    (2..n).each { |n| sieve.push(n) }
    ind = 0
    until sieve[ind] == sieve.last
      val = sieve[ind]
      sieve.each_index do |i|
        sieve[i] = 0 if (sieve[i] % val).zero? && sieve[i] > val
      end
      ind += 1
      sieve.delete(0)
    end
    sieve
  end
end
