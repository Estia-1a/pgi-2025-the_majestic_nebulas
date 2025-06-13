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
    printf(" Hello World !");
}

void tenth_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    
    // Charger les données de l'image avec read_image_data
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    
    // Extraire les composantes RGB
    unsigned char R = data[27];  // index 27
    unsigned char G = data[28];  // index 28
    unsigned char B = data[29];  // index 29
    
    // Afficher le résultat dans le format requis
    printf("tenth_pixel: %d, %d, %d", R, G, B);
    
    
}