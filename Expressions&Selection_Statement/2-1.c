#include <stdio.h>

int main()
{
    int a, b, c; //Declaration
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a >= b && a >= c){
        printf("Maximum integer is: %d\n", a); //comparing the a with others
    }else if (b >= a && b >= c){
        printf("Maximum integer is: %d\n", b); //comparing the b with others 
    }
    else{
        printf("Maximum Integer is: %d\n", c); //here is else case for c
    }

    return 0;
}
// This way of solving is more complex and not user friendly i think
// I will do my best to write the more advanced version of it 

// #include <stdio.h>

// int main()
// {
//     int a, b, c;

//     printf("Enter three integers: ");
//     scanf("%d %d %d", &a, &b, &c);

//     int largest = a;
//     if(b > largest){
//         largest = b;
//     }
//     if(c > largest){
//         largest = c;
//     }

//     printf("The largest number is: %d\n", largest);
//     return 0;
// }

//Here I just pointed a as largest number and compared twice with b and c 
// Tip: If you want even larger integers you can change and add %lld