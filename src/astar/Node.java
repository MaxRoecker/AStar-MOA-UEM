package astar;


public class Node {
    
    private int g;
    private double h;
    private double f;
    private Node pai;
    private int tabuleiro[][];

    public Node(int g, double h, double f, Node pai, int[][] tabuleiro) {
        this.g = g;
        this.h = h;
        this.f = f;
        this.pai = pai;
        this.tabuleiro = tabuleiro;
    }

    
    
    public Node() {
    }

    public int getG() {
        return g;
    }

    public void setG(int g) {
        this.g = g;
    }

    public double getH() {
        return h;
    }

    public void setH(double h) {
        this.h = h;
    }

    public double getF() {
        return f;
    }

    public void setF(double f) {
        this.f = f;
    }

    public Node getPai() {
        return pai;
    }

    public void setPai(Node pai) {
        this.pai = pai;
    }

    public int[][] getTabuleiro() {
        return tabuleiro;
    }

    public void setTabuleiro(int[][] tabuleiro) {
        this.tabuleiro = tabuleiro;
    }

    public void calculaF() {
        this.f = this.g + this.h;
    }

    boolean isEstadoFinal() {
        return h == 0;
    }


    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Node other = (Node) obj;
        for (int i = 0; i < tabuleiro.length; i++) {
            for (int j = 0; j < tabuleiro.length; j++) {
                if (tabuleiro[i][j]!=other.tabuleiro[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

    
}
