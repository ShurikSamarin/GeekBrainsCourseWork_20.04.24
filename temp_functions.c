#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_functions.h"

#define MAX_LINE_LENGTH 1000000

void printHelp() {
    printf("Usage: temperature_stats -f <filename.csv> [-m <month>]\n");
}

void processFile(const char *filename, int month) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    float sum = 0;
    float min = 0;
    float max = 0;
    int i = 1;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line_number++;
        DataPoint data;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &data.year, &data.month, &data.day, &data.hour, &data.minute, &data.temperature) == 6) {
            if (month == -1 || data.month == month) {
                printf("Date: %d-%02d-%02d %02d:%02d, Temperature: %d\n", data.year, data.month, data.day, data.hour, data.minute, data.temperature);
                sum = sum + data.temperature;
                if (data.temperature < min) {
					min = data.temperature;
				}
				if (data.temperature > max) {
					max = data.temperature;
				}
                i++;
            }
        } else {
            printf("Error in line %d: Invalid format\n", line_number);
            i = i-1;
        }
        
    }
	printf("Average temperature: %f\n", sum/i);
	printf("Min temperature: %f\n", min);
	printf("Max temperature: %f\n", max);
    fclose(file);
}
