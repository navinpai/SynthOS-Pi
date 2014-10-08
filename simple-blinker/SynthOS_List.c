#include "SynthOS_List.h"

/*
 * Initialize a linked list.
 */
void SynthOS_listInit(SynthOS_List *list) {
    list->next = list;
    list->previous = list;
}

/*
 * Add an element to the tail of a list.
 */
void SynthOS_listAppend(SynthOS_List *list, SynthOS_List *element) {
    element->next = list;
    element->previous = list->previous;
    list->previous->next = element;
    list->previous = element;
}

/*
 * Insert an element, new, into a list before another element, old, already on
 * that list.
 */
void SynthOS_listInsertBefore(SynthOS_List *new, SynthOS_List *old) {
  SynthOS_listAppend(new, old);
}

/*
 * Remove the element at the head of a list.
 * Return NULL if list is empty.
 */
struct SynthOS_List *SynthOS_listRemoveFirst(SynthOS_List *list) {
    SynthOS_List *element = list->next;
    if (element == list)
        return 0;
    else {
        SynthOS_listRemove(element);
        return element;
    }
}

/*
 * Remove an element from whatever list it happens to be on. If it's not
 * on a list, nothing happens.
 */
void SynthOS_listRemove(SynthOS_List *element) {
    element->previous->next = element->next;
    element->next->previous = element->previous;
    element->next = element;
    element->previous = element;
}

/**
 * Test if a linked list is empty. Returns 1 if empty, otherwise 0.
 */
int SynthOS_listIsEmpty(SynthOS_List *list) {
    return (list->next == list);
}





