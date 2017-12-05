class Game
  def initialize
    @scores = []
    @spare_indexes = []
    @strike_indexes = []
    @points = 0
  end

  def roll(pins)
    @scores << pins
  end

  def score
    if @scores.size % 2 == 0
      @points += @scores.sum
    else
      temp = @scores.dup
      temp.pop
      @points += temp.sum
    end
    find_spares
    find_strikes
    @points
  end

  private

  def find_strikes
    @scores.each_index.each_slice(2) do |i|
      next unless i[0] && i[1]
      next unless i[0] || i[1] == 0
      if @scores[i[0]] == 10 || @scores[i[1]] == 10
        @strike_indexes << [i[1], (i[1] + 1)]
      end
    end
    add_strikes
  end

  def add_strikes
    @strike_indexes.each do |idx|
      @points += (@scores[idx[0]] + @scores[idx[1]])
    end
  end

  def find_spares
    @scores.each_index.each_slice(2) do |i|
      next unless i[0] && i[1]
      next unless i[0] && i[1] > 0
      if @scores[i[0]] + @scores[i[1]] == 10
        @spare_indexes << i[1] + 1
      end
    end
    add_spares
  end

  def add_spares
    @spare_indexes.each do |idx|
      @points += @scores[idx]
    end
  end

end
