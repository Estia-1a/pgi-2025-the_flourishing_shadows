#include <estia-image.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("print_pixel (%d, %d): %d, %d, %d\n", 
           x, y, current_pixel->R, current_pixel->G, current_pixel->B);

}



int* min_pixel(const char *filename) {
    unsigned char *data;
    int w,h,n;
    int* resultat=malloc(2);
    int result = read_image_data(filename,&data,&w,&h,&n);
 
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        
    }
 
    int sum=0, sum_min=765, x_min=0, y_min=0; 
    unsigned char r_min=0, g_min=0, b_min=0;
 
    for(int y=0;y<h; y++)
    {
        for(int x=0;x<w;x++)
        {
            pixelRGB *current_pixel = get_pixel(data,w,h,n,x,y);
 
            if (current_pixel==NULL)
            {
                printf("Erreur");
                
            }
 
            sum = current_pixel->R + current_pixel->G + current_pixel->B;  
           
            if(sum<sum_min)
            {
                sum_min=sum;
                x_min=x;
                y_min=y;
                r_min=current_pixel->R;
                g_min=current_pixel->G;
                b_min=current_pixel->B;
            }
        }
    }
    resultat[0]=x_min;
    resultat[1]=y_min;
    printf("min_pixel (%d, %d): %d, %d, %d\n", x_min, y_min, r_min, g_min, b_min);
    return(resultat);
}

int* max_pixel(const char *filename) {
    unsigned char *data;
    int* resultat=malloc(2);
    int w,h,n;

    int result = read_image_data(filename,&data,&w,&h,&n);
 
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        
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
    resultat[0]=x_max;
    resultat[1]=y_max;
    printf("max_pixel (%d, %d): %d, %d, %d\n", x_max, y_max, r_max, g_max, b_max);
    return (resultat);
}



int max_component(const char *source_path, const char *pixel) {
    unsigned char *data;
    int w, h, n, max = 0;
    int x_max = 0, y_max = 0;
    int result = read_image_data(source_path, &data, &w, &h, &n);
    
    if (result == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        
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
    int *mxpixel;
    int *mnpixel;
    int maxxp = 0,maxyp = 0, minxp = 0,minyp = 0, maxcR = 0, maxcG = 0, maxcB = 0, mincR = 0, mincG = 0, mincB = 0;

    stat = fopen("stat.txt","w");
    mxpixel = max_pixel(source_path);
    mnpixel = min_pixel(source_path);
    maxcR = max_component(source_path,"R");
    maxcG = max_component(source_path,"G");
    maxcB = max_component(source_path,"B");
    mincR = min_component(source_path,"R");
    mincB = min_component(source_path,"B");
    mincG = min_component(source_path,"G");
    maxxp = mxpixel[0];  
    maxyp = mxpixel[1];
    minxp = mnpixel[0];
    minyp = mnpixel[1];
    
    fprintf(stat, "%d,%d\n %d,%d\n %d\n %d\n %d\n %d\n %d\n %d\n",maxxp,maxyp,minxp,minyp,maxcR,maxcB,maxcG,mincR,mincG,mincB);
    fclose(stat);
}

void color_red(const_char *sourcepath){
}

