#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <stdio.h>

int stringHash1(char * str)
{
		int i;
			int r = 0;
				for (i = 0; str[i] != '\0'; i++)
							r += str[i];
					return r;
}

int stringHash2(char * str)
{
		int i;
			int r = 0;
				for (i = 0; str[i] != '\0'; i++)
							r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
					return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
		int index;
			if(ht == NULL)
						return;
				ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
					ht->tableSize = tableSize;
						ht->count = 0;
							for(index = 0; index < tableSize; index++)
										ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/
	int i;
	struct hashLink *next = NULL, *curr = NULL;
	for (i = 0; i < ht->tableSize; i++) {
		curr = ht->table[i];
		while (next != NULL) {
			next = curr->next;
			free(curr);
			curr = next;
		}
		ht->table[i] = NULL;
	}
}

void insertMap(struct hashMap* ht, KeyType k, ValueType v)
{
	int i, flag = 0;
	struct hashLink* itr;

	i = stringHash1(k) % ht->tableSize; /*find bucket data should be in*/
	itr = ht->table[i];
	while (itr != NULL) {
		if (strcmp(itr->key, k) == 0) { 
			flag = 1;   /*match found*/
			/*printf("Match found\n");*/
			break;
		}
		itr = itr->next;
	}

	if (flag) {
		/* concurrence was found, so increment value*/
		itr->value++;
	}
	else { /*if matching key wasn't found, add a new link*/
		itr = (hashLink*)malloc(sizeof(hashLink));
		itr->key = k; 
		itr->value = v;
		itr->next = NULL;
		ht->table[i] = itr;
		ht->count++;
	}
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/
	int i, flag = 0;
	struct hashLink* itr;
	i = stringHash1(k) % ht->tableSize;
	itr = ht->table[i];
	while (itr != NULL) {
		if (itr->key == k) {
			flag = 1;
			break;
		}
		itr = itr->next;
	}
	if (flag == 1) {
		return &(itr->value);
	}
	else return NULL;
}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/

        int i, flag = 0;
        struct hashLink* itr;
        i = stringHash1(k) % ht->tableSize;
        itr = ht->table[i];
        while (itr != NULL) {
                if (itr->key == k) {
                        flag = 1;
                        break;
                }
                itr = itr->next;
        }
        return flag;
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	int i, flag = 0;
	struct hashLink* itr;

	i = stringHash1(k) % ht->tableSize; /*find bucket data should be in*/
	itr = ht->table[i];
	while (itr != NULL) {
		if (itr->key == k) {
			flag = 1;
			break;
		}
		itr = itr->next;		
	}

	if (flag) {
		/*remove node p from bucket i*/
		itr = ht->table[i];
		while (itr->next != NULL) {
			if (itr->next->key == k) {
				itr->next = itr->next->next;
				break;
			}
			itr = itr->next;
		}
		ht->count--;
		free(itr);

	}
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	return ht->count;
}

int capacityMap(struct hashMap *ht)
{  /*write this? not in assignment*/
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  /*write this */
	int i, count = 0;
	for (i = 0; i < ht->tableSize; i++) {
		if (ht->table[i] == NULL) {
			count++;
		}
	}
	return count;
}



float tableLoad(struct hashMap *ht)
{
	float load = (float)ht->count / ht->tableSize;
	return load;
}