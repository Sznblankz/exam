#include "MusicDB.h"
#include <stdlib.h>
#include <stdio.h>
struct MusicDB
{
    Song **songs;
    size_t n_songs;
    size_t song_cap;
    Artist **artists;
    size_t n_artists;
    size_t artist_cap;
};

MusicDB *db_create{
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
MusicDB db_destroy{
free(songs);
free(n_songs);
free(song_cap);
free(artists);
free(n_artists);
free(artist_caps);
}