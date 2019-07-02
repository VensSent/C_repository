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
#include <stdlib.h>
#include <iso646.h>
#define true 1
#define false 0

//Структура для срочек, из которой делаем список
typedef struct list_command {
    char command[50];
    struct list_command *next;
}com;

typedef struct stack {
    float element;
    struct stack *last;
}stack;


float numb_operation(char command, float first, float second){
    float y;
    float support; //Возвращаем данный указатель с результатами
    switch (command){
        case '+':
            support = first + second;
            return support;
        case '-':
            support = first - second;
            return support;
        case '*':
            support = first * second;
            return support;
        case '^':
            support = first;
            if (second != 0){
                for (int i = 1; i < second; i++){
                    first = first * support;
                }
                return first;
            } else{
                first = 1;
                return first;
            }

        case '/':
            support = first / second;
            return support;
        case '!':
            y = 1;
            for(int i = 1; i<=first; i++){y = y * i;}
            support = y;
            return support;
    }
}

void addelement_data(com *current, FILE *input){
    com *tmp_data = malloc(1 * sizeof(com));
    fgets(tmp_data->command, sizeof(tmp_data->command), input);
    tmp_data->next = NULL;
    current->next = tmp_data;
}

int condition_check(char oper){
    char operation[5] = {'+', '*', '^', '/', '!'};
    for (int i = 0; i != 5; i++){
        if (oper == operation[i]){
            return true;
        }
    }
    return false;
}


stack *push_stack(float element, stack *head_stack){
    stack *tmp_stack = malloc(1* sizeof(stack));
    tmp_stack->element = element;
    if (head_stack == NULL){
        tmp_stack->last = NULL;
        head_stack = tmp_stack;
        return head_stack;
    } else{
        tmp_stack->last = head_stack;
        head_stack = tmp_stack;
        return head_stack;
    }
}

float pop_elemet(stack *head_stack){
    if(head_stack != NULL) {
        float data;
        data = head_stack->element;
        return data;
    }else{puts("None");}
}


int main() {
    FILE *input, *output;
    com *head, *current;
    stack *head_stack = NULL;
    char *cut;
    float element, first, second;
    input = fopen("input.txt", "r");
    if (!feof(input)){
        head_stack = NULL;
        //Добавление строчек в список
        head = malloc(1 * sizeof(com));
        fgets(head->command, sizeof(head->command), input);
        head->next = NULL;
        current = head;
        while (!feof(input)) {
            addelement_data(current, input);
            current = current->next;
        }
        //head - это указатель на начало списка. ыполняется обработка символов, и идет запись данных в стэк
        current = head;
        while (current != NULL){
            //Размер операции. Если 1-операция
            for(int i = 0; i < 50; i++) {
                if (current->command[i] == '.') {
                    break;
                } else {
                    if (condition_check(current->command[i]) == true) {
                        if (current->command[i] != '!') {
                            second = pop_elemet(head_stack);
                            head_stack = head_stack->last;
                            first = pop_elemet(head_stack);
                            head_stack = head_stack->last;
                        } else {
                            first = pop_elemet(head_stack);
                            head_stack = head_stack->last;
                        }
                        element = numb_operation(current->command[i], first, second);
                        head_stack = push_stack(element, head_stack);
                        i++;
                    } else {
                        if (current->command[i] == '-' and current->command[i + 1] == ' ') {
                            second = pop_elemet(head_stack);
                            head_stack = head_stack->last;
                            first = pop_elemet(head_stack);
                            head_stack = head_stack->last;
                            element = numb_operation(current->command[i], first, second);
                            head_stack = push_stack(element, head_stack);
                            i++;
                        } else {
                            //находим длинну среза
                            int k = i;
                            //Получаем длинну среза
                            while (current->command[k] != ' ') { k++; }
                            int len_arr = k - i;
                            //Начинаем заполнениеhj
                            k = i;
                            cut = malloc(len_arr * sizeof(char));
                            for (int p = 0; p < len_arr; p++) {
                                cut[p] = current->command[k];
                                k++;
                            }
                            i = k;
                            element = atof(cut);
                            head_stack = push_stack(element, head_stack);
                        }
                    }
                }
            }
            current = current->next;
        }
        output = fopen("output.txt", "w");
        while (head_stack != NULL){
            element = pop_elemet(head_stack);
            fprintf(output, "Result: %.2f\n", element);
            head_stack = head_stack->last;
        }

        return true;
    }
    return false;
}
