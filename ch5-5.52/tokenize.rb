def tokenize str
  scanner = StringScanner.new(str)
  tokenized = []

  until scanner.eos?
    scanner.scan(/\s+/) ? nil :
    scanner.scan(/\(/) ? tokenized << scanner.matched :
    scanner.scan(/\)/) ? tokenized << scanner.matched :
    scanner.scan(/[a-z0-9A-Z\;\:\"\'\-\=\_\*\?\!\>\<\/]+/) ? tokenized << scanner.matched :
    nil
  end
  tokenized
end

def read_from tokens
  token = tokens[0]
  tokens.delete_at(0)

  if token == "("
    cell = ConsCell.new
    while tokens[0] != ")"
      cell.push read_from tokens
    end

    tokens.delete_at(0)
    return cell
  end
  return atom token
end


