module BookKeeping
  VERSION = 1
end

class Bst
  attr_accessor :data, :left, :right, :size
  def initialize(data)
    @data = data
    @size = 1
  end

  def insert(data)
    data <= @data ? insert_left(data) : insert_right(data)
    @size += 1
  end

  def insert_left(data)
    @left ? left.insert(data) : @left = Bst.new(data)
  end

  def insert_right(data)
    @right ? right.insert(data) : @right = Bst.new(data)
  end

  def each(&block)
    return to_enum(__method__) { size } unless block_given?
    left.each(&block) if left
    yield data
    right.each(&block) if right
  end
end
