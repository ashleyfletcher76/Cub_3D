Key points

* Map is 2d array
* Read line bye line(get_next_line)
* All values are kept as is, i.e. spaces included.

* Now we have a map intialized to zero, we want to add the values inside the map coordinates. The map will be a 2D array.

* Once the correct values have been placed into the map, we will make one final check to make the sure the map parameters have been met i.e. the outside walls are all correctly '1', siginifying they are walls. See check_arg doc.

* Using a second function to read line by line and not do them in the previous check_arg functions, is to prevent malloc'ing when the intial checks were done. This is better to prevent unneccesary mallocing, but is admitedly not the great doing multiple read line checks.

* The purpose of this final check being after malloc'ing, we can then check the index of the line above or below. If the line index above or below is a space then the current value must be a '1'. Omnidirectional.

* Another check is for the multiple start positions. This has been implemented in this stage after the map has been initialized. Now we use a checker to see if "NSEW" has been found multiple times, if yes, invalid map.
