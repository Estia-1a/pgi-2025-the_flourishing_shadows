#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */
void dimension(char *source_path) 
{
    unsigned char *data;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels) != 0) 
    {
        printf("dimension: %d, %d\n", width, height);
    }
}

void first_pixel(char *source_path) 
{
    unsigned char *data;
    int width, height, channels;

    read_image_data(source_path, &data, &width, &height, &channels)
    printf("first_pixel : %d, %d, %d",data[0], data[1], data[2]);
}

void helloWorld() {
    printf("Hello World !");
}

void dimension(const char *source_path) {
    unsigned char *data;
    int w, h, n;
    
    read_image_data(source_path, &data, &w, &h, &n);
    printf("Dimension : %d, %d\n", w, h);
}

void first_pixel (const char *source_path){
    unsigned char *data;
    int w, h, n, r, g, b;
    
    read_image_data(source_path, &data, &w, &h, &n);
    r = data[0];
    g = data[1];
    b = data[2];
    printf("first_pixel: %d, %d, %d\n",r,g,b);
}

void tenth_pixel (const char *source_path){
    unsigned char *data;
    int w, h, n, r, g, b;
    
    read_image_data(source_path, &data, &w, &h,&n);
    r = data[27];
    g = data[28];
    b = data[29];
    printf("tenth_pixel: %d, %d, %d\n",r,g,b);
}

void second_line(const char *source_path) {
    unsigned char *data;
    int w, h, n, r, g, b;
    read_image_data(source_path, &data, &w, &h,&n);

    r = data[3*w];
    g = data[3*w+1];
    b = data[3*w+2];
    printf("second_line: %d, %d, %d\n", r, g, b);
}

void print_pixel( char *filename, int x, int y ) {
    unsigned char *data;
    int w, h, n, r, g, b;
    pixelRGB *pixel = read_image_data(filename, &data, &w, &h,&n);

    get_pixel(data, w, h, n, x, y);
    printf("print_pixel ( %d, %d) : %d, %d, %d)", x, y, pixel->R, pixel->G, pixel->B);
}