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

void print_pixel(const char *filename, int x, int y) {
    unsigned char *data;
    int w, h, n;

    int result = read_image_data(filename, &data, &w, &h, &n);
    
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    if (x < 0 || x >= w || y < 0 || y >= h) {
        printf("Erreur: coordonnées hors limites (%d, %d)\n", x, y);
        return;
    }
    
    pixelRGB *current_pixel = get_pixel(data, w, h, n, x, y);
    printf("print_pixel (%d, %d): %d, %d, %d\n",x, y, current_pixel->R, current_pixel->G, current_pixel->B);

}

void max_pixel(const char *filename) {
    unsigned char *data;
    int w,h,n;

    int result = read_image_data(filename,&data,&w,&h,&n);
 
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    int somme=0, somme_max=-1, x_max=0, y_max=0;
    unsigned char r_max=0, g_max=0, b_max=0;

    for(int y=0;y<h; y++)
    {
        for(int x=0;x<w;x++)
        {
            pixelRGB *current_pixel = get_pixel(data,w,h,n,x,y);

            if (current_pixel==NULL)
            {
                printf("Erreur");
                return;
            }

            somme = current_pixel->R + current_pixel->G + current_pixel->B;  
            
            if(somme>somme_max)
            {
                somme_max=somme;
                x_max=x;
                y_max=y;
                r_max=current_pixel->R;
                g_max=current_pixel->G;
                b_max=current_pixel->B;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d\n", x_max, y_max, r_max, g_max, b_max);
}