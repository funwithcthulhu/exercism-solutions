class Integer
  def to_roman
    dictionary = {
      1 => 'I',
      2 => 'II',
      3 => 'III',
      4 => 'IV',
      5 => 'V',
      6 => 'VI',
      7 => 'VII',
      10 => 'X',
      50 => 'L',
      100 => '',
      1000 => 'M'
    }
    case self 
    when 1
      'I'
    when 2
      'II'
    when 3
      'III'
    when 4
      'IV'
    when 5
      'V'
    when 6
      'VI'
    when 7
      'VII'
    when 8
      'VIII'
    when 9
      'IX'
    when 10
      'X'
    end
  end 
end