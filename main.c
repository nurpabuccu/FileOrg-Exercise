//
//  main.c
//  Fileorg
//
//  Created by Nur Pabuççu on 6.04.2019.
//  Copyright © 2019 Nur Pabuççu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    int lineNo, count = 0;
    FILE *fp1, *fp2;
    char file[MAX], str[MAX], temp[] = "temp.txt";
    
    /* get the input file name from the user */
    printf("Enter your input file name:");
    scanf("%s", file);
    
    /* open the input file in read mode */
    fp1 = fopen(file, "r");
    
    /* error handling */
    if (!fp1) {
        printf("Unable to open the input file!!\n");
        return 0;
    }
    
    /* open the temporary file in write mode */
    fp2 = fopen(temp, "w");
    
    /* error handling */
    if (!fp2) {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fp1);
        return 0;
    }
    
    /* get the line number to delete the specific line */
    printf("Enter the line number you want to delete:");
    scanf("%d", &lineNo);
    
    /*
     * copy all contents to the temporary file other
     * other than line belongs to input line number.
     */
    while (!feof(fp1)) {
        strcpy(str, "\0");
        fgets(str, MAX, fp1);
        if (!feof(fp1)) {
            count++;
            /* skip the line at given line number */
            if (count != lineNo) {
                fprintf(fp2, "%s", str);
            }
        }
    }
    
    /* close the opened files */
    fclose(fp1);
    fclose(fp2);
    
    /* remove the input file */
    remove(file);
    
    /* rename the temporary file */
    rename(temp, file);
    return 0;
    
}
