# lackadaisical bob
class Bob
  def self.hey(remark)
    if remark.match(/\p{Lower}/).nil? && remark.match(/[a-zA-Z]/)
      'Whoa, chill out!'
    elsif remark.strip.empty?
      'Fine. Be that way!'
    elsif remark.strip.split('').last.=~(/\?/)
      'Sure.'
    else
      'Whatever.'
    end
  end
end

module BookKeeping
  VERSION = 1
end
