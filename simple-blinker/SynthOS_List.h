#ifndef SYNTHOS_LIST_INCLUDED
#define SYNTHOS_LIST_INCLUDED

/*
 * A List is used as both a list header and as an element that
 * can be added to a List. This is essentially "inherited" by structures
 * that will be placed into linked lists. The implementation is doubly-linked
 * so that additions and removals can be made anywhere in the list.
 */
typedef struct SynthOS_List {
    struct SynthOS_List *next;
    struct SynthOS_List *previous;
} SynthOS_List;

void SynthOS_listInit(SynthOS_List *list);
void SynthOS_listAppend(SynthOS_List *list, SynthOS_List *element);
void SynthOS_listInsertBefore(SynthOS_List *new, 
			      SynthOS_List *old);
SynthOS_List *SynthOS_listRemoveFirst(SynthOS_List *list);
void SynthOS_listRemove(SynthOS_List *element);
int SynthOS_listIsEmpty(SynthOS_List *list);

#endif
