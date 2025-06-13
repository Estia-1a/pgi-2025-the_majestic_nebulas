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

void max_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    int max_sum = -1, max_x = 0, max_y = 0;
    unsigned char r, g, b;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width + x) * channels;
            int sum = data[i] + data[i + 1] + data[i + 2];

            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                r = data[i];
                g = data[i + 1];
                b = data[i + 2];
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, r, g, b);
    }