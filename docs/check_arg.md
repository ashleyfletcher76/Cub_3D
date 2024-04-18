Key points

* Use a temp cube structure to avoid allocating memeory in the inital checks for map validation.

* Check argument count and check for correct map name(.cub)

* Read line by line to check the validity

* When reading line by line we increase the map height and simultaneously fidn the max width

* We use a valid char checker('0' '1' 'N' 'S' 'W' 'E')

* If the conditions are not correct we exit before any memory allocation and then print our relevant message
