Key points

* Now we have a map intialized to zero, we want to add the values inside the map coordinates. The map will be a 2D array.

* Once the correct values have been placed into the map, we will make one final check to make the sure the map parameters have been met i.e. the outside walls are all correctly '1', siginifying they are walls.

* Similarly to the previous check_args functions, we will again use get_next_line to read line by line and then assign to corresponding value into the correct coordinate position.

* Using a second function to read line by line and not do them in the previous check_arg functions, is to prevent malloc'ing when the intial checks were done. This is better to prevent unneccesary mallocing, but is admitedly not the great doing multiple read line checks.

* The purpose of this final check being after malloc'ing, we can then check the index of the line above or below. If the line index above or below is a space then the current value must be a '1'.
