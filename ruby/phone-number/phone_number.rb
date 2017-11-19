# Module to clean user-entered phone numbers for SMS messaging
module PhoneNumber
  def self.clean(unclean_number)
    clean = unclean_number.gsub(/[^\d]/, '')
    clean.size == 11 && clean[0] == '1' && clean[0] = ''
    return nil unless (clean[0] =~ /[2-9]/) && (clean[3] =~ /[2-9]/)
    clean.size == 10 ? clean : nil
  end
end

module BookKeeping
  VERSION = 2
end
