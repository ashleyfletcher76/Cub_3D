Key points

* We firstly multiply the the map height and width by the a pre-defined number of pixels. We use this value to determin the size of the minimap, so it get larger with bigger maps and smaller with smaller ones.

* We have pre defined min and max values to ensure the map is a reasonable size. We then find the fmin between the base_height/width and the MAX corresponding value. Then we find the fmax between this value and the MIN_MAP corresponding value.

* Map conditions will find the corresponding tile from the larger map using th previous scale we have defined.

* Non gird lines functions divide the maps evenly using modulo and then gives this pixel the corresponding the colour value.
