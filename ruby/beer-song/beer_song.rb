class BeerSong
  def verse(high, low = 'a')
    low = high unless low != 'a'
    song = ''
    high.downto(low) do |bottle|
      if bottle > 2
        song << <<~TEXT
          #{bottle} bottles of beer on the wall, #{bottle} bottles of beer.
          Take one down and pass it around, #{bottle - 1} bottles of beer on the wall.
          TEXT
      elsif bottle == 2
        song << <<~TEXT
          2 bottles of beer on the wall, 2 bottles of beer.
          Take one down and pass it around, 1 bottle of beer on the wall.
          TEXT
      elsif bottle == 1
        song << <<~TEXT
          1 bottle of beer on the wall, 1 bottle of beer.
          Take it down and pass it around, no more bottles of beer on the wall.
          TEXT
      else
        song << <<~TEXT
          No more bottles of beer on the wall, no more bottles of beer.
          Go to the store and buy some more, 99 bottles of beer on the wall.
          TEXT
      end
      song << "\n" unless bottle == low && low != 'a'
    end
    song
  end

  def verses(high, low)
    verse(high, low)
  end
end

module BookKeeping
  VERSION = 3
end