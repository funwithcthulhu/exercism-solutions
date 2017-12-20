module BookKeeping
  VERSION = 1
end

class Crypto
  attr_accessor :ciphertext

  def initialize(plaintext)
    @plaintext = plaintext
    format_text
    find_rows_and_cols
    make_rectangle
    make_ciphertext
  end

  def format_text
    @formatted = @plaintext.downcase.gsub(/[^a-z0-9]/, '')
  end

  def find_rows_and_cols
    @size = @formatted.size
    @cols = Math.sqrt(@size).ceil
  end

  def make_rectangle
    @rectangle = []
    @count = 0
    if @size > 0
      @formatted.chars.each_slice(@cols) do |slice|
        slice << ' ' until slice.size == @cols
        @rectangle << slice && @count += 1
      end
    end
  end

  def make_ciphertext
    @ciphertext = @rectangle.transpose.map { |row| row.join('') }.join('')
    @ciphertext = @ciphertext.gsub(/(.{#{@count}})(?=.)/, '\1 \2')
  end
end
