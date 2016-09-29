

/*
    Varebestillings software opgave 2.1
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden


Includerer relevante libraries
*/
#include<stdio.h>
#include<stdlib.h>
#define maksBest lager_len
struct lagervare
{
    int vareNr;
    int pris;
    char* beskrivelse;
};

struct kundeordre
{
    int vareNr;
    int antal;
};

struct lagervare firmaLager[] = {{.vareNr = 1, .pris = 27, .beskrivelse = "Panama papers"},
                    {.vareNr = 2, .pris = 50, .beskrivelse = "Hillary Clintons email server"},
                    {.vareNr = 3, .pris = 203, .beskrivelse = "Donald trumps tax returns"},
                    {.vareNr = 4, .pris = 12, .beskrivelse = "Proof tha the moonlanding was a hoax"},
                    {.vareNr = 5, .pris = 1, .beskrivelse = "North Korean nuklear launch codes"},
                    {.vareNr = 6, .pris = 42, .beskrivelse = "The missing link"},
                    {.vareNr = 7, .pris = 1337, .beskrivelse = "Doughnut holes"},
                    {.vareNr = 8, .pris = 13, .beskrivelse = "sonic screwdriwer"},
                    {.vareNr = 9, .pris = 78, .beskrivelse = "The lost ark"},
                    {.vareNr = 10, .pris = 420, .beskrivelse = "Rubber docky"},
                    {.vareNr = 11, .pris = 9999, .beskrivelse = "The lost nazi treasure"}};



//længden af lager_len beregnet ved størrelse i bit / størrelsen af et element i bit
int lager_len = sizeof(firmaLager)/sizeof(firmaLager[0]);

void bobble_sort(struct kundeordre array[], int length);

void print_lager(struct lagervare lager[]);

void print_ordre(struct kundeordre ordre[], int count);

int lager_search(int varenummer);
