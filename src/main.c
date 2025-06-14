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
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }


  if ( strncmp( configuration.command, "dimension",9) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    dimension(configuration.filenames[0]);
  }

 if ( strncmp( configuration.command, "second_line",11) == 0 ) {

    second_line(configuration.filenames[0]);
  }


  if ( strncmp( configuration.command, "min_pixel",9) == 0 ) {

    min_pixel(configuration.filenames[0]);
  }


  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
      /* first_pixel() function is defined in feature.h and implemented in feature.c */
      first_pixel(configuration.filenames[0]);
  }
  
if (strncmp(configuration.command, "print_pixel", 12) == 0) {
    if (configuration.arguments[0] == NULL || configuration.arguments[1] == NULL) {
        printf("Erreur: coordonnées manquantes. Usage: -c print_pixel <X> <Y>\n");
        return 1;
    }
    
    int pixel_x = atoi(configuration.arguments[0]);
    int pixel_y = atoi(configuration.arguments[1]);
    
    print_pixel(configuration.filenames[0], pixel_x, pixel_y);
}
if (strncmp(configuration.command, "max_component", 13) == 0) {
    if (configuration.arguments[0] == NULL) {
        return 1;
    }
    
    char component = configuration.arguments[0][0]; // Premier caractère de l'argument (R, G ou B)
    max_component(configuration.filenames[0], component);
}

if ( strncmp( configuration.command, "color_green", 11 ) == 0 ) {
    color_green(configuration.filenames[0]);
}
if ( strncmp( configuration.command, "stat_report", 11 ) == 0 ) {
  stat_report(configuration.filenames[0]);
}





  if ( strncmp( configuration.command, "min_component", 13 ) == 0 ) {
    min_component(configuration.filenames[0], configuration.arguments[0][0]);
  }

  

if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    color_red(configuration.filenames[0]);
  }

if ( strncmp( configuration.command, "color_desaturate", 16) ==0) {
  color_desaturate( configuration.filenames[0]);
}


  return 0;
}
