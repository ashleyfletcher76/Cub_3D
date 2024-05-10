Key points

* We firstly multiply the the map height and width by the a pre-defined number of pixels. We use this value to determin the size of the minimap, so it get larger with bigger maps and smaller with smaller ones.

* We have pre defined min and max values to ensure the map is a reasonable size. We then find the fmin between the base_height/width and the MAX corresponding value. Then we find the fmax between this value and the MIN_MAP corresponding value.

* Map conditions will find the corresponding tile from the larger map using th previous scale we have defined.

* Non gird lines functions divide the maps evenly using modulo and then gives this pixel the corresponding the colour value.

* We create a pixel scale compared to the size of the map. We take the square root of the total area and divide this by 150. Making lager maps have a bigger base value for the pixel and smaller the oppposite. We then take this value and clamp it ensuring no pixel is too large or small

* We scale down the original maps width and height to a reasonable number, then take the min of these two values for a reasonable scale. The draw height and width is multiplied by the scale so we can get an accurate map but in a reasonable size according to our scale. If the the pixels are 1000 wide and out scale is 0.2, 100 * 0.2 = 200 pixels.
