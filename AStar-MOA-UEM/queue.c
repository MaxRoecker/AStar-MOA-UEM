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

void insertAtEnd(tQueue *queue, tNodeQueue node) {
    //lista vazia
    if ((queue->begin == NULL) && (queue->end == NULL)) {
        node.ant = NULL;
        node.next = NULL;
        queue->begin = &node;
        queue->end = &node;
    } else {
        printf("\n\nFim da lista: %d",queue->end->elem->f);
        queue->end->next = &node;
        node.ant = queue->end;
        node.next = NULL;
        queue->end = &node;
        printf("\n\nNovo Fim da lista: %d\n",queue->end->elem->f);
    }
    queue->length++;
}

void removeMin(tQueue *queue, tNodeQueue *node) {
    if (queue->length == 0) {
        node = NULL;
        return;
    }
    if (queue->length == 1) {
        node = queue->begin;
        queue->begin = NULL;
        queue->end = NULL;

    } else {
        tNodeQueue *e = queue->begin->next;
        node = queue->begin;
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
}
