module BookKeeping
  VERSION = 3
end

class Game
  attr_accessor :fill
  class BowlingError < StandardError; end
  
  def initialize
    @score_card = {}
    @count = 1
  end

  def roll(pins)
    @score_card[@count] ||= Frame.new(@count)
    @score_card[@count].pins << pins
    check_pins(@score_card[@count].pins)
    @count += 1 if @score_card[@count].pins.sum == 10 || 
                   @score_card[@count].pins.size == 2
  end

  def score
    verify_game
    @score_card.values.map.with_index(1) do |frame, idx|
      frame.check
      frame_score(frame, idx)
    end.sum
  end

  def verify_game
    raise BowlingError.new unless @count > 10
    if @score_card[10].pins.first == 10 &&
      !@score_card[11] && @score_card[10].pins.size != 2
      raise BowlingError.new
    end
    if @score_card[10].pins.first == 10 &&
       @score_card[11].pins.first == 10 && 
       !@score_card[12]
      raise BowlingError.new
    end
    if !@score_card[10].strike &&
       !@score_card[11] && @score_card[10].pins.sum == 10
       raise BowlingError.new
    end
  end

  def frame_score(frame, idx)
    return 0 unless idx.between?(0, 10)
    if frame.strike || frame.spare
      score_strike_or_spare(frame, idx)
    else
      frame.pins.sum
    end
  end

  def score_strike_or_spare(frame, idx)
    temp = []
    @score_card.values.each.with_index(1) do |frame, i|
      next unless i.between?(idx, idx + 2)
      temp << frame.pins
    end
    temp.flatten[0..2].sum
  end

  def check_pins(pins)
    @fill = true if @count == 10 && @score_card[10].pins.sum == 10
    raise BowlingError.new unless pins.all? { |x| x.between?(0, 10) }
    raise BowlingError.new unless pins.sum <= 10
    raise BowlingError.new unless @count <= 10 || @fill
  end
end

class Frame
  attr_accessor :pins, :strike, :spare, :number
  def initialize(number)
    @number = number
    @pins = []
  end

  def check
    if @pins.first == 10
      @strike = true
    elsif @pins.sum == 10
      @spare = true
    end
  end
end
