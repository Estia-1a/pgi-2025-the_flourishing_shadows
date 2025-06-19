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
int resultat[2];
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
    
    fprintf(stat, "%d,%d\n%d,%d\n%d\n%d\n%d\n%d\n%d\n%d\n",maxxp,maxyp,minxp,minyp,maxcR,maxcB,maxcG,mincR,mincG,mincB);
    fclose(stat);
}

void color_red(const char *source_path) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            int pos = (ligne * w + colonne) * 3;
            
            
            data[pos + 1] = 0;
            data[pos + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void color_green(const char *source_path) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    for (int ligne = 0; ligne < h; ligne++) {
    for (int colonne = 0; colonne < w; colonne++) {
        int pos = (ligne * w + colonne) * 3;
        
        
        data[pos + 1] = 0;
        data[pos + 2] = 0;
    }
}
write_image_data("image_out.bmp", data, w, h);
    
}

void color_blue(const char *source_path) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    for (int ligne = 0; ligne < h; ligne++) {
    for (int colonne = 0; colonne < w; colonne++) {
        int pos = (ligne * w + colonne) * 3;
        
        
        data[pos + 1] = 0;
        data[pos + 2] = 0;
    }
}
write_image_data("image_out.bmp", data, w, h);

}

void color_gray(const char *source_path){
    unsigned char *data;
    int w, h, n;
    unsigned char r, g, b;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            pixelRGB *current_pixel = get_pixel(data, w, h, n, colonne, ligne);
            
            r = current_pixel->R;
            g = current_pixel->G;
            b = current_pixel->B;
            
            unsigned char valeur_grise = (r + g + b) / 3;
            
            current_pixel->R = valeur_grise;
            current_pixel->G = valeur_grise;
            current_pixel->B = valeur_grise;
        }
    }
    
    write_image_data("image_out.jpeg", data, w, h);
}

void color_invert(const char *source_path){
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    unsigned char nouvelles_donnees[w * h * 3];
	
    for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            int pos = (ligne * w + colonne) * 3;
        
            nouvelles_donnees[pos] = 255 - data[pos];
            nouvelles_donnees[pos + 1] = 255 - data[pos+1];
            nouvelles_donnees[pos + 2] = 255 - data[pos+2];
        }
    }
    
    write_image_data("image_out.bmp", nouvelles_donnees, w, h);
    
}

void color_gray_luminance(const char *source_path) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    unsigned char nouvelles_donnees[w * h * 3];
    unsigned char value = 0;
	
    for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            int pos = (ligne * w + colonne) * 3;
            value = 0.21 * get_pixel(data,w,h,n,colonne,ligne)->R + 0.72 * get_pixel(data,w,h,n,colonne, ligne)->G + 0.07 * get_pixel(data,w,h,n,colonne,ligne)->B;
            nouvelles_donnees[pos] = value;
            nouvelles_donnees[pos + 1] = value;
            nouvelles_donnees[pos + 2] = value;
        }
    }
    write_image_data("image_out.bmp", nouvelles_donnees, w, h);
    return;
}

int max(int R, int G, int B) {
    int maximum = R;
    if (G > maximum) maximum = G;
    if (B > maximum) maximum = B;
    return maximum;
}

int min(int R, int G, int B) {
    int minimum = R;
    if (G < minimum) minimum = G;
    if (B < minimum) minimum = B;
    return minimum;
}

void color_desaturate(const char *source_path) {
    unsigned char *data;
    int w, h, n;
    unsigned char r=0, g=0, b=0;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    int new_val = 0;

    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    unsigned char nouvelles_donnees[w * h * 3];

    for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            int pos = (ligne * w + colonne) * 3;

            pixelRGB *current_pixel = get_pixel(data,w,h,n,colonne,ligne);
            r = current_pixel->R;
            g = current_pixel->G;
            b = current_pixel->B;

            new_val = ((min(r, g, b) + max(r, g, b)) / 2);
            nouvelles_donnees[pos] = new_val;
            nouvelles_donnees[pos + 1] = new_val;
            nouvelles_donnees[pos + 2] = new_val; 

        }
    }
    write_image_data("image_out.bmp", nouvelles_donnees, w, h);
    return;
    
}

