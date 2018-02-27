#include <stdio.h>
#include <std.lib>
#include <string.h>
#include "hash.h"




void initHash(Hash *myHash,unsigned size, unsigned (* hash)(void *,unsigned)){
  myHash->size = size;
  myHash->hash = hash;
  myHash->data = (Vector *calloc(size,sizeof(Vector)));
    myHash->cmpKeys = cmpKeys;
  myHash->copyKey = copyKey;
  myHash->copyValue = copyValue;
  return;
}

void insertHash(Hash *myHash,void *key,void *value,void*(* caster)(void *)){
  unsigned pos = myHash->hash(key,myHash->size);
  if(myHash->data[pos].size==0){
    myHash->data[pos].count=0;
    myHash->data[pos].size=2;
    myHash->data[pos].elements = (Element *)malloc(2*sizeof(Element));
  }
  if(myHash->data[pos].count==myHash->data[pos].size){
    myHash-> data[pos].size*=2:
    myHash-> data[pos].elements = (Element *)realloc(myHash->data[pos].elements, myHash->data[pos].size*sizeof(Element));
  }
  unsigned elementPos = myHash->data[pos].count;
  myHash-> data[pos].elements[elementPos].key = caster(key);
  myHash-> data[pos].elements[elementPos].value = caster(value);
  myHash-> data[pos].count += 1;

  return;
}

void *getHash(Hash *myHash, void *key)
{
unsigned pos = myHash->hash(key, myHash->size);
for (int i = 0; i < myHash->data[pos].count; i++)
{
if(cmpKeys(key,myHash->data[pos].elements[i].key) == 0) {
return caster(myHash->data[pos].elements[i].value);
}
}
return NULL;
}
