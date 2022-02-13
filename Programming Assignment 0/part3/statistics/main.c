//
// Created by diego on 13/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "read_data.h"
#include "statistics.h"

int main(int argc, char* argv[])
{
    char* filename = argv[1];
    int length = atoi(argv[2]);

    double data[length][5];
    read_data(filename, data, length);

    double means[5];
    double std_devs[5];

    mean(data, length, means);
    std_dev(data, length, means, std_devs);

    printf ("{u}: mean=%f, std_dev=%f\n", means[0], std_devs[0]);
    printf ("{v}: mean=%f, std_dev=%f\n", means[1], std_devs[1]);
    printf ("{t}: mean=%f, std_dev=%f\n", means[2], std_devs[2]);
    printf ("{v/t}: mean=%f, std_dev=%f\n", means[3], std_devs[3]);
    printf ("{4u - 5v + 2t}: mean=%f, std_dev=%f\n", means[4], std_devs[4]);
}