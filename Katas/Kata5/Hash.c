
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

void initHash(Hash *h, unsigned size,
              unsigned (*hash)(void *, unsigned),
              void *(*copyKey)(void *),
              void *(*copyValue)(void *),
              int (*compareKeys)(void *, void *)) {
    h->size = size;
    h->hash = hash;
    h->copyKey = copyKey;
    h->copyValue = copyValue;
    h->compareKeys = compareKeys;
    h->data = (Vector*)calloc(size, sizeof(Vector));
    return;
}

void insert(Hash *h, void *key, void *value) {
    unsigned pos = h->hash(key, h->size);

    if(h->data[pos].size == 0) {
        h->data[pos].count = 0;
        h->data[pos].size = 2;
        h->data[pos].elements = (Element *)malloc(2 * sizeof(Element));
    }

    if(h->data[pos].count == h->data[pos].size) {
        h->data[pos].size *= 2;
        h->data[pos].elements = (Element *) realloc(h->data[pos].elements, h->data[pos].size);
    }

    unsigned elementPos = h->data[pos].count;
    h->data[pos].elements[elementPos].key = h->copyKey(key);
    h->data[pos].elements[elementPos].value = h->copyValue(value);
    h->data[pos].count++;
}

void * get(Hash *h, void *key) {
    unsigned pos = h->hash(key, h->size);
    for (int i = 0; i < h->data[pos].count; i++) {
        if (h->compareKeys(key, h->data[pos].elements[i].key)) {
            return h->copyValue(h->data[pos].elements[i].value);
        }
    }
    return NULL;
}
