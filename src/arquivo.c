//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <string.h>
#include "headers/arquivo.h"

void verificaArquivo(FILE *arquivo) {
    if (!arquivo) {
        printf("\nFalha ao abrir o arquivo!\n");
        exit(0);
    }
}

Grafo *___preencherVertices(FILE *arquivo) {
    Grafo *novoGrafo = criaGrafo();
    char linha[999];
    char *nome;
    fgets(linha, 999, arquivo);
    nome = strtok(linha, ";");
    inserirGrafo(novoGrafo, criaAresta(nome, nome, 0, 0));
    for (int i = 1; (nome = strtok(NULL, ";")); i++) {
        inserirGrafo(novoGrafo, criaAresta(nome, nome, 0, 0));
    }
    return novoGrafo;
}

Grafo *___preencherDistancias(FILE *arquivo) {
    char linha[999];
    char *distancia;
    char *origem;
    char *destino;
    Grafo *grafoBairros = ___preencherVertices(arquivo);
    Grafo *novoGrafo = criaGrafo();
    for (int i = 0; fgets(linha, 999, arquivo); i++) {
        strtok(linha, ";");
        origem = grafoBairros->arestas->registros[i]->origem;
        for (int j = 0; (distancia = strtok(NULL, ";")); j++) {
            if (strcmp(distancia, "0") == 0 || strcmp(distancia, "0\n") == 0) continue;
            destino = grafoBairros->arestas->registros[j]->destino;
            inserirGrafo(novoGrafo, criaAresta(origem, destino, distancia, "0"));
        }
    }
    return novoGrafo;
}

Grafo *preencherGrafo(FILE *arquivo) {
    verificaArquivo(arquivo);
    return ___preencherVertices(arquivo);
}