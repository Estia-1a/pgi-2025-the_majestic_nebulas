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
    printf(" hello Word !");
}


/*
fonction pour trouver la dimension de l'image
Le paramètre c'est le source_path, pour qu'on puisse obtenir 
les données de l'image et ici largeur (width) et hauteur (height)
la fonction renvoie deux valeurs, largeur et hauteur
*/ 


void dimension(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    /*on vérifie si nous avons bien des données pour évité tout beug*/
    if (read_image_data(source_path, &data, &width, &height, &channels)) {

        printf("dimension: %d, %d\n", width, height);
    } 
    else {
        fprintf(stderr, "problème sur le source_path %s\n", source_path);
    }

    if (data != NULL) {
        free(data);
    }
}

/*
fonction pour affiché les couleurs RBG du premier Pixel 
de la ligne 2, de coordonée (1,0)
paramétre de la fonction le source_path pour obtenir les données
de l'image
renvoie trois valeurs correspondant au RGB du pixel (1,0)
*/



void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    /*on vérifie si nous avons bien des données pour évité tout beug*/
    if (read_image_data(source_path, &data, &width, &height, &channels)) {

        int index = (1 * width + 0) * channels;

        printf("second_line: %d, %d, %d\n", data[index], data[index + 1], data[index + 2]);
    } 
    else {
        fprintf(stderr, "problème sur le source_path %s\n", source_path);
    }

    if (data != NULL) {
        free(data);
    }
}


void min_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channels;

        /*on vérifie si nous avons bien des données pour évité tout beug*/
        if (read_image_data(source_path, &data, &width, &height, &channels)) {

            int min_sum = 256 * 3;  // max possible RGB sum is 255+255+255 = 765
            int min_x = 0, min_y = 0;
            int min_r = 0, min_g = 0, min_b = 0;
    
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    int index = (y * width + x) * channels;
                    int r = data[index];
                    int g = data[index + 1];
                    int b = data[index + 2];
                    int sum = r + g + b;
    
                    if (sum < min_sum) {
                        min_sum = sum;
                        min_x = x;
                        min_y = y;
                        min_r = r;
                        min_g = g;
                        min_b = b;
                    }
                }
            }



            printf("min_pixel(%d,%d): %d, %d, %d\n",min_x, min_y, min_r, min_g, min_b);
        }
        else {
            fprintf(stderr, "problème sur le source_path %s\n", source_path);
        }
    
        if (data != NULL) {
            free(data);
        }
}