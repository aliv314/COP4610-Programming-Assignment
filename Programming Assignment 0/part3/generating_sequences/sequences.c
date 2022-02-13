//
// Created by diego on 12/2/22.
//

#include "sequences.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// pseudo-randomly picks a rational number of the form
// a*max/RAND_MAX + min where a is an integer between 1 and RAND_MAX inclusive
// might not result in a uniform distribution due to rounding errors
#define u_rand(min, max) ((rand()/(double)RAND_MAX) * (max - min) + min)

// generates a random rational number from a normal distribution
// with mean miu and std dev sigma using the Box-Muller transform
#define norm_rand(miu, sigma) (sigma * (sqrt(-2 * log(u_rand(0,1))) * cos(2 * M_PI * u_rand(0,1))) + miu)

int main(void)
{
    generate_sequences ("scenario1.csv", 20, 1, 8, 5, 1);
    generate_sequences ("scenario2.csv", 200000, 1, 2000, 1024, 256);
    generate_sequences ("scenario3.csv", 2000000, 1, 8100, 4096, 1331.2);
}

void generate_sequences(char* fn, int num, double min, double max, double miu, double sigma)
{
    //create file and write header
    FILE* out_file = fopen(fn, "w");
    fprintf(out_file, "u, v, t, v/t, 4u - 5v + 2t\n");

    // generate sequences
    for (int i = 0; i < num; i++)
    {
        // this guarantees that the result is in the interval [min, max[
        // while maintaining a uniform distribution
        double random = u_rand(min, max);
        int u = (int) ((random != max) ? random : max - 1);

        double v = norm_rand(miu, sigma);
        double t;

        // makes sure t is in range [min, max[
        do
        {
            t = norm_rand(miu, sigma);
        }while(t < min || t >= max);

        fprintf (out_file, "%d, %f, %f, %f, %f\n", u, v, t, v/t, 4*u - 5*v + 2*t);
    }

    fclose (out_file);
}