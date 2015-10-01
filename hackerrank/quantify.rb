def here
	puts "hello"
end
test = $stdin.gets.chomp.split
arr = []
(1..(test[1].to_i)).each do |i|
	arr[i] = $stdin.gets.chomp.split
end
count = 0
while(line = gets)
	self.here
end