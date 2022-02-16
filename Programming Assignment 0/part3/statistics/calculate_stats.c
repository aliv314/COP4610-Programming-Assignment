//
// Created by diego on 15/2/22.
//

#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[])
{
    // arrays to store statistics
    double means[5] = {0, 0, 0, 0, 0};
    double devs[5] = {0, 0, 0, 0, 0};

    // quantities used for computing statistics
    double squares[5] = {0, 0, 0, 0, 0};
    double sums[5] = {0, 0, 0, 0, 0};
    int n = 0;

    // open file
    FILE* file = fopen (argv[1], "r");
    if (file == NULL)
    {
        printf ("Couldn't find file %s\n", argv[1]);
        return 1;
    }

    // skip header
    fscanf(file, "%*[^\n]\n");

    // compute stuff while iterating over file for efficiency
    double data[5];
    while (fscanf(file, "%lf, %lf, %lf, %lf, %lf\n", &data[0], &data[1], &data[2], &data[3], &data[4]) != EOF)
    {
        // add data points and their squares to total
        for (int i = 0; i < 5; i++)
        {
            sums[i] += data[i];
            squares[i] += data[i] * data[i];
        }

        // increment n
        n++;
    }

    // compute means
    for (int i = 0; i < 5; i++)
    {
        means[i] += sums[i] / n;
    }

    // compute std deviations
    for (int i = 0; i < 5; i++)
    {
        devs[i] += sqrt ((squares[i] - 2 * means[i] * sums[i] + n * means[i] * means[i]) / (n - 1));
    }

    // print all the stuff
    printf ("{u}: mean=%f, std_dev=%f\n", means[0], devs[0]);
    printf ("{v}: mean=%f, std_dev=%f\n", means[1], devs[1]);
    printf ("{t}: mean=%f, std_dev=%f\n", means[2], devs[2]);
    printf ("{v/t}: mean=%f, std_dev=%f\n", means[3], devs[3]);
    printf ("{4u - 5v + 2t}: mean=%f, std_dev=%f\n", means[4], devs[4]);
}