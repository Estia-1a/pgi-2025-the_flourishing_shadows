#ifndef FEATURES_H
#define FEATURES_H

void helloWorld();
void dimension (const char *source_path);
void first_pixel (const char *source_path);
void tenth_pixel (const char *source_path);
void second_line(const char *source_path);
void print_pixel(const char *filename, int x, int y );
int* max_pixel(const char *filename);
int* min_pixel(const char *filename);
int max_component(const char *source_path, const char *pixel);
int min_component(const char *source_path, const char *pixel);
void stat_report(const char *source_path);
void color_red(const char *source_path);
void color_green(const char *source_path);
void color_blue(const char *source_path);
#endif
