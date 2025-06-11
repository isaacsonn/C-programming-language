#include <stdio.h>
#define max_score 100

int main()
{
    int score;
    printf("Enter your score: ");
    scanf("%d", &score);

    if(score > max_score || score < 0){
        printf("Error: Invalid score");
    }
    else if(score >= 90){
        printf("Your score is A\n");
    }else if(score >= 80){
        printf("Your score is B\n");
    }else if(score >= 70){
        printf("Your score is C\n");
    }else if(score >= 60){
        printf("Your score is D\n");
    }
    else{
        printf("your score is F\n");
    }
    return 0;
}