#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>

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

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	int i, flag = 0, pos = 0;
	struct hashLink itr;

	i = stringhash1(k) % ht->tableSize; /*find bucket data should be in*/
	itr = ht->table[i];
	while (itr != NULL) {
		pos++;
		if (itr->key == k) {
			flag = 1;
			break;
		}
		itr = itr->next;		
	}

	if (!flag) { /*if matching key wasn't found*/
		itr = (hashLink*)malloc(sizeof(hashLink);
		itr->key = k;
		itr->value = v;
		itr->next = ht->table[i];
		ht->table[i] = itr;
		ht->count++;
	}
	else {
		/*replace node p in bucket i's value with v*/
		itr->value = v;
	}
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/
}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
}

