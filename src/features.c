#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"
#include "estia-image.h"


/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("  hello Word !");
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
           
        }
}

void first_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;

    read_image_data(source_path, &data, &width, &height, &channels);

    printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);
}

void print_pixel(char *filename, int x, int y) {
    unsigned char *data;
    int width, height, channels;

    read_image_data(filename, &data, &width, &height, &channels);

    pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);

    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
}
void max_component(char *filename, char component) {
    unsigned char *data;
    int width, height, channels;

    read_image_data(filename, &data, &width, &height, &channels);

    unsigned char max_value = 0;
    int max_x = 0, max_y = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            
            unsigned char current_value;
            if (component == 'R') {
                current_value = pixel->R;
            } else if (component == 'G') {
                current_value = pixel->G;
            } else if (component == 'B') {
                current_value = pixel->B;
            }

            if (current_value > max_value) {
                max_value = current_value;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);

}

void tenth_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    
   
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    
   
    unsigned char R = data[27];  
    unsigned char G = data[28];  
    unsigned char B = data[29];  
    
   
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
   
    void min_component(char *source_path, char component) {
        unsigned char *data;
        int width, height, nbChannels;
        
        read_image_data(source_path, &data, &width, &height, &nbChannels);
        
        int min_value = 256, min_x = 0, min_y = 0;
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int i = (y * width + x) * nbChannels;
                
                int value;
                if (component == 'R') value = data[i];
                else if (component == 'G') value = data[i + 1];
                else value = data[i + 2];
                
                if (value < min_value) {
                    min_value = value;
                    min_x = x;
                    min_y = y;
                }
            }
        }
        
        printf("min_component %c (%d, %d): %d", component, min_x, min_y, min_value);
        
    }

    void color_red(char *source_path) {
        unsigned char *data;
        int width, height, nbChannels;
        
        
        read_image_data(source_path, &data, &width, &height, &nbChannels);
        
       
        for (int i = 0; i < width * height * nbChannels; i += nbChannels) {
           
            data[i + 1] = 0;  
            data[i + 2] = 0;  
        }
        
        
        write_image_data("image_out.bmp", data, width, height);
        

    }

    void color_green(char *source_path) {
        unsigned char *data;
        int width, height, nbChannels;
        
       
        read_image_data(source_path, &data, &width, &height, &nbChannels);
        
       
        for (int i = 0; i < width * height * nbChannels; i += nbChannels) {
            data[i] = 0;     
       
            data[i + 2] = 0;  
        }
        
        write_image_data("image_out.bmp", data, width, height);
        
    }

    void color_invert(char *source_path) {
        unsigned char *data;
        int width, height, channels;
        
        read_image_data(source_path, &data, &width, &height, &channels);
        
        for (int i = 0; i < width * height * channels; i += channels) {
            data[i] = 255 - data[i];
            data[i + 1] = 255 - data[i + 1];
            data[i + 2] = 255 - data[i + 2];
        }
        
        write_image_data("image_out.bmp", data, width, height);
     }

     