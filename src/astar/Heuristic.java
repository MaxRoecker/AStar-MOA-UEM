package astar;

public class Heuristic {

    private int h;
    private double p1;
    private double p2;
    private double p3;

    public Heuristic(int h, double p1, double p2, double p3) {
        this.h = h;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public Heuristic() {
    }

    public int getH() {
        return h;
    }

    public void setH(int h) {
        this.h = h;
    }

    public double getP1() {
        return p1;
    }

    public void setP1(double p1) {
        this.p1 = p1;
    }

    public double getP2() {
        return p2;
    }

    public void setP2(double p2) {
        this.p2 = p2;
    }

    public double getP3() {
        return p3;
    }

    public void setP3(double p3) {
        this.p3 = p3;
    }

    private int h1(int matrix[][]) {
        int counter = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                if (matrix[i][j] != (i + j * 4 + 1)) {
                    if (matrix[i][j] != 0) {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }

    private int h2(int matrix[][]) {
        int counter = 0;
        int previous = matrix[0][0];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                if (!(i == 0 && j == 0)) {
                    if (matrix[j][i] != previous + 1) {
                        counter++;
                    }
                    if (matrix[i][j] != 0) {
                        previous = matrix[j][i];
                    }
                }
            }
        }
        return counter;
    }

    private int h3(int matrix[][]) {
        int counter = 0;
        int value;
        int posi;
        int posj;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                if (matrix[i][j] != 0) {
                    value = matrix[i][j] - 1;
                    posi = value % 4;
                    posj = value / 4;
                    counter += Math.abs(posi - i) + Math.abs(posj - j);
                }
            }
        }
        return counter;
    }

    private double h4(int matrix[][]) {
        if (this.p1 + this.p2 + this.p3 != 1) {
            System.out.println("Valores invalidos para os pesos");
            return -1;
        }
        double r1 = this.p1 * h1(matrix);
        double r2 = this.p2 * h2(matrix);
        double r3 = this.p3 * h3(matrix);
        return (r1 + r2 + r3) / 3;
    }

    private int h5(int matrix[][]) {
        int r1 = h1(matrix);
        int r2 = h2(matrix);
        int r3 = h3(matrix);
        if (r1 > r2) {
            if (r1 > r3) {
                return r1;
            } else {
                return r3;
            }
        } else {
            if (r2 > r3) {
                return r2;
            } else {
                return r3;
            }
        }
    }

    public void calc(int matrix[][]) {
        switch (this.h) {
            case 1:
                h1(matrix);
                break;
            case 2:
                h2(matrix);
                break;
            case 3:
                h3(matrix);
                break;
            case 4:
                h4(matrix);
                break;
            case 5:
                h5(matrix);
                break;
        }
    }
}
