class School
  def initialize
    @school = {}
    @by_grade = []
  end

  def students(grade)
    @school[grade] ||= []
    @school[grade].sort
  end

  def add(student, grade)
    @school[grade] ||= []
    @school[grade] << student
  end

  def students_by_grade

  end
end
