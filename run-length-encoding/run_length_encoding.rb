# Run Length Compression Module
module RunLengthEncoding
  def self.encode(string)
    encoded_string = ''
    count = 0
    string.chars.each_index do |idx|
      count += 1
      next if string[idx + 1] == string[idx]
      encoded_string << if count > 1
                          count.to_s + string[idx]
                        else
                          string[idx]
                        end
      count = 0
    end
    encoded_string
  end

  def self.decode(string)
    decoded_string = ''
    until string.empty?
      string.chars.each_index do |index|
        num = string[index..index + 1].to_i
        if string[index] =~ /\d/ && string[index + 1] =~ /\d/
          decoded_string << string[index + 2] * num
          string.slice!(index..index + 2)
        elsif string[index].to_i != 0
          decoded_string << string[index + 1] * num
          string.slice!(index..index + 1)
        else
          decoded_string << string[index]
          string.slice!(index)
        end
        break
      end
    end
    decoded_string
  end
end

module BookKeeping
  VERSION = 3
end
