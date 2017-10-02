class Gigasecond
  GIGASECOND = 1_000_000_000

  def self.from(year, month = 1, day = 1, hour = 1, minute = 0, second = 0)
    moment = check_object(year)
    moment ||= Time.new(year, month, day, hour, minute, second)
    moment + GIGASECOND
  end

  def self.check_object(year)
    year.is_a?(Time) ? year : nil
  end
  
  private_class_method :check_object
end

module BookKeeping
  VERSION = 6
end
