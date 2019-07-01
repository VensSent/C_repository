/*
 ============================================================================
 Name        : Vector calculator with list
 Author      : VensSent
 Version     :
 Copyright   : Bulavin Ivan
 Description :
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
    char command; //Задаем команду сложения, вычитания, умножения и т.д. Задаем то, какая операция будет выполнятся (с векторами(v) или с числами(s))
    char operation;
    int size; //Размер векторов или количество чисел
    float *first; //Задаем первое или второе число/вектор
    float *second;
    struct linked_list *next; //Указатель на следующий элемент
}elem;

typedef struct result_list{
    float *result; //Указатель для хранения результата
    struct result_list *next_result;
}result;

float *vector_operation(char command, int size, float *vector1, float *vector2){
    float *vector; //Объявляем вектор.
    if (command != '*'){
        vector = malloc(size * sizeof(float)); //Выделяем память для длинны вектора
        switch(command) {
            case '+':
                for (int i = 0; i < size; i++) {vector[i] = vector1[i] + vector2[i];}
                return vector;
            case '-':
                for (int i = 0; i < size; i++) {vector[i] = vector1[i] - vector2[i];}
                return vector;
        }
    }
    else{
        vector = malloc(1 * sizeof(float));
        vector[0] = 0;
        for (int i = 0; i < size; i++) {vector[0] = vector[0] + (vector1[i] * vector2[i]);}
        return vector;
    }
}

float *numb_operation(char command, float *first, float *second){
    float y;
    float *support;
    support = malloc(1 * sizeof(float));
    switch (command){
        case '+':
            support[0] = first[0] + second[0];
            return support;
        case '-':
            support[0] = first[0] - second[0];
            return support;
        case '*':
            support[0] = first[0] * second[0];
            return support;
        case '^':
            support[0] = first[0];
            if (second[0] != 0){
                for (int i = 1; i < second[0]; i++){
                    first[0] = first[0] + support[0];
                }
                return first;
            } else{
                first[0] = 1;
                return first;
            }

        case '/':
            support[0] = first[0] / second[0];
            return support;
        case '!':
            y = 1;
            for(int i = 1; i<=first[0]; i++){y = y * i;}
            support[0] = y;
            return support;
    }
}

//Функция для чтения числа по указателю и добавления в first или second
float *addNumb(FILE *input, int size){ //Добавление числа
    float *numb;
    numb = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++){fscanf(input,"%f", &numb[i]);}
    return numb;
}

void addelement(elem *current, FILE *input){
    elem *tmp = malloc(1 * sizeof(elem));
    //Добавление в структуру.
    fscanf(input, " %c %c", &tmp->command, &tmp->operation);
    if (tmp->operation == 'v') { fscanf(input, " %i", &tmp->size);}
    else { tmp->size = 1; }
    if (tmp->command != '!') {
        tmp->first = addNumb(input, tmp->size);
        tmp->second = addNumb(input, tmp->size);
    } else {
        tmp->first = addNumb(input, tmp->size);
        tmp->second = NULL;
    }
    tmp->next = NULL;
    current->next = tmp;
}

void addelement_res(result *current_res, elem *current){
    result *tmp_res = malloc(1 * sizeof(result));
    if (current->operation == 'v'){tmp_res->result = vector_operation(current->command, current->size, current->first, current->second );}
    else{tmp_res->result = numb_operation(current->command, current->first, current->second);}
    tmp_res->next_result = NULL;
    current_res->next_result = tmp_res;
}


int main() {
    FILE *input, *output;
    elem *head, *current;
    result *head_res, *current_res;
    input = fopen("input.txt", "r"); //Открываем файл, в который нужно записать данные
    if (!feof(input)) {
        head = malloc(1 * sizeof(elem)); //Выделяем память для головы списка(первого элемента)
        fscanf(input, " %c %c", &head->command, &head->operation);
        //записываем отдельно данные для 1 элемента
        if (head->operation == 'v') { fscanf(input, " %i", &head->size); }
        else { head->size = 1; }
        if (head->command != '!') {
            head->first = addNumb(input, head->size);
            head->second = addNumb(input, head->size);
        } else {
            head->first = addNumb(input, head->size);
            head->second = NULL;
        }
        //Копируем указатели и добавляем элементы до тех пор, пока файл не закочнится
        current = head;
        while (!feof(input)) {
            addelement(current, input);
            current = current->next;
        }
        // Создание головы списка с ответами. Выделение памяти и помещение в функцию последующего добавления
        head_res = malloc(sizeof(result));
        current = head;

        if (current->operation == 'v') {
            head_res->result = vector_operation(current->command, current->size, current->first, current->second);
        }
        else { head_res->result = numb_operation(current->command, current->first, current->second); }
        head_res->next_result = NULL;
        current = current->next;
        current_res = head_res;
        while (current != NULL) {
            addelement_res(current_res, current);
            current = current->next;
            current_res = current_res->next_result;
        }
        //Копируем указатели для добавления в файл
        current = head;
        current_res = head_res;
        fclose(input);
        output = fopen("output.txt", "w");
        while (current != NULL) {
            if (current->operation == 'v') {
                fprintf(output, "(");
                //вывод данных из first,second and result
                for (int i = 0; i < current->size; i++) {
                    fprintf(output, " %.2f ", current->first[i]);
                }
                fprintf(output, ") %c (", current->command);
                for (int i = 0; i < current->size; i++) {
                    fprintf(output, " %.2f ", current->second[i]);
                }
                fprintf(output, ") = ");
                if (current->command != '*') {
                    fprintf(output, "(");
                    for (int i = 0; i < current->size; i++) { fprintf(output, " %.2f ", current_res->result[i]); }
                    fprintf(output, ")\n");
                } else {
                    fprintf(output, " %.2f\n", current_res->result[0]);
                }
            } else {
                fprintf(output, "Ansver: %.2f\n", current_res->result[0]);
           }
            //Передвигаем указатели
            current = current->next;
            current_res = current_res->next_result;
        }
    }
    return 0;
}
