#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    /** YOU DON'T NEED TO MODIFY THIS */
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    * YOU DON'T NEED TO MODIFY THIS
    */

    address Q = first(L);
    if (first(L) != NULL){
        do {
            cout<<"name    : "<<info(Q).name<<endl
                <<"ID      : "<<info(Q).ID<<endl
                <<"location: "<<info(Q).location<<endl;
            Q = next(Q);
        } while(Q!=first(L));
    }else{
        cout<<"List Kosong"<<endl;
    }
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    * YOU DON'T NEED TO MODIFY THIS
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //------------- YOUR CODE HERE -------------
    address P = first(L);
    int i = 0;
    do{
        P = next(P);
        i++;
    }while (P != first(L));

    address Q,R;
    for(int j = 1; j <= i; j++){
        int hasilAcak = randomInt(j);
        int h = 1;
        Q = first(L);
        do{
            h++;
            Q = next(Q);
        }while (Q != first(L) && h < hasilAcak);
        deleteAfter(L,prev(Q),R);
        insertFirst(L,R);
    }

    //----------------------------------------
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------
    for(int i = 0; i < n; i++){
        address P = first(L);
        do{
            playMusic(P);
            P = next(P);
        }while (P!=first(L));
    }
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //------------- YOUR CODE HERE -------------
    address P,Q;
    P =findElmByID(L,x);
    P = prev(P);
    if(P == NULL){
        cout<<"Music Not Found"<<endl;
    }else if (next(P) == first(L)){
        deleteFirst(L,P);
        deallocate(P);
    }else if(info(next(P)).ID == x.ID){
        deleteAfter(L,P,Q);
    }
    //----------------------------------------
}
