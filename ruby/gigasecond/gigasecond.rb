class Gigasecond
  GIGASECOND = 1_000_000_000
  def self.from(time)
    verify_input(time)
    time + GIGASECOND
  end

  def self.verify_input(time)
    message = 'Please input Time object or moment in seconds'
    unless time.is_a?(Time) || time.is_a?(Integer)
      raise ArgumentError.new, message
    end
  end
end

module BookKeeping
  VERSION = 6
end
