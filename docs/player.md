Key points

* For the player, we iterate through the map to find the start position (NSEW) and use this position to position the pixel. We then use a double while loop to create a small pixel block of colour and multiply the positon by the grid size.

* We added another condition to check if the player/pixel is larger than zero but smaller smaller than the image->width and image->height to prevent a seg fault when the player goes out of the screen. See draw_grid.c source file.

* Players default are stored before drawing begins, this way we can reset the players position using "P" key. This is part of the hooks features.

* We have a collision feature, we take the current value, add or subtract how much we want to move, this is stored inside double data type, we check the condition of that particular cell inside the grid(see is wall function), if the map coordinate is a '1' then we do not allow movement into that grid point.
