//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923
//                                                             //
//-------------------------------------------------------------//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <iostream>
#include "Node.h"
using namespace std;

// Interface da classe SparseMatrix
class SparseMatrix {

    private:

        Node *m_head; // nó cabeça
        int n_col; // número de colunas
        int n_lin; // número de linhas

    public:
        
        // Construtor da classe SparseMatrix
        // - Recebe o número de linhas(m) e colunas(n)
        SparseMatrix(int m, int n){
            
        };

        // Destrutor
        ~SparseMatrix();

        // Insere um valor na SparseMatrix
        // - Recebe a linha(i) e a coluna (j) junto do valor(value) a ser inserido na determinada posição
        void insert(int i, int j, double value);


        // Devolve o valor na célula (i, j) da matriz
        // Checa se os índices passados são válidos
        double get(int i, int j);

        // Printa a matriz A no terminal
        // Inclusive os elementos iguais a 0
        void print();

};


#endif

// início: 29/05
// conclusão 02/06
