def generate_large_map(width, height, breaches=[]):
	with open("false_map.cub", "w") as file:
		for y in range(height):
			line = ""
			for x in range(width):
				if (x == 0 or x == width - 1 or y == 0 or y == height - 1):
					if (x, y) in breaches:
						line += '0'
					else:
						line += '1'
				else:
					line += '0'
			file.write(line + "\n")

map_width = 100
map_height = 100

# Coordinates where breaches should occur, for example at the middle of the bottom row
breaches = [(map_width // 2, map_height - 1)]

generate_large_map(map_width, map_height, breaches)
