def generate_large_map(width, height):
	with open("valid_map.cub", "w") as file:
		for y in range(height):
			line = ""
			for x in range(width):
				if x == 0 or x == width - 1 or y == 0 or y == height - 1:
					line += '1'
				else:
					line += '0'
			file.write(line + "\n")

map_width = 100
map_height = 100

# Generate the map
generate_large_map(map_width, map_height)
