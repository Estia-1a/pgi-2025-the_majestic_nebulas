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


/*
fonction pour trouver la dimension de l'image
Le paramètre c'est le source_path, pour qu'on puisse obtenir 
les données de l'image et ici largeur (width) et hauteur (height)
la fonction renvoie deux valeurs, largeur et hauteur
*/ 


void dimension(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    /*on vérifie sous nous avons bien des données pour évité tout beug*/
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        printf("dimension: %d, %d\n", width, height);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
    }

    if (data != NULL) {
        free(data);
    }
}
