import random

def generate_random_shape_map(width, height, wall_probability=0.2):
	with open("random_shape_map.cub", "w") as file:
		for y in range(height):
			line = ""
			for x in range(width):
				if x == 0 or x == width - 1 or y == 0 or y == height - 1:
					line += '1'
				else:
					line += '1' if random.random() < wall_probability else '0'
			file.write(line + "\n")

map_width = 100
map_height = 100

# Generate the random shaped map
generate_random_shape_map(map_width, map_height)
