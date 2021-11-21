#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// счётчик
int count;

typedef struct node {
    int index;
    char *value;

    struct node *next;
}Base;


Base *database_create() {

    Base *main = (Base *)malloc(sizeof(Base));

    main -> index = 0;
    main -> value = "Hello";
    main -> next = NULL;

    return main;
}

Base *create_node(int set_index, char *set_value){
    Base *node = (Base *)malloc(sizeof(Base));
    node -> index = set_index;
    node -> value = set_value;
    node -> next = NULL;

    return node;
}

void database_insert(Base **list, int set_index, char *set_value) {

    if (set_index < 0) {   // если index < 0, то добавляю в начало
        Base *new_element = create_node(set_index, set_value);
        new_element -> next = *list;
        *list = new_element;
    }
    else if(set_index >= 0) { // если index >= 0, то добавляем в конец
        Base *new_element = create_node(++set_index, set_value);
        Base *tmp = *list;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_element;
    }
    count++;
}

// поиск по индексу
void database_read(Base **list, int index) {
    Base *tmp = (Base*)malloc(sizeof(Base));
    tmp->next = *list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (tmp->index == index) {
            printf("Значение %s\n", tmp->value);
        }
    }
}

// поиск по значению
int database_search(Base **list, char *value) {
    Base *tmp = (Base*)malloc(sizeof(Base));
    tmp->next = *list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (strcmp(tmp->value, value) == 0) {
            return tmp->index;
        }
    }
}


int get_count(){
    printf("Длинна: %d\n", count);
}

// удаление по индексу
void database_delete(Base **list, int index) {
    Base *tmp = (Base*)malloc(sizeof(Base));
    tmp->next = *list;
    while(tmp->next != NULL) {
        tmp = tmp->next;
        if (tmp->index == index){
            free(tmp);
        }
    }
}

int main() {

    Base *list = database_create();
    database_insert(&list, 0, "Big");
    database_insert(&list, 1, "Flame");
    database_insert(&list, -1, "Great");
    database_read(&list, 1);
    int index = database_search(&list, "Big");
    printf("Индекс: %d\n", index);
    return 0;
}
