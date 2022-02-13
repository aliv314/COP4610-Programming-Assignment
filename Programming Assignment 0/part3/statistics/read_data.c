//
// Created by diego on 13/2/22.
//

#include "read_data.h"
#include <stdio.h>

/*
 * Reads the sequences from csv files (a bit hacky, but it does the job)
 */
void read_data(char* filename, double data[][5], int rows)
{
    // open file
    FILE* file = fopen (filename, "r");
    if (file == NULL)
    {
        printf ("Couldn't find file %s\n", filename);
        return;
    }

    // skip header
    fscanf(file, "%*[^\n]\n");

    for (int i = 0; i < rows; i++)
    {
        fscanf(file, "%lf, %lf, %lf, %lf, %lf\n", &data[i][0], &data[i][1], &data[i][2], &data[i][3], &data[i][4]);
    }
}
