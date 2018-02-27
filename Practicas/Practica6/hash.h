typedef struct e{
  void *key;
  void *value;
} Element

typedef struct v{
  unsigned count;
  unsigned size;
  Element *elements
}Vector;

typedef struct h{
  unsigned size;
  Vector *data;
  unsigned (* hash)(void *,unsigned);
  void *(*copyValue)(void *);
  void *(*copyKey)(void *);
  int (*cmpKeys)(void *, void *);
}Hash;

void initHash(Hash *myHash,unsigned size, unsigned (* hash)(void *,unsigned));

void insertHash(Hash *,void *,void *);

void * getHash(Hash *,void *);
