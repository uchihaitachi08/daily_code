n = $stdin.gets.chomp.to_i
q = $stdin.gets.chomp.to_i
arr = []
(1..n).each do |i|
	num = $stdin.gets.chomp
	arr.push(num);
end 
count = 0
(1..q).each do|j|
	l = $stdin.gets.chomp.to_i
	k = $stdin.gets.chomp.to_i
	(1..n).each do |i|
		if arr[i-1] >= l 
			count++
		end
		if count == k 
			puts(arr[i-1])
			break;
		end
	end
	count = 0
end