# class for creating a school roster
class School
  def initialize
    @db = Hash.new { |hash, key| hash[key] = [] }
  end

  def students(grade)
    @db[grade].sort
  end

  def add(student, grade)
    @db[grade] << student
  end

  def students_by_grade
    @db.sort.map do |grade, students|
      { grade: grade, students: students.sort }
    end
  end
end

module BookKeeping
  VERSION = 3
end
