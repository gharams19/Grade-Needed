#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


bool GradeCheck(char g) {
    if (g == 'A' || g == 'a' || g == 'B' || g == 'b' || g == 'C' || g == 'c' || g == 'D' || g == 'd' || g == 'F' ||
        g == 'f') {
        return true;
    } else {
        return false;
    }
}

bool IfNeg(double a) {
    if (a >= 0) {
        return false;
    } else {
        return true;
    }

}


double GradePercent(char grade) {
    double rqGrade;
    if (grade == 'A' || grade == 'a') {
        rqGrade = 90;
    } else if (grade == 'B' || grade == 'b') {
        rqGrade = 80;
    } else if (grade == 'C' || grade == 'c') {
        rqGrade = 70;
    } else if (grade == 'D' || grade == 'd') {
        rqGrade = 60;
    } else {
        rqGrade = 0;
    }
    return rqGrade;
}

double GradeNeeded(int currPrcnt, double rqGrade, double finWeigh) {
    double finalNeeded;
    finalNeeded = ((100 * (rqGrade) - (100 - finWeigh) * (currPrcnt)) / finWeigh);
    return finalNeeded;
}


int main() {
    char lastChar;
    char grade;
    int currPrcnt;
    double rqGrade, finWeigh;
    int numArgs;
    printf("Enter the grade you want in the class: ");
    numArgs = scanf("%c", &grade);
    scanf("%c" , &lastChar);



    if ((numArgs != 1 || lastChar != '\n')) {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    if (GradeCheck(grade) == false) {
        printf("Unknown Grade Received: %c. Ending program.", grade);
        exit(0);

    }



    printf("Enter your current percent in the class:");
    numArgs = scanf("%d", &currPrcnt);
    scanf("%c", &lastChar);


    if (((numArgs != 1) || (lastChar != '\n')) || isalpha(lastChar)) {
        printf(" Invalid formatting. Ending program.\n");
        exit(0);
}


    if (IfNeg(currPrcnt)) {
        printf(" The number you last entered should have been positive. Ending program.\n");
        exit(0);
    }


    printf(" Enter the weight of the final: ");
    numArgs = scanf("%lf", &finWeigh);
    scanf("%c", &lastChar);


    if (((numArgs != 1) || (lastChar != '\n')) || (isalpha(lastChar))) {
        printf(" Invalid formatting. Ending program.\n");
        exit(0);
    }

    if (IfNeg(finWeigh)) {
        printf("The number you last entered should have been positive. Ending program.\n");
        exit(0);
    }


    rqGrade = GradePercent(grade);
    if (GradeNeeded(currPrcnt, rqGrade, finWeigh) <= 100 && GradeNeeded(currPrcnt, rqGrade, finWeigh) >= 0) {

        printf("\nYou need a grade of at least %.2f%% on the final to get a %c in the class.",
               GradeNeeded(currPrcnt, rqGrade, finWeigh), grade);
    } else if (GradeNeeded(currPrcnt, rqGrade, finWeigh) > 100 && GradeNeeded(currPrcnt, rqGrade, finWeigh) > 0) {
        printf("\nYou cannot get a %c in the class because you would need to score at least %.2f%% on the final.\n", grade,
               GradeNeeded(currPrcnt, rqGrade, finWeigh));
    } else if (GradeNeeded(currPrcnt, rqGrade, finWeigh) < 0) {
        printf("\nYou cannot score low enough on the final to get a %c in the class.\n", grade);
    }


    return 0;
}