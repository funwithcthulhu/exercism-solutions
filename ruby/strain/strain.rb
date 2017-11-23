# Re-implementing #select and #reject
class Array
  def keep
    return to_enum(__method__) { size } unless block_given?
    new_array = []
      self.size.times do |x|
        new_array << self[x] if yield self[x]
      end
    new_array
  end

  def discard
    return to_enum(__method__) { size } unless block_given?
    new_array = []
      self.size.times do |x|
        new_array << self[x] unless yield self[x]
      end
    new_array
  end
end
