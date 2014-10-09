package astar;

import astar.Node;


public class Heuristicas {

    private int tabuleiro[][];

    public void heuristica1(Node n) {
        this.tabuleiro = n.getTabuleiro();
        int h = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 3 && j == 3) {
                    if (this.tabuleiro[i][j] != 0) {
                        h++;
                    }
                } else if (this.tabuleiro[i][j] != 0) {
                    if (this.tabuleiro[i][j] != (i + j * 4 + 1)) {
                        h++;
                    }
                }
            }

        }
        n.setH(h);
    }

    public void heuristica2(Node n) {
        this.tabuleiro = n.getTabuleiro();
        int sequencia = this.tabuleiro[0][0];
        int cont = 0;
        for (int coluna = 0; coluna < 4; coluna++) {
            for (int linha = 0; linha < 4; linha++) {
                if (coluna != 0 || linha != 0) {
                    if (coluna != 3 || linha != 3) {
                        sequencia++;

                        if (this.tabuleiro[linha][coluna] != (sequencia)) {
                            cont++;
                        }
                        sequencia = tabuleiro[linha][coluna];
                    }
                    if (tabuleiro[linha][coluna] != 0) {
                        sequencia = tabuleiro[linha][coluna];
                    }
                    if (tabuleiro[linha][coluna] == 15) {
                        sequencia = 0;
                    }

                }
            }

        }
        n.setH(cont);
    }

    public void heuristica3(Node n) {
        this.tabuleiro = n.getTabuleiro();
        int desloc = 0;
        for (int coluna = 0; coluna < 4; coluna++) {
            for (int linha = 0; linha < 4; linha++) {
                if (tabuleiro[linha][coluna] != 0 && (tabuleiro[linha][coluna] != linha + coluna * 4 + 1)) {
                    int linhaReal = (tabuleiro[linha][coluna] - 1) % 4;
                    int colunaReal = (tabuleiro[linha][coluna] - 1) / 4;
                    int deslocamentoLocal = Math.abs(linha - linhaReal) + Math.abs(coluna - colunaReal);
                    desloc += deslocamentoLocal;
                }
            }
        }
        n.setH(desloc);
    }

    public void heuristica4(Node n) {
        double p1, p2, p3, h1, h2, h3;

        p1 = 0.3;
        p2 = 0.3;
        p3 = 0.4;

        heuristica1(n);
        h1 = n.getH();
        heuristica2(n);
        h2 = n.getH();
        heuristica3(n);
        h3 = n.getH();
        n.setH(p1 * h1 + p2 * h2 + p3 * h3);
    }

    public void heuristica5(Node n) {
        heuristica1(n);
        double max = n.getH();
        heuristica2(n);
        if (max < n.getH()) {
            max = n.getH();
        }
        heuristica3(n);
        if (max < n.getH()) {
            max = n.getH();
        }
        n.setH(max);
    }

    public void aplicaHeuristica(Node n, int heuristica) {
        switch (heuristica) {
            case 1:
                heuristica1(n);
                break;
            case 2:
                heuristica2(n);
                break;
            case 3:
                heuristica3(n);
                break;
            case 4:
                heuristica4(n);
                break;
            case 5:
                heuristica5(n);
                break;
        }
    }
}
