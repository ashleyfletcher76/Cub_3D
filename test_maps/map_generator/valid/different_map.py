def generate_u_shape_map(width, height):
	with open("u_shape_map.cub", "w") as file:
		for y in range(height):
			line = ""
			if y == 0 or y == height - 1:
				line = '1' * width
			else:
				if y < height // 2:
					line = '1' + '0' * (width - 2) + '1'
				else:
					line = '1' * width
			file.write(line + "\n")

def generate_cross_shape_map(width, height):
	with open("cross_shape_map.cub", "w") as file:
		mid_x = width // 2
		mid_y = height // 2
		for y in range(height):
			line = ""
			if y == 0 or y == height - 1:
				line = '1' * width
			else:
				line = []
				for x in range(width):
					if x == 0 or x == width - 1 or x == mid_x or y == mid_y:
						line.append('1')
					else:
						line.append('0')
				line = ''.join(line)
			file.write(line + "\n")

map_width = 100
map_height = 100

# Generate U-shaped and Cross-shaped maps
generate_u_shape_map(map_width, map_height)
generate_cross_shape_map(map_width, map_height)
