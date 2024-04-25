Key points

* Map is 2d array
* Read line bye line(get_next_line)
* All values are kept as is, i.e. spaces included.

* Now we have a map intialized to zero, we want to add the values inside the map coordinates. The map will be a 2D array.

* Once the correct values have been placed into the map, we will make one final check to make the sure the map parameters have been met i.e. the outside walls are all correctly '1', siginifying they are walls. See check_arg doc.

* Using a second function to read line by line and not do them in the previous check_arg functions, is to prevent malloc'ing when the intial checks were done. This is better to prevent unneccesary mallocing, but is admitedly not the great doing multiple read line checks.

* We check omnidirectionally to see if the last value that is not space, \0 or \n and if yes, then we know the perimeter is secure. Otherwise we exit.

* We also check the columns and if they are also just spaces we then make changes to the map data. We take the old map and give the new_map the correct values up till the space column and then proceed to skip this column and finish until the end of the line. Then find this column for each row. This process is repeated for any following space columns.

* Finally the old map is freed and then given the new_maps value after. Map width is then subtracted by one to ensure an accurate map.

* Another check is for the multiple start positions. This has been implemented in this stage after the map has been initialized. Now we use a checker to see if "NSEW" has been found multiple times, if yes, invalid map.

* We also now have a flood fill checker to check the perimeter. This flood fill creates a stack and will move around the grid checking if it has reached width = 0, height = 0, width max and height max. In this case the perimeter would have been breached as it should not escape the 1's(walls). We start the search from the plasyers position.

* We check previously with another method to avoid malloc'ing when unnecessary.