void rotate_cw(const char *source_path){
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    unsigned char nouvelles_donnees[w * h * 3];

    int nvh=w;
    int nvw=h;

     for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            int pos = (ligne * w + colonne) * 3;
            
            int nvcolonne=h-1-ligne;
            int nvligne=colonne;
            int nvpos=(nvligne*nvw+nvcolonne)*3;
            nouvelles_donnees[nvpos] = data[pos];
            nouvelles_donnees[nvpos + 1] = data[pos+1];
            nouvelles_donnees[nvpos + 2] = data[pos+2];
        }
    }
    
    write_image_data("image_out.bmp", nouvelles_donnees, nvw, nvh);  
}

void rotate_acw(const char *source_path){
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    unsigned char nouvelles_donnees[w * h * 3];

    int nvh=w;
    int nvw=h;

     for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {
            int pos = (ligne * w + colonne) * 3;
            
            int nvcolonne=ligne;
            int nvligne=w-1-colonne;
            int nvpos=(nvligne*nvw+nvcolonne)*3;
            nouvelles_donnees[nvpos] = data[pos];
            nouvelles_donnees[nvpos + 1] = data[pos+1];
            nouvelles_donnees[nvpos + 2] = data[pos+2];
        }
    }
    
    write_image_data("image_out.bmp", nouvelles_donnees, nvw, nvh);
      
}

void mirror_vertical(const char *source_path){
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    for (int ligne = 0; ligne < h / 2; ligne++) {
        for (int colonne = 0; colonne < w; colonne++) {

            pixelRGB *pixel_haut = get_pixel(data, w, h, n, colonne, ligne);
            pixelRGB *pixel_bas = get_pixel(data, w, h, n, colonne, h - 1 - ligne);
            
            pixelRGB temp = *pixel_haut;
            *pixel_haut = *pixel_bas;
            *pixel_bas = temp;
        }
    }
    
    write_image_data("image_out.bmp", data, w, h);
}

void mirror_horizontal(const char *source_path){
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    for (int ligne = 0; ligne < h; ligne++) {
        for (int colonne = 0; colonne < w / 2; colonne++) {
            pixelRGB *pixel_gauche = get_pixel(data, w, h, n, colonne, ligne);
            pixelRGB *pixel_droite = get_pixel(data, w, h, n, w - 1 - colonne, ligne);

            pixelRGB temp = *pixel_gauche;
            *pixel_gauche = *pixel_droite;
            *pixel_droite = temp;
        }
    }
    
    write_image_data("image_out.bmp", data, w, h);
}

void mirror_total(const char *source_path){
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }

    int total_pixels = w * h;
    for (int i = 0; i < total_pixels / 2; i++) {
        int ligne1 = i / w;
        int colonne1 = i % w;
        
        int ligne2 = h - 1 - ligne1;
        int colonne2 = w - 1 - colonne1;
        
        pixelRGB *pixel1 = get_pixel(data, w, h, n, colonne1, ligne1);
        pixelRGB *pixel2 = get_pixel(data, w, h, n, colonne2, ligne2);
        
        pixelRGB temp = *pixel1;
        *pixel1 = *pixel2;
        *pixel2 = temp;
    }
    
    write_image_data("image_out.bmp", data, w, h);
}

void scale_nearest(const char *source_path, float scale_factor) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    if (scale_factor <= 0) {
        printf("Erreur: facteur d'échelle invalide\n");
        return;
    }
    
    int new_w = (int)(w * scale_factor);
    int new_h = (int)(h * scale_factor);
    
    if (new_w <= 0 || new_h <= 0) {
        printf("Erreur: dimensions résultantes invalides\n");
        return;
    }
    
    unsigned char nouvelles_donnees[new_w * new_h * 3];
    
    for (int new_y = 0; new_y < new_h; new_y++) {
        for (int new_x = 0; new_x < new_w; new_x++) {
            int orig_x = (int)(new_x / scale_factor);
            int orig_y = (int)(new_y / scale_factor);
            
            if (orig_x >= w) orig_x = w - 1;
            if (orig_y >= h) orig_y = h - 1;
            
            int orig_pos = (orig_y * w + orig_x) * 3;
            int new_pos = (new_y * new_w + new_x) * 3;
            
            nouvelles_donnees[new_pos] = data[orig_pos];
            nouvelles_donnees[new_pos + 1] = data[orig_pos + 1];
            nouvelles_donnees[new_pos + 2] = data[orig_pos + 2];
        }
    }
    
    write_image_data("image_out.bmp", nouvelles_donnees, new_w, new_h);
    
}

