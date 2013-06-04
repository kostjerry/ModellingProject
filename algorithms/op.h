#ifndef OP_H
#define OP_H

class Op
{
public:
    Op();
    double **createMatrix(int n);
    double *createVector(int n);
    void mulMatrixVector(double *dest, double **matrix, double *vector, int n);
    double mulVector(double *v1, double *v2, int n);
    void copyMatrix(double **dest, double **source, int n);
    void mulMatrix(double **dest, double **source1, double **source2, int n);
    void transposeMatrix(double **dest, double **source, int n);
    void copyVector(double *dest, double *source, int n);
};

#endif // OP_H
