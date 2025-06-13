#include <estia-image.h>
#include <stdio.h>
#include <string.h>

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

<<<<<<< HEAD
void max_pixel(const char *filename) {
    unsigned char *data;
    int w,h,n;

    int result = read_image_data(filename,&data,&w,&h,&n);
 
=======
























































































int max_component(const char *source_path, const char *pixel) {
    unsigned char *data;
    int w, h, n, max = 0;
    int x_max = 0, y_max = 0;
    int result = read_image_data(source_path, &data, &w, &h, &n);
    
>>>>>>> 5b7888e88fbe7be95b879c0ab5c7639605e2d3a8
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
<<<<<<< HEAD

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
=======
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {       
            pixelRGB *current_pixel = get_pixel(data, w, h, n, x, y);
            
            int current_value = 0;
            if (strcmp(pixel, "R") == 0) {
                current_value = current_pixel->R;
            } else if (strcmp(pixel, "G") == 0) {
                current_value = current_pixel->G;
            } else if (strcmp(pixel, "B") == 0) {
                current_value = current_pixel->B;
            }
            
            if (current_value > max) {
                max = current_value;
                x_max = x;
                y_max = y;
            }
        }
    }
    
    printf("max_component %s (%d, %d): %d\n", pixel, x_max, y_max, max);
    return(max);
}

int min_component(const char *source_path, const char *pixel) {
    unsigned char *data;
    int w, h, n, min = 256;
    int x_min = 0, y_min = 0;
    int result = read_image_data(source_path, &data, &w, &h, &n);
    
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {       
            pixelRGB *current_pixel = get_pixel(data, w, h, n, x, y);
            
            int current_value = 0;
            if (strcmp(pixel, "R") == 0) {
                current_value = current_pixel->R;
            } else if (strcmp(pixel, "G") == 0) {
                current_value = current_pixel->G;
            } else if (strcmp(pixel, "B") == 0) {
                current_value = current_pixel->B;
            }
            
            if (current_value < min) {
                min = current_value;
                x_min = x;
                y_min = y;
            }
        }
    }
    
    printf("min_component %s (%d, %d): %d\n", pixel, x_min, y_min, min);
    return(min);
}

void stat_report(const char *source_path) {
    FILE *stat;
    int maxp = 0, minp = 0, maxcR = 0, maxcG = 0, maxcB = 0, mincR = 0, mincG = 0, mincB = 0;
    maxp = max_pixel(source_path);
    minp = min_pixel(source_path);
    maxcR = max_component(source_path,"R");
    maxcG = max_component(source_path,"G");
    maxcB = max_component(source_path,"B");
    mincR = min_component(source_path,"R");
    mincB = min_component(source_path,"B");
    mincG = min_component(source_path,"G");

    fopen("stat.txt","w");
    fprintf(stat, "%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n",maxp,minp,maxcR,maxcB,maxcG,mincR,mincG,mincB);
    fclocle(stat);
}

>>>>>>> 5b7888e88fbe7be95b879c0ab5c7639605e2d3a8
