#include <stdio.h>

int convertToShade(int grayscaleValue) {
    // Ensure grayscale value is within range (0-255)
    if (grayscaleValue < 0)
        grayscaleValue = 0;
    else if (grayscaleValue > 255)
        grayscaleValue = 255;

    // Calculate the corresponding shade of gray
    int shade = 255 - grayscaleValue;

    return shade;
}

int main() {
    int grayscaleValue;
    printf("Enter grayscale value (0-255): ");
    scanf("%d", &grayscaleValue);

    // Convert grayscale value to shade
    int shade = convertToShade(grayscaleValue);
    printf("Shade value: %d\n", shade);

    return 0;
}
