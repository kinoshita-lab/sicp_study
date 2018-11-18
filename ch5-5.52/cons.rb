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

    def atom?
        return @car != nil && @cdr == nil
    end

    def cons?
        return (!@car.atom?) && @cdr != nil
    end

    def to_s
        if nil?
            return "nil "
        end

        if atom?
            return @car.to_s
        end

        # cons cell
        r = "("
        cell = self
      
        while cell
            cellcar = cell.car
            r += cell.car.to_s
            cell = cell.cdr
            if cell != nil 
                r += " "
            end
        end

        r += ")"
    end

    def length
        length = 0
        if (! @car.nil?)
            length += 1
        end
        if (! @cdr.nil?)
            length += @cdr.length
        end

        length
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

def caddr cell
    car(cddr(cell))
end