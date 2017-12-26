let SECONDS = 31557600;
let MERCURY = 0.2408467;
let VENUS = 0.61519726;
let MARS = 1.8808158;
let JUPITER = 11.862615;
let SATURN = 29.447498;
let URANUS = 84.016846;
let NEPTUNE = 164.79132;


let SpaceAge = function(seconds) {
  this.seconds = seconds;
  this.age = this.seconds / SECONDS;
}

SpaceAge.prototype.onEarth = function() {
  return Number((this.age).toFixed(2));
}
SpaceAge.prototype.onMercury = function() {
  return Number((this.age / MERCURY).toFixed(2));
}
SpaceAge.prototype.onVenus = function() {
  return Number((this.age / VENUS).toFixed(2));
}
SpaceAge.prototype.onMars = function() {
  return Number((this.age / MARS).toFixed(2));
}
SpaceAge.prototype.onJupiter = function() {
  return Number((this.age / JUPITER).toFixed(2));
}
SpaceAge.prototype.onSaturn = function() {
  return Number((this.age / SATURN).toFixed(2));
}
SpaceAge.prototype.onUranus = function() {
  return Number((this.age / URANUS).toFixed(2));
}
SpaceAge.prototype.onNeptune = function() {
  return Number((this.age / NEPTUNE).toFixed(2));
}

module.exports = SpaceAge;