#include "musicdb.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct MusicDB
{
    Song **songs;
    size_t n_songs;
    size_t song_cap;
    Artist **artists;
    size_t n_artists;
    size_t artist_cap;
};

MusicDB *db_create(){
MusicDB *db = malloc(sizeof(MusicDB));
if (db ==NULL){
    return NULL;
}
(*db).songs =NULL;
(*db).n_songs =0;
(*db).song_cap =0;
(*db).artists =NULL;
(*db).n_artists =0;
(*db).artist_cap =0;
return db;
}
void          db_destroy(MusicDB *db){
    if (db==NULL){
    return;
    };
    size_t i =0;
    while (i<(*db).n_songs){
        Song *song=(*db).songs[i];
        free((*song).title);
        free(song);
    }
    while (i<(*db).n_artists){
        Artist *artist=(*db).artists[i];
        free((*artist).songs);
        free((*artist).name);
        free(artist);
    }
    free((*db).songs);
    free((*db).artists);
    free((db));

}

size_t        db_song_count(const MusicDB *db){
    if(db==NULL){
        return 0;
    }
    return(*db).n_songs;
}
size_t        db_artist_count(const MusicDB *db){
     if(db==NULL){
        return 0;
    }
    return(*db).n_artists;
}
const Song   *db_get(const MusicDB *db, size_t i){
     if(db==NULL){
        return NULL;
    }
    if( i>=(*db).n_songs){
        return NULL;
    }
    return (*db).songs[i];
}
int           db_push(MusicDB *db, const char *title, const char *artist,double rating, int year, unsigned long num_rated){

    if(title==NULL){
        return -1;
    }
    if(db==NULL){
        return -1;
    }
    if(artist==NULL){
        return -1;
    }
    size_t len =0;
    while (title[len] !=0){
        len++;
    }
     char *cp =malloc(len);
     if(cp==NULL){
        return -1;
    }
    for(size_t j =0;j<=len;j++){
        cp[j] = title[j];
    }
    Artist *fArtists =NULL;
    size_t k = 0;
    while (k<((*db).n_artists)){
        Artist *current=(*db).artists[k];
        if (strcmp((*current).name,artist)==0){
            fArtists=current;
            break;
        }
        k++;
    }
    int artistNew = (fArtists==NULL)
    if (artistNew){
        fArtists= malloc(sizeof(Artist));
        free(cp);
        return -1
    }
    size_t namelen = 0;
    while( artist[namelen]){
        namelen++;
    }
    (*fArtists).name=malloc(namelen);
    if ((*fArtists).name==NULL){
        free(fArtists);
        free(cp);
        return -1;
    }
    size_t j=0;
    while (j<=namelen){
        (*fArtists).name[j]=artist[j];
        j++;
    }
    (*fArtists).songs=NULL;
    (*fArtists).n_songs=0;
    (*fArtists).cap=0;
    Song *song = malloc(sizeof(Song));
    if(snong ==NULL){
        if(artistNew){
            free((*fArtists).name);
            free(*fArtists);
    }

    free(cp);
    return -1;
}
(*song).title=cp;
(*song).artist=fArtists;
(*song).rating=rating ;
(*song).year=year;
(*song).num_rated=num_rated;
(*song).id=(*db).n_songs;
//db_Push is partially finished and needs more work 
}

