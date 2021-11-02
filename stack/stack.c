#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    int index;
    char *text;
    struct s_list *next;
}t_list;


 // create node
t_list *create_node(char *set_text){
    t_list *node = (t_list *)malloc(sizeof(t_list));
    
    node -> text = set_text;
    
    node -> next = NULL;
    return node;
}

// add node in front of list
//void push_front(t_list **list, char *set_text) {
//    t_list *new_element = create_node(set_text);
    
///    new_element -> next = *list;
 ///   *list = new_element;
//}

// add node in back of list
void robot_put(t_list *list, char *set_text) {
    t_list *new_element = create_node(set_text);
    t_list *tmp = list;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_element;
}

// create stack
t_list stack_create(){
    t_list *list = create_node("dwdwd");
    return *list;
}


void robot_pop(t_list *list){
    //t_list *list2 = list;
    while (list != NULL){
        if (list -> next == NULL){
        
           // list = NULL;
           /// free(list);
            printf("%s\n", list -> text);
            
            list = list -> next;
            printf("%s\n", list -> text);
            free(list);


            return;
        }
        list = list -> next;
    }
    
}


void robot_len(t_list *list){
    t_list *list2 = list;
    int count = 0;
    while (list2 != NULL){
        count++;
        list2 = list2 -> next;
    }
    count--;
    printf("%d\n", count);
}

int main(){
    t_list section_food = stack_create();
    t_list section_appliances = stack_create();
    t_list section_gadgets = stack_create();
   // printf("Hello");    
    robot_put(&section_food, "Apples");
    robot_put(&section_food, "Oranges");
    robot_put(&section_food, "Meat");
    
    robot_put(&section_appliances, "Microwave Owen");
    robot_put(&section_appliances, "Refrigerator");
     


    robot_put(&section_gadgets, "Smartphone");
    robot_put(&section_gadgets, "Watches");
    robot_put(&section_gadgets, "Headphones");
    robot_put(&section_gadgets, "PowerBank");


    robot_pop(&section_food);
    robot_pop(&section_gadgets);
    robot_pop(&section_gadgets);
    robot_pop(&section_appliances);
    robot_len(&section_gadgets);
    robot_len(&section_appliances);

    return 0;
}

