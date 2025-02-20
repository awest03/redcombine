#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

#include <stdio.h>

int main(const int argc, const char **argv)
{
    if (argc < 4)
    {
        printf("Insufficient Arguments, expected:\n %s rin gin bin output:\n",
               argv[0]);
        return EXIT_FAILURE;
    }

    const char *metallic = argv[1];
    const char *roughness = argv[2];
    const char *ao = argv[3];

    int met_width, met_height, met_channels;
    int rou_width, rou_height, rou_channels;
    int ao_width, ao_height, ao_channels;

    stbi_uc *metallicData =
        stbi_load(metallic, &met_width, &met_height, &met_channels, 0);
    stbi_uc *roughnessData =
        stbi_load(roughness, &rou_width, &rou_height, &rou_channels, 0);
    stbi_uc *aoData = stbi_load(ao, &ao_width, &ao_height, &ao_channels, 0);

    unsigned char *output = (unsigned char *)malloc(met_width * met_height * 4);

    // Note: Assumes all three textures are the same size and have at least 3
    // channels
    for (unsigned long int r = 0; r < (unsigned int)(met_width * met_height);
         r += 1)
    {
        output[r * 4] = metallicData[r * met_channels];
        output[r * 4 + 1] = roughnessData[r * rou_channels];
        output[r * 4 + 2] = aoData[r * ao_channels];
        output[r * 4 + 3] = 255;
    }

    stbi_write_png(argv[4], met_width, met_height, 4, (const void *)output,
                   met_width * 4);
}