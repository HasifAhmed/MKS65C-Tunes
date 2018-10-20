#include "tunes.h"

int indexOf(char * artist){
  int i=artist[0];
  if (artist[0]>=65 && artist[0]<=90){
    i+=32;
  }
  if (i>=97 && i<=122){
    i-=97;
    return i;
  }
  return 26;
}
void add_song(char * name,char *artist){
  int i=indexOf(artist);
  lib[i]=insert_order(lib[i],name,artist);
}


void print_library(){
  int num=0;
  for(;num<27;num++){
    if(lib[num]){
    printf("Artists:%c",num+65);
    print_list(lib[num]);
  }
  }
}
struct song_node * find_song(char * artist, char * name){
  int index = indexOf(artist);
  return find_node( lib[index],name, artist);
}
void find_artist(char *a){
  int index = indexOf(a);
  struct song_node * first = find_first(lib[index],a);
  if(first == NULL){
    printf("node not found\n");
  }
  while(first && strcmp(first->artist,a)==0){
    print_node(first);
    first = first -> next;
  }
}
void print_letter(char * l){
  int index = indexOf(l);
  //printf("%d",index);
  print_list(lib[index]);
}
void clear_library(){
  int num=0;
  for(;num<27;num++){
    if(lib[num]){
     lib[num]=free_list(lib[num]);
    }
  }
}
void shuffle_library(){
  int n = rand()%26;
  //printf("%d",n);
  n++;
  while(n){
    //printf("%d",n);
    //int x=rand()%26;
    //x++;
    if(lib[n]){
    print_node(rand_node(lib[n]));
  }
    n--;
  }
}

void  delete_song(char *name, char *artist){
    int index =indexOf(artist);
    lib[index]=remove_node(lib[index], name,artist);
}
