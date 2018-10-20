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
struct song_node * find_artist(char *a){
  int index = indexOf(a);
  struct song_node * first = find_first(lib[index],a);
  while(strcmp(first->artist,a)){
    print_node(first);
    first = first -> next;
  }
}
