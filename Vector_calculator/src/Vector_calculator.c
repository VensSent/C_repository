/*
 ============================================================================
 Name        : Vector calculator with text file
 Author      : VensSent
 Version     :
 Copyright   : Bulavin Ivan
 Description :
 ============================================================================
 */


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
char exit;
    do {
        puts("\n The perform the operation, click Enter.");
        scanf("%c",&exit);
        char operation_type, command_type;
        FILE *in_file;
        FILE *out_file;

        in_file = fopen("input.txt","r"); //Функция для открытия файла input.txt
        out_file = fopen("output.txt", "w"); //Функция для открытия файла output.txt
        fscanf(in_file, "%c", &command_type);
        fscanf(in_file, " %c", &operation_type);

        switch (operation_type) {

            case 's': {                //Кейс для работы над операциями с символами
                int num1, num2, i;
                float result;

                fscanf(in_file, " %d", &num1);
                fscanf(in_file, " %d", &num2);

                switch (command_type) {
                    case '+':
                        result = num1 + num2;
                        fprintf(out_file, "%d + %d = %.0f", num1, num2, result);
                        break;

                    case '-':
                        result = num1 - num2;
                        fprintf(out_file, "%d - %d = %.0f", num1, num2, result);
                        break;

                    case '*':
                        result = num1 * num2;
                        fprintf(out_file, "%d * %d = %.0f", num1, num2, result);
                        break;

                    case '/':
                        result = num1 / num2;
                        fprintf(out_file, "%d / %d = %.0f", num1, num2, result);
                        break;

                    case '^':
                        result = 1;

                        for (i = 0; i < num2; i++) {
                            result = result * num1;
                        }
                        fprintf(out_file, "%d ^ %d = %.0f \n", num1, num2,
                                result);
                        break;

                    case '!':
                        if (num1 == 0)
                        {
                            result = 1;
                        } else // если number != 0
                        {
                            result = 1;
                            for (i = 1; i <= num1; i++) {
                                result = result * i;
                            }
                        }
                        fprintf(out_file, "%d! = %.0f \n", num1, result);
                        break;

                    default:
                        puts("error: invalid operation symbol, fix file and try again");
                        break;
                }
                break;
            }
//векторы







            case 'v': {             //Кейс для работы над операциями с векторами

                float *vector_1;
                float *vector_2;
                float *vector_result;
                int size = 0;

                                     // выделяем память под векторы
                vector_1 = calloc(size,sizeof(int));
                vector_2 = calloc(size,sizeof(int));
                vector_result = calloc(size,sizeof(float));
                fscanf(in_file, " %d", &size);


                switch (command_type) {
                    case '+': {
                                     //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," + ");


                                      //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                                      // результат
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] + vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file,")");
                        break;
                    }
                    case '-':
                    {                 //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," - ");


                                       //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                                      // результат
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] - vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file,")");
                        break;}




                    case '*':
                    {                 //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," * ");


                                      //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                                       // результат
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] * vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file,")");
                        break;}

                    default:
                        puts("error: invalid operation symbol, fix file and try again.");
                        break;
                }

                free(vector_1);        //освобождаем память
                free(vector_2);
                free(vector_result);
                break;
            }

            default:
                puts("error: invalid data type.");
                break;
        }
        fclose(in_file);               // закрываем файлы
        fclose(out_file);

        puts("The operation is comleted. Check the file output.txt in the program folder.\n Press 'q' for exit.");

    }while(exit != 'q');
}
