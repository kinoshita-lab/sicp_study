class ConsCell
    attr_accessor :car, :cdr
    def initialize car=nil, cdr=nil
      @car = car
      @cdr = cdr
    end
  
    def push cell
      if @car == nil
        @car = cell
        return self
      end
  
      if @cdr == nil
        @cdr = ConsCell.new
        @cdr.car = cell
        return self
      end
      
      return @cdr.push(cell)    
    end
  
    def nil?
      return @car == nil && @cdr == nil
    end

    def to_s
        if nil?
            "nil"
        end
    end
end


def car cell
    cell.car
end

def cdr cell
    cell.cdr
end

def cadr cell
    car(cdr(cell))
end

def cddr cell
    cdr(cdr(cell))
end