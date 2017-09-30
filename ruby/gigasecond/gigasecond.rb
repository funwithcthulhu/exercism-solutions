# Returns a moment 1 gigasecond from input
class Gigasecond
  GIGASECOND = 1_000_000_000
  def self.from(time)
    verify_input(time)
    time + GIGASECOND
  end

  private

  def self.verify_input(time)
    msg = 'Please input Time object or moment in seconds'
    raise ArgumentError.new, msg unless time.is_a?(Time) || time.is_a?(Integer)
  end
end

module BookKeeping
  VERSION = 6
end
