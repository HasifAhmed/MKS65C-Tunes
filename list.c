#include "list.h"



struct song_node * make_song(char * n, char * a){
  struct song_node *new = calloc(sizeof(struct song_node), 1);
  strcpy(new->name,n);
  strcpy(new->artist,a);
  return new;
}


struct song_node * insert_back(struct song_node *p, struct song_node *new){
  struct song_node * iter = p;

  if(p == NULL){
     return new;
  }

  while(iter -> next != NULL){
    iter = iter -> next;
  }
  iter -> next = new;
  return p;
}
void print_node(struct song_node *p){
  if(p){
    //printf("node found ");
    //printf("%s",p->artist);
    printf("|%s: %s| \n", p->artist, p->name);
  }
  else{
    printf("node not found\n");
  }
}

void print_list(struct song_node *p){
  printf("\n=====================================\n");
  if(p == NULL){
    return;
  }
	while(p){
		printf("|%s: %s| ", p->artist, p->name);
		p=p->next;
	}
  printf("\n=====================================\n");

}

struct song_node * insert_front(struct song_node *p, char *song, char *a){
	struct song_node *new = malloc(sizeof(struct song_node));
	strcpy(new->name, song);
	strcpy(new->artist, a);
	new->next = p;
	return new;
}

struct song_node * free_list(struct song_node * p){
  struct song_node *curP = p;
  struct song_node *tempP = p;
  while(curP){
    curP = curP->next;
    free(tempP);
    tempP = curP;
  }
  return curP;
}

struct song_node * insert_order(struct song_node *p, char *song, char *a){
  struct song_node *new = malloc(sizeof(struct song_node));
	strcpy(new->name, song);
	strcpy(new->artist, a);

  struct song_node *iter = malloc(sizeof(struct song_node));
  iter = p;

	if(!iter){
		return new;
	}

  if(strcmp(a, iter->artist) < 0 || (strcmp(a, iter->artist) == 0 && strcmp(song, iter->name) < 0)){
   new->next = iter;
   return new;
 }

 struct song_node *bef = malloc(sizeof(struct song_node));
 bef = p;

 while(iter  && (strcmp(a, iter->artist)>0 || (strcmp(a, iter->artist)==0 && strcmp(song, iter->name) > 0))){
  bef = iter;
  iter = iter -> next;
 }
 new->next = iter;
 bef->next = new;
 return p;
}

struct song_node* find_node(struct song_node *p, char *n, char *a){
  while(p){
    if(strcmp(a, p->artist) == 0 && strcmp(n, p->name) == 0){
      return p;
    }
    p = p->next;
  }
  return NULL;
}

struct song_node * find_first(struct song_node *p, char *a){
  while(p){
    if(strcmp(a, p->artist) == 0){
      return p;
    }
    p = p->next;
  }
  return NULL;
}

struct song_node * rand_node(struct song_node *p){
  struct song_node *iter = malloc(sizeof(struct song_node));
  iter = p;
  int cnt = 0;
  while(iter){
    cnt++;
    iter = iter->next;
  }
  int i = rand() % cnt;
  for(;i>0;i--){
    p = p->next;
  }
  return p;
}


struct song_node * remove_node(struct song_node *p,char* n, char * a){
  struct song_node * curP = p;
  struct song_node * prevP = p;
  if (strcmp(n,curP->name)==0 && strcmp(a,curP->artist)==0)
    {
        p = curP->next;  // *p = p->next;
        free(curP);
        return p;
    }
    while (curP != NULL && curP ->next !=NULL && (strcmp(n,curP->name)!=0 || strcmp(a,curP->artist)!=0))
    {
        prevP = curP;
        curP = curP->next;
    }
    prevP->next = curP ->next;
    free(curP);
    return p;
}
