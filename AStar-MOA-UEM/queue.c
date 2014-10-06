/* 
 * File:   main.c
 * Author: joao
 *
 * Created on 24 de Setembro de 2014, 10:23
 */

#include <stdio.h>
#include <stdlib.h>
#include "definicoes.h"

void initialize(tQueue *queue) {
    queue->begin = NULL;
    queue->end = NULL;
    queue->length = 0;
}

void insertAtEnd(tQueue *queue, tNodeQueue *node) {
    //lista vazia
    printf("%d\n",queue);
    if ((queue->begin == NULL) && (queue->end == NULL)) {
        node->ant = NULL;
        node->next = NULL;
        queue->begin = node;
        queue->end = node;
    } else {
        node->ant = queue->end;
        node->next = NULL;
        queue->end->next = node;
        queue->end = node;
    }
    queue->length++;
}

tNodeQueue* removeMin(tQueue *queue) {
    tNodeQueue *node;
    if (queue->length == 0) {
        node = NULL;
        return 1;
    }
    if (queue->length == 1) {
        node = queue->begin;
        queue->begin = NULL;
        queue->end = NULL;
    } else {
        tNodeQueue *e = queue->begin->next;
        node = e->ant;
        while (e != NULL) {
            if (node->elem->f > e->elem->f) {
                node = e;
            }
            e = e->next;
        }
        //node é o menor da lista
        if (node->ant == NULL) {
            queue->begin = node->next;
            node->next->ant = NULL;
        } else if (node->next == NULL) {
            queue->end = node->ant;
            node->ant->next = NULL;
        } else {
            node->ant->next = node->next;
            node->next->ant = node->ant;
        }
    }
    queue->length--;
    return node;
}

int removeElem(tNodeQueue *elem, tQueue *queue){
    tNodeQueue *e = queue->begin;
    while ((e != NULL) && (!(equalsNode(elem, e)))) {
        e = e->next;
    }
    if (e == NULL) {
        return 0;
    }
    e->ant->next = e->next;
    e->next->ant = e->ant;
    free(e);    
}

void printQueue(tQueue *queue) {
    if (queue->length == 0) {
        printf("\nLista Vazia!\n");
    } else {
        printf("\nLista:\n");
        tNodeQueue *e = queue->begin;
        while (e != NULL) {
            printf("f: %d\n", e->elem->f);
            e = e->next;
        }
        printf("\n");
    }
}

int isEmpty(tQueue *queue) {
    if (queue->length > 0) {
        return 0;
    }
    return 1;
}

int equalsNode(tNodeQueue *e1, tNodeQueue *e2) {
    if (e1->elem->h == e2->elem->h) {
        if (equalsMatrix(e1->elem->matrix, e2->elem->matrix)) {
            return 1;
        }
    }
    return 0;
}

int memberOf(tNodeQueue *elem, tQueue *queue) {
    tNodeQueue *e = queue->begin;
    while ((e != NULL) && (!(equalsNode(elem, e)))) {
        e = e->next;
    }
    if (e == NULL) {
        return 0;
    }
    return 1;
}

int memberOfWithGMin(tNodeQueue *elem, tQueue *queue) {
    tNodeQueue *e = queue->begin;
    while ((e != NULL) && (!(equalsNode(elem, e)))) {
        e = e->next;
    }
    if ((e != NULL) && (e->elem->g > elem->elem->g)) {
        return 1;
    }
    return 0;
}