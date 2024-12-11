#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

typedef struct {
    unsigned char *data;
    int width, height, channels;
} Image;

Image loadImage(const char *filename) {
    Image image = {0};
    image.data = stbi_load(filename, &image.width, &image.height, &image.channels, 0);
    return image;
}

void saveImage(const char *filename, const Image *image) {
    char *extension = strrchr(filename, '.');
    if (extension != NULL) {
        extension++; // Skip the dot
        if (strcmp(extension, "jpg") == 0 || strcmp(extension, "jpeg") == 0 ||
            strcmp(extension, "png") == 0 || strcmp(extension, "bmp") == 0) {
            stbi_write_png(filename, image->width, image->height, image->channels, image->data, image->width * image->channels);
        } else {
            printf("Unsupported format\n");
        }
    } else {
        printf("Invalid filename\n");
    }
}

void invertImage(Image *image) {
    int size = image->width * image->height * image->channels;
    for (int i = 0; i < size; ++i) {
        image->data[i] = 255 - image->data[i];
    }
}

void rotateImage(Image *image) {
    // Implementation for rotating image
}

void addFrameToImage(Image *image) {
    // Implementation for adding frame to image
}

void blurImage(Image *image) {
    // Implementation for blurring image
}

int main() {
    Image image = {0};
    char filename[256];
    int choice;

    do {
        printf("Image Processing Menu:\n");
        printf("1. Load Image\n");
        printf("2. Invert Image\n");
        printf("3. Rotate Image\n");
        printf("4. Add Frame to Image\n");
        printf("5. Blur Image\n");
        printf("6. Save Image\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter image file name: ");
                scanf("%s", filename);
                if (image.data != NULL) {
                    stbi_image_free(image.data);
                }
                image = loadImage(filename);
                if (image.data != NULL) {
                    printf("Image loaded successfully.\n");
                } else {
                    printf("Failed to load image.\n");
                }
                break;
            case 2:
                invertImage(&image);
                printf("Image inverted.\n");
                break;
            case 3:
                rotateImage(&image);
                break;
            case 4:
                addFrameToImage(&image);
                break;
            case 5:
                blurImage(&image);
                break;
            case 6:
                printf("Enter output image file name: ");
                scanf("%s", filename);
                saveImage(filename, &image);
                printf("Image saved successfully.\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    if (image.data != NULL) {
        stbi_image_free(image.data);
    }

    return 0;
}
