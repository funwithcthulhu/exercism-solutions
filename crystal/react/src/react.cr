# Please implement your solution to react in this file
module React
  class InputCell

    def initialize(value : Int32)
      @value = value
    end

    def value
      @value
    end

    def value=(value)
      @value = value
    end
  end

  class ComputeCell
    def initialize(*args)
      @value = 0
      args.each do |input|
        @value += yield input.value
      end
    end

    def value
      @value
    end
  end
end
