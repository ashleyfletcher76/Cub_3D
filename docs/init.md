Key points

* We initialize the window through the MLX42 library. Using the relevant external library functions for window creation. See MLX42 library docs.

* We initalize the window size to 1920 * 1080

* Because we have done initial checks for map validity we now malloc a t_cube structure which will be sued throughout the rest of the program. See init_cube function.

* Now the intial strucutre has been initialized, we can start to create the map structure. See init_map function.

* We use the max_height and max_width values from our previous temp_cube structure to create the relevant map size.
