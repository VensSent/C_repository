#include<stdio.h>
#include <math.h>

int main (void){
    float a, b, c=1, ansver; //Мы объявили переменные, с которыми будем взаимодействовать
    int k;
    int z=1;
    while (z==1){
        printf("enter two numbers a and b\n");
        scanf("%f%f", &a, &b);
        printf("(Addition=1)_\n");
        printf("(Subtraction =2)\n");            //Здесь у нас сканируются введенные переменные, введенные в цикле, затем они выводятся в консоли, а потом выводятся варианты команд с их последующим выбором
        printf("(Multiplication =3)\n");
        printf("(Division =4)\n");
        printf("(power of number(a^b)=5)\n");
        printf("(factorial(from a)=6)\n");
        printf("_ENTER YOUR COMAND_\n");
        scanf("%d", &k);
        switch (k) {
            if (k==1){  //Путем ввода значения нашей команды, выбирается команда, которая нам нужна
                 printf("ansver %f\n", a + b);  // k=1-Сложение, k=2-Вычитание, k=3-Умножение, k=4-Деление, k=5-Возведение в степень, k=6-Факториал числе от a
                 break;
                     }
            if (k==2){
                 printf("ansver %f\n", a - b);
                 break;
                     }
            if (k==3){
                 printf("ansver %f\n", a * b);
                 break;
                     }
            if (k==4){
                 printf("ansver %f\n", a / b);
                 break;
                     }
            if (k==5){
                 ansver =  pow(a, b);
                 printf("ansver %f\n", ansver);
                 break;
                     }
            if (k==6){
                 while (a != 0) {
                            c = c * a;
                            a = a - 1;
                            if (a==0){
                                printf("ansver %f\n", c);
                                     }
                                }
                      }
                  break;
                   }

            printf("restart: enter 1, exit: enter 2\n");
            scanf("%d", &z);
                 }
                }
