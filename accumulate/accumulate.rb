# Implementation of 'accumulate' map method
class Array
  def accumulate
    return to_enum(__method__, size) unless block_given?
    reduce([]) do |array, val|
      array.push(yield val)
    end
  end
end

module BookKeeping
  VERSION = 1
end
