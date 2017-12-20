(function() {
  var Bob;

  Bob = class Bob {
    hey(phrase) {
      if (!phrase.match(/[a-z]/) && phrase.match(/[A-Z]/)) {
        return 'Whoa, chill out!';
      } else if (phrase.trim() === "") {
        return 'Fine. Be that way!';
      } else if (phrase.trim().endsWith('?')) {
        return 'Sure.';
      } else {
        return 'Whatever.';
      }
    }

  };

  module.exports = Bob;

}).call(this);
