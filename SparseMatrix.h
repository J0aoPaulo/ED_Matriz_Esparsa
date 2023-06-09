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
        int n_col {0}; // número de colunas
        int n_lin {0}; // número de linhas

    public:
        
        // Construtor da classe SparseMatrix
        // - Recebe o número de linhas(m) e colunas(n)
        SparseMatrix(int m, int n){
            if(m > 0 && n > 0){
                m_head = new Node(nullptr, nullptr, 0, 0); // cria o nó cabeça apontado para nulo
                n_col += m; // incrementa o número de linhas
                n_lin += n; // incrementa o número de colunas
                
                Node *aux = m_head;
                for(int i = 1; i <= n_lin; i++){
                    aux->abaixo = new Node(nullptr, nullptr, i, 0);
                    aux = aux->abaixo;
                    aux->direita = aux;
                }
                aux->abaixo = m_head;

                aux = m_head;
                for(int i = 1; i <= n_lin; i++){
                    aux->direita = new Node(nullptr, nullptr, 0, i);
                    aux = aux->direita;
                    aux->abaixo = aux;
                }
                aux->direita = m_head;
            } else {
                cout << "Insira tamanhos válidos! (O número de linhas e de colunas devem ser maiores que 0)." << endl;
            }
        };

        // Destrutor
        ~SparseMatrix();

        // Insere um valor na SparseMatrix
        // - Recebe a linha(i) e a coluna (j) junto do valor(value) a ser inserido na determinada posição
        void insert(int i, int j, double value){

            if(i > this->n_lin || j > this->n_col || i < 1 || j < 1){
                cout << "Insira índices válidos! (Correspondentes ao tamanho da matriz informada)." << endl;
            } else {

                Node *auxl = m_head;
                for(int k = 1; k <= n_lin; k++){
                    if(auxl->linha == i){
                        break;
                    } else {
                        auxl = auxl->abaixo;
                    }
                }

                Node *auxc = m_head;
                for(int k = 1; k <= n_col; k++){
                    if(auxc->coluna == j){
                        break;
                    } else {
                        auxc = auxc->direita;
                    }
                }

                Node *exists = auxl->direita;
                for(int at = 1; at <= n_col; at++){
                    if(exists->coluna == j){
                        exists->valor = value;
                    } else {
                        exists = exists->direita;
                    }
                }

                

                if(auxl->direita == auxl){
                    if(auxc->abaixo == auxc){

                    } else {

                    }
                } else {
                    if(auxc->abaixo == auxc){

                    } else {

                    }
                }


                // quando o nó já existe
                
                // não há nada na linha nem na coluna
                // if(auxl->direita == auxl && auxc->abaixo == auxc){
                //     auxl->direita = new Node(value, auxl, auxc, i, j);
                //     auxc->abaixo = auxl->direita;
                // } else {
            
                // }

                // // quando há nós na linha mas não há nas colunas
                // if(auxl->direita != auxl && auxc->abaixo == auxc){
                //     Node *atual = auxl;
                //     for(int at = 1; at <= n_col; at++){
                //         atual = atual->direita;
                //     }
                // }
            }
        };

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