void scale_bilinear(const char *source_path, float scale_factor) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    if (scale_factor <= 0) {
        printf("Erreur: facteur d'échelle invalide\n");
        return;
    }
    
    int new_w = (int)(w * scale_factor);
    int new_h = (int)(h * scale_factor);
    
    if (new_w <= 0 || new_h <= 0) {
        printf("Erreur: dimensions résultantes invalides\n");
        return;
    }
    
    unsigned char nouvelles_donnees[new_w * new_h * 3];
    
    for (int new_y = 0; new_y < new_h; new_y++) {
        for (int new_x = 0; new_x < new_w; new_x++) {
            float orig_x_f = (float)new_x / scale_factor;
            float orig_y_f = (float)new_y / scale_factor;
            
            int x1 = (int)orig_x_f;
            int y1 = (int)orig_y_f;
            int x2 = x1 + 1;
            int y2 = y1 + 1;
            
            if (x2 >= w) x2 = w - 1;
            if (y2 >= h) y2 = h - 1;
            
            float dx = orig_x_f - x1;
            float dy = orig_y_f - y1;
            
            int pos_tl = (y1 * w + x1) * 3;
            int pos_tr = (y1 * w + x2) * 3;
            int pos_bl = (y2 * w + x1) * 3;
            int pos_br = (y2 * w + x2) * 3;
            
            int new_pos = (new_y * new_w + new_x) * 3;
            
            for (int c = 0; c < 3; c++) {
                float top = data[pos_tl + c] * (1 - dx) + data[pos_tr + c] * dx;
                float bottom = data[pos_bl + c] * (1 - dx) + data[pos_br + c] * dx;
                float result = top * (1 - dy) + bottom * dy;
                
                nouvelles_donnees[new_pos + c] = (unsigned char)result;
            }
        }
    }
    
    write_image_data("image_out.bmp", nouvelles_donnees, new_w, new_h);

}

void scale_crop(const char *source_path, int center_x, int center_y, int crop_w, int crop_h) {
    unsigned char *data;
    int w, h, n;
    int resultat = read_image_data(source_path, &data, &w, &h, &n);
    
    if (resultat == 0 || data == NULL) {
        printf("Erreur: impossible de lire l'image\n");
        return;
    }
    
    if (crop_w <= 0 || crop_h <= 0) {
        printf("Erreur: dimensions de crop invalides\n");
        return;
    }
    
    unsigned char nouvelles_donnees[crop_w * crop_h * 3];
    
    int start_x = center_x - crop_w / 2;
    int start_y = center_y - crop_h / 2;
    
    for (int crop_y = 0; crop_y < crop_h; crop_y++) {
        for (int crop_x = 0; crop_x < crop_w; crop_x++) {
            int orig_x = start_x + crop_x;
            int orig_y = start_y + crop_y;
            
            int crop_pos = (crop_y * crop_w + crop_x) * 3;
            
            if (orig_x >= 0 && orig_x < w && orig_y >= 0 && orig_y < h) {
                int orig_pos = (orig_y * w + orig_x) * 3;
                nouvelles_donnees[crop_pos] = data[orig_pos];
                nouvelles_donnees[crop_pos + 1] = data[orig_pos + 1];
                nouvelles_donnees[crop_pos + 2] = data[orig_pos + 2];
            } else {
                nouvelles_donnees[crop_pos] = 0;
                nouvelles_donnees[crop_pos + 1] = 0;
                nouvelles_donnees[crop_pos + 2] = 0;
            }
        }
    }
    
    write_image_data("image_out.bmp", nouvelles_donnees, crop_w, crop_h);
    
}