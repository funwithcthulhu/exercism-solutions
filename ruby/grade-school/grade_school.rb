# class for creating a school roster
class School
  def initialize
    @db = Hash.new([])
  end

  def students(grade)
    @db[grade].sort
  end

  def add(student, grade)
    @db[grade] = [] unless @db.key?(grade)
    @db[grade] << student
  end

  def students_by_grade
    @db.keys.sort.map do |grade|
      { grade: grade, students: students(grade) }
    end
  end
end

module BookKeeping
  VERSION = 3
end
