package astar;

public class Node {

    private int matrix[][];
    private double g;
    private double h;
    private double f;
    private Node p;

    public Node() {
    }

    public Node(int[][] matrix, double g, double h, double f, Node p) {
        this.matrix = matrix;
        this.g = g;
        this.h = h;
        this.f = f;
        this.p = p;
    }

    public int[][] getMatrix() {
        return matrix;
    }

    public void setMatrix(int[][] matrix) {
        this.matrix = matrix;
    }

    public double getG() {
        return g;
    }

    public void setG(double g) {
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

    public Node getP() {
        return p;
    }

    public void setP(Node p) {
        this.p = p;
    }

    public void calcF() {
        this.f = this.g + this.h;
    }

    public boolean isEstadoFinal() {
        for (int i = 0; i < this.matrix.length; i++) {
            for (int j = 0; j < this.matrix.length; j++) {
                if (this.matrix[i][j] != (i + j * 4 + 1)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    @Override
    public String toString(){
        String str = "";
        for (int i = 0; i < this.matrix.length; i++) {
            for (int j = 0; j < this.matrix.length; j++) {
                str += this.matrix[i][j]+" ";
            }
        }
        return str;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Node object = (Node) obj;
        for (int i = 0; i < this.matrix.length; i++) {
            for (int j = 0; j < this.matrix.length; j++) {
                if (this.matrix[i][j] != object.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

}
