#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) 
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) 
  {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    dimension( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel( configuration.filenames[0] );
}
  if ( strncmp( configuration.command, "tenth_pixel", 12 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    tenth_pixel( configuration.filenames[0] );
}
  if ( strncmp( configuration.command, "second_line", 13 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    second_line( configuration.filenames[0] );
  }
  if ( strcmp( configuration.command, "print_pixel" ) == 0 ) {
    if ( configuration.filenames[0] != NULL && 
         configuration.arguments[0] != NULL && 
         configuration.arguments[1] != NULL ) {
        
        int x = atoi( configuration.arguments[0] );
        int y = atoi( configuration.arguments[1] );
        
        print_pixel( configuration.filenames[0], x, y );
      }
  }

  if ( strncmp( configuration.command, "max_component", 15 ) == 0 ) {
  /* max_component() function is defined in feature.h and implemented in feature.c */
  max_component( configuration.filenames[0], configuration.arguments[0] );
}
if (strcmp(configuration.command, "max_pixel")==0){
  if (configuration.filenames[0] != NULL){
    max_pixel(configuration.filenames[0]);
  }
}
if (strcmp(configuration.command, "min_pixel")==0){
  if (configuration.filenames[0] != NULL){
    min_pixel(configuration.filenames[0]);
  }
}
  if ( strncmp( configuration.command, "min_component", 15 ) == 0 ) {
  /* min_component() function is defined in feature.h and implemented in feature.c */
  min_component( configuration.filenames[0], configuration.arguments[0] );
}
  if ( strncmp( configuration.command, "stat_report", 16 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    stat_report( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    color_red( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_green", 11 ) == 0 ) {
     color_green( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_blue", 10 ) == 0 ) {
    color_blue( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_gray", 12 ) == 0 ) {
    color_gray( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_invert", 12 ) == 0 ) {
    color_invert( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_gray_luminance", 12 ) == 0 ) {
    color_gray_luminance( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_desaturate", 12 ) == 0 ) {
  color_desaturate( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "rotate_cw", 12 ) == 0 ) {
  rotate_cw( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "rotate_acw", 12 ) == 0 ) {
  rotate_acw( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "mirror_horizontal", 12 ) == 0 ) {
  mirror_horizontal( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "mirror_vertical", 12 ) == 0 ) {
  mirror_vertical( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "mirror_total", 12 ) == 0 ) {
  mirror_total( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "scale_nearest", 15 ) == 0 ) {
scale_nearest( configuration.filenames[0], atof(configuration.arguments[0]) );
}
if ( strncmp( configuration.command, "scale_bilinear", 15 ) == 0 ) {
scale_bilinear( configuration.filenames[0], atof(configuration.arguments[0]) );
}
if ( strncmp( configuration.command, "scale_crop", 15 ) == 0 ) {
scale_crop( configuration.filenames[0], atoi(configuration.arguments[0]),atoi(configuration.arguments[1]), atoi(configuration.arguments[2]),atoi(configuration.arguments[3]));
}

return 0;
}
  