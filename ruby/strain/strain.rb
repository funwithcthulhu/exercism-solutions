# Re-implementing #select and #reject
class Array
  def keep
    return to_enum(__method__) { size } unless block_given?
    [].tap do |new_array|
      each do |x|
        new_array << x if yield x
      end
    end
  end

  def discard
    return to_enum(__method__) { size } unless block_given?
    [].tap do |new_array|
      each do |x|
        new_array << x unless yield x
      end
    end
  end
end
