Key points

* For the player, we iterate through the map to find the start position (NSEW) and use this position to position the pixel. We then use a double while loop to create a small pixel block of colour and multiply the positon by the grid size.

* We added another condition to check if the player/pixel is larger than zero but smaller smaller than the image->width and image->height to prevent a seg fault when the player goes out of the screen. See draw_grid.c source file.

* Players default are stored before drawing begins, this way we can reset the players position using "P" key. This is part of the hooks features.
