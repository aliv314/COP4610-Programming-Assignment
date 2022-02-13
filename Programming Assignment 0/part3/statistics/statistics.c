//
// Created by diego on 12/2/22.
//

#include "statistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mean(double sequences[][5], int seq_size, double seq_means[5])
{
    // set array to 0
    for (int i = 0; i < 5; i++)
    {
        seq_means[i] = 0;
    }

    // add all values
    for (int i = 0; i < seq_size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            seq_means[j] += sequences[i][j];
        }
    }

    // divide values by number of data points
    for (int i = 0; i < 5; i++)
    {
        seq_means[i] /= seq_size;
    }
}

void std_dev(double sequences[][5], int seq_size, double seq_means[5], double seq_devs[5])
{
    // set array to 0
    for (int i = 0; i < 5; i++)
    {
        seq_devs[i] = 0;
    }

    // add up all square differences
    for (int i = 0; i < seq_size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            seq_devs[j] += pow(sequences[i][j] - seq_means[j], 2);
        }
    }

    // divide values by size - 1 and take square root
    for (int i = 0; i < 5; i++)
    {
        seq_devs[i] = sqrt(seq_means[i] / (seq_size - 1));
    }
}