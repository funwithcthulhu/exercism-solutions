class Bob
  hey: (phrase) ->
    if !phrase.match(/[a-z]/) && phrase.match(/[A-Z]/)
      'Whoa, chill out!'
    else if phrase.trim() == ""
      'Fine. Be that way!'
    else if phrase.trim().endsWith('?')
      'Sure.'
    else
      'Whatever.'


module.exports = Bob