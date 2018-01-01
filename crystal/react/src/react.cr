# Please implement your solution to react in this file
module React
  class InputCell
    def initialize(data : Int32)
      @data = data
    end

    def value=(data)
      @data = data
    end

    def value
      @data
    end

    def +(other)
      @data += other.value
    end
  end

  class ComputeCell
    def initialize(*cells : InputCell, &block)
      @cell = React::InputCell.new(0)   
      cells.each do |cell|
        @cell.value += cell.value
      end
    end

    def initialize(*cells : ComputeCell, &block)
      @cell = React::InputCell.new(0)   
      cells.each do |cell|
        @cell.value += cell.value
      end
    end

    def value
      return @cell
    end
  end
end
