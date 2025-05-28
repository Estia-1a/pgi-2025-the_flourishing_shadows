#include <estia-image.h>
#include "utils.h"
#include <stdio.h>

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

 pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    
    if (data == NULL) {
        return(NULL);
    }
    if ((x >= width) || (y >= height)) {
        return(NULL);
    }
      return (pixelRGB *) &data[(y * width + x) * n] ;
}
