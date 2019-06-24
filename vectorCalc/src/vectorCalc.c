#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Choose your operation: 1) Numbers 2) Vectors\n");
    int change_op;
    scanf("%d", &change_op);
    int op = 1;
    while (op == 1) {
        switch (change_op) {
        case 1: {

            float a, b, c = 1, ansver; //Мы объявили переменные, с которыми будем взаимодействовать
            int k;
            int z = 1;
            while (z == 1) {
                printf("enter two numbers a and b\n");
                scanf("%f%f", &a, &b);
                printf("(Addition=1)_\n");
                printf("(Subtraction =2)\n"); //Здесь у нас сканируются введенные переменные, введенные в цикле, затем они выводятся в консоли, а потом выводятся варианты команд с их последующим выбором
                printf("(Multiplication =3)\n");
                printf("(Division =4)\n");
                printf("(power of number(a^b)=5)\n");
                printf("(factorial(from a)=6)\n");
                printf("_ENTER YOUR COMAND_\n");
                scanf("%d", &k);
                switch (k) {
                case 1: //Путем ввода значения нашей команды, выбирается команда, которая нам нужна
                    printf(" ansver %f\n", a + b); // k=1-Сложение, k=2-Вычитание, k=3-Умножение, k=4-Деление, k=5-Возведение в степень, k=6-Факториал числе от a
                    break;
                case 2:
                    printf(" ansver %f\n", a - b);
                    break;
                case 3:
                    printf(" ansver %f\n", a * b);
                    break;
                case 4:
                    printf(" ansver %f\n", a / b);
                    break;
                case 5:
                    ansver = pow(a, b);
                    printf(" ansver %f\n", ansver);
                    break;
                case 6:
                    while (a != 0) {
                        c = c * a;
                        a = a - 1;
                        if (a == 0) {
                            printf(" ansver %f\n", c);
                        }
                    }
                    break;
                }
                printf(" Restart: enter 1, exit: enter 2\n");
                scanf("%d", &z);
            }

        }
        case 2: {

            float *vector1, *vector2;
            int size, f;

            printf("Enter the dimension of the vector: "); //Здесь мы задаем размерность векторов, с которыми будем выполнять операции
            scanf("%d", &size);

            vector1 = calloc(size, sizeof(float)); //Функция calloc выделяет память для вектора, где size - это количество элементов, а sizeof() - размер одного элемента
            for (int i = 0; i < size; i++) {
                printf("Enter cords first vector (a): ");
                scanf("%f", &vector1[i]);
            }

            vector2 = calloc(size, sizeof(float));

            for (int i = 0; i < size; i++) {
                printf("Enter cords second vector (b): ");
                scanf("%f", &vector2[i]);
            }

            int k;
            puts(
                    "\n Select operation:    1) \"+\" - Addition\n    2) \"-\" - Substraction\n    3) \"*\" - Scalar multipilication *"); //Выбор операции для векторов
            printf("select command: ");
            scanf("%d", &k);

            f = 0;
            while (f == 0) {
                if (k > 0 && k < 4) {
                    f = 1;
                } else {
                    printf("Wrong command! Select command from list: ");
                    scanf("%d", &k);
                }
            }

            float result = 0;
            switch (k) {
            case 1:
                printf("\n Result: (");
                for (int i = 0; i < size; i++) {
                    printf("%.2f", vector1[i] + vector2[i]);
                    if (i != size - 1)
                        printf(" ");
                }
                printf(")\n\n");
                break;
            case 2:
                printf("\n Result: (");
                for (int i = 0; i < size; i++) {
                    printf("%.2f", vector1[i] - vector2[i]);
                    if (i != size - 1)
                        printf(" ");
                }
                printf(")\n\n");
                break;
            case 3:
                for (int i = 0; i < size; i++) {
                    result += vector1[i] * vector2[i];
                }
                printf("\n Result: %.2f\n\n", result);
                break;
            }
            free(vector1);
            free(vector2);

        }
            break;
        }
        printf("Restart: Enter 1, Exit: Enter 2\n");
        scanf("%d", &op);
    }

}
