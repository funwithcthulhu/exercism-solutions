module BookKeeping
  VERSION = 1
end

class SpaceAge
  SECONDS = 31557600
  MERCURY = 0.2408467
  VENUS = 0.61519726
  MARS = 1.8808158
  JUPITER = 11.862615
  SATURN = 29.447498
  URANUS = 84.016846
  NEPTUNE = 164.79132

  def initialize(seconds)
    @earth_age = seconds.to_f / SECONDS
  end

  def on_earth
    @earth_age
  end

  def on_mercury
    @earth_age / MERCURY
  end

  def on_venus
    @earth_age / VENUS
  end

  def on_mars
    @earth_age / MARS
  end

  def on_jupiter
    @earth_age / JUPITER
  end

  def on_saturn
    @earth_age / SATURN
  end

  def on_uranus
    @earth_age / URANUS
  end

  def on_neptune
    @earth_age / NEPTUNE
  end
end