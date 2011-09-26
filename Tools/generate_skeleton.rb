#!/usr/bin/ruby

subdir = ARGV[0]
name   = ARGV[1]

unless name.nil? && subdir.nil?
    header = File.open("#{subdir}/#{name}.h", "w")
    header.puts "#ifndef #{name.upcase}_H"
    header.puts "#define #{name.upcase}_H"
    header.puts ""
    header.puts "class #{name} {"
    header.puts "public:"
    header.puts "    #{name}();"
    header.puts "    virtual ~#{name}();"
    header.puts ""
    header.puts "private:"
    header.puts "};"
    header.puts ""
    header.puts "#endif"
    header.close()

    source = File.open("#{subdir}/#{name}.cpp", "w")
    source.puts "#include <#{subdir}/#{name}.h>"
    source.puts ""
    source.puts "#{name}::#{name}() {"
    source.puts "}"
    source.puts ""
    source.puts "#{name}::~#{name}() {"
    source.puts "}"
    source.close()
end
