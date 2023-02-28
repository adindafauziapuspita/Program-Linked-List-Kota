#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spNRSLL.h"

// Fungsi untuk mencari node kota pada linked list
struct Node* findKota(kota * head, char * namaKota) {
    struct Node* current = head;

    // Traversing linked list hingga menemukan node dengan namaKota yang sesuai
    while (current != NULL) {
        if (strcmp(current->namaKota, namaKota) == 0) {
            return current;
        }
        current = current->nextKota;
    }

    // Mengembalikan NULL jika node tidak ditemukan
    return NULL;
}

// Fungsi untuk memasukkan warga ke dalam linked list
void insertWarga(kota * head, char * namaKota, char * namaWarga) {
    struct Node* current = findKota(head, namaKota);

    // Membuat node baru untuk warga
    ElmtList* warga = (ElmtList*)malloc(sizeof(ElmtList));
    warga->info = namaWarga;
    warga->next = NULL;

    // Memasukkan node warga ke dalam linked list kota
    if (current->nextList == NULL) {
        current->nextList = warga;
    } else {
        warga->next = current->nextList;
        current->nextList = warga;
    }

    printf("Warga dengan nama %s berhasil ditambahkan ke kota %s.\n", namaWarga, namaKota);
}

// Fungsi untuk menghapus warga dari linked list
void deleteWarga(kota * head, char * namaKota, char * namaWarga) {
    struct Node* current = findKota(head, namaKota);

    // Traversing linked list warga hingga menemukan warga dengan nama yang sesuai
    ElmtList* prev = NULL;
    ElmtList* currWarga = current->nextList;

    while (currWarga != NULL) {
        if (strcmp(currWarga->info, namaWarga) == 0) {
            // Menghapus warga dari linked list
            if (prev == NULL) {
                current->nextList = currWarga->next;
            } else {
                prev->next = currWarga->next;
            }
            free(currWarga);
            printf("Warga dengan nama %s berhasil dihapus dari kota %s.\n", namaWarga, namaKota);
            return;
        }
        prev = currWarga;
        currWarga = currWarga->next;
    }

    printf("Warga dengan nama %s tidak ditemukan di kota %s.\n", namaWarga, namaKota);
}

int main() {
    // Membuat linked list kota
    kota* head = NULL;
    head = (kota*)malloc(sizeof(kota));
    head->namaKota = "Jakarta";
    head->nextKota = NULL;
    head->nextList = NULL;

    // Memasukkan kota baru ke linked list kota
    struct Node* newKota = (struct Node*)malloc(sizeof(struct Node));
    newKota->namaKota = "Bandung";
    newKota->nextKota = head;
    newKota->nextList = NULL;
    head = newKota;
