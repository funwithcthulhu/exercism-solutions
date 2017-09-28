# Please implement your solution to rna-transcription in this file
class RnaComplement
  def self.of_dna(nts : String)
    return "" if nts =~ (/[^GCAT]/)
    nts.gsub(/[GCAT]/, DICT)
  end

  DICT =
    {
      "G" => "C",
      "C" => "G",
      "A" => "U",
      "T" => "A",
    }
end
