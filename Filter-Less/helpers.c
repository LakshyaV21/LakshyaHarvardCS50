#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double avrg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avrg = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            avrg = round(avrg);

            image[i][j].rgbtBlue = avrg;
            image[i][j].rgbtGreen = avrg;
            image[i][j].rgbtRed = avrg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // declare variables
    float sepiaRed, sepiaGreen, sepiaBlue;
    int originalRed, originalGreen, originalBlue;

    // cycle rows
    for (int i = 0; i < height; i++)
    {
        // cycle columns
        for (int j = 0; j < width; j++)
        {
            // assign values to variables
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // used original formula to avoid mistakes or typos.
            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // round numbers
            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);

            // check if any value exeed 255, and if so set to 255 else leave as it is
            sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
            sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

            // change oringinal pixels to sepia
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // temp variable
    RGBTRIPLE tmp[1][1];
    int last = width;
    int first = 0;

    for (int i = 0; i < height; i++)
    {
        last = width - 1;
        first = 0;

        // swapping the pixels
        for (int j = 0; j < width / 2; j++)
        {
            tmp[0][0] = image[i][first];
            image[i][first] = image[i][last];
            image[i][last] = tmp[0][0];

            last--;
            first++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_blur[height][width];
    double avgRed, avgGreen, avgBlue;
    float counter;

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            counter = 0;
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;

            for (int s = -1; s < 2; s++)
            {
                for (int n = -1; n < 2; n++)
                {

                    int d = i + s;
                    int k = j + n;

                    if (d < height && k < width && d >= 0 && k >= 0)
                    {
                        avgRed = avgRed + image[d][k].rgbtRed;
                        avgGreen = avgGreen + image[d][k].rgbtGreen;
                        avgBlue = avgBlue + image[d][k].rgbtBlue;

                        counter++;
                    }
                }
            }

            avgRed = round(avgRed / counter);
            avgGreen = round(avgGreen / counter);
            avgBlue = round(avgBlue / counter);

            image_blur[i][j].rgbtRed = avgRed;
            image_blur[i][j].rgbtGreen = avgGreen;
            image_blur[i][j].rgbtBlue = avgBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_blur[i][j];
        }
    }
    return;
}
