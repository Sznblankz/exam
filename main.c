#include "musicdb.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    musicdb *db = db_create;
    if (db==NULL){
        printf( "db creation failed\n" );
        return 1;
    }
    printf("songs %d\n", db_song_count(db));
    printf("artists %d\n", db_artist_count(db));
    if(db_get(db,0)==NULL){
        printf("get works\n");
    }
    else{
        printf("get failed\n");
        db_destroy(db);
        printf(" database empty\n");
    }
    return 0;
}
