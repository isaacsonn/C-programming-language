// simple calculator

#include <stdio.h>

int main()
{
    int i, n;
    char op;
    printf("Enter two numbers and a character (+,-,* or /): ");
    scanf("%d  %c %d", &i, &op, &n);

    if(op == '+'){
         printf("Result: %d\n", i + n);
    }else if (op == '-'){
        printf("Result: %d\n", i - n);
    }else if (op == '*'){
        printf("Result: %d\n", i * n);
    } else if (op == '/') {
    if (n != 0) {
        printf("Result: %d\n", i / n);
    } else {
        printf("Error: division by zero\n");
    }
} else {
    printf("Error: Invalid operator\n");
}
    return 0;
}

// The program read two integers and an operator from the user 
// Here i used if / else if statement to kno which operation to perform