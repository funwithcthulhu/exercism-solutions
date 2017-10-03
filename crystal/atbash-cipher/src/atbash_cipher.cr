# Please implement your solution to atbash-cipher in this file
module Atbash
  ATBASH   = "zyxwvutsrqponmlkjihgfedcba"
  ALPHABET = "abcdefghijklmnopqrstuvwxyz"

  def self.encode(string)
    prestr = string.downcase.tr(ALPHABET, ATBASH).delete(" ").gsub(/[.,]/, "")
    if prestr.size > 5
      i = 5
      while i < prestr.size
        prestr = prestr.insert(i, " ")
        i += 6
      end
    end
    prestr
  end
end
