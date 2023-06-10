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
                m_head = new Node(m_head, m_head, 0, 0); // cria o nó cabeça apontado para ele mesmo para e baixo e para a direita
                n_lin = m; // incrementa o número de linhas
                n_col = n; // incrementa o número de colunas
                
                Node *aux = m_head; // auxiliar é o m_head
                for(int i = 1; i <= n_lin; i++){ // percorre o número de linhas de 1 até o tamanho
                    aux->abaixo = new Node(nullptr, nullptr, i, 0); // auxiliar abaixo aponta para um novo nó
                    aux = aux->abaixo; // auxiliar é o nó abaixo dele
                    aux->direita = aux; // auxiliar direita aponta para ele mesmo
                    aux->abaixo = m_head;
                }

                aux = m_head; // auxiliar é o m_head
                for(int i = 1; i <= n_col; i++){ // percorre o número de colunas, do 1 ao tamanho
                    aux->direita = new Node(nullptr, nullptr, 0, i); // auxiliar direita aponta para um NOVO nó
                    aux = aux->direita; // auxiliar é o NOVO nó
                    aux->abaixo = aux; // auxiliar abaixo aponta para ele mesmo
                    aux->direita = m_head;
                }
            } else {
                cout << "Insira tamanhos válidos! (O número de linhas e de colunas devem ser maiores que 0)." << endl;
            }
        };

        bool indice_invalido(int i, int j){
            return i > n_lin || j > n_col || i < 1 || j < 1;
        }

        // Destrutor
        ~SparseMatrix();

        // Insere um valor na SparseMatrix
        // - Recebe a linha(i) e a coluna (j) junto do valor(value) a ser inserido na determinada posição
        void insert(int i, int j, double value){

            if(indice_invalido(i, j)){
                cout << "insercao no indice errado" << endl;
                return;
            } else {

                Node *auxl = m_head; // auxl é m_head
                for(int k = 1; k <= n_lin; k++){ // percorre todas as linhas, de 1 até o número de linhas
                    if(auxl->linha == i){
                        break;
                    } else {
                        auxl = auxl->abaixo; // auxl é o próximo nó abaixo
                    }
                }

                Node *auxc = m_head; // aux é m_head
                for(int k = 1; k <= n_col; k++){ // percorre todas as colunas, de 1 ao tamanho
                    if(auxc->coluna == j){
                        break;
                    } else {
                        auxc = auxc->direita; // auxc é igual ao próximo a direita
                    }
                }

                if(auxl->direita == auxl){ // quando a linha está vazia
                    if(auxc->abaixo == auxc){ // quando a coluna está vazia
                        auxl->direita = new Node(value, auxl, auxc, i, j);
                        auxc->abaixo = auxl->direita;
                    } else {
                        Node *atual = auxc; // atual é auxc
                        for(int at = 0; at <= n_lin; at++){ // percorre da coluna sentinela atée o último nó da coluna,ou seja do 0 ao tamanho
                            if((i > atual->linha && i < atual->abaixo->linha) || atual->abaixo->linha == 0){
                                Node* novo = new Node(value, auxl, atual->abaixo, i, j);
                                auxl->direita = novo;
                                atual->abaixo = novo;
                                break;
                            } else {
                                atual = atual->abaixo;
                            }
                        }
                    }
                } else { // quando a linha possui pelo menos um nó
                    if(auxc->abaixo == auxc){

                        Node *atual = auxl;
                        for(int at = 0; at <= n_col; at++){ // percorre o sentinela ao último nó, ou seja, de 0 ao tamanho
                            if((j > atual->coluna && j < atual->direita->coluna) || atual->direita->coluna == 0){
                                Node* novo = new Node(value, atual->direita, auxc, i, j);
                                auxc->abaixo = novo;
                                atual->direita = novo;
                                break;
                            } else {
                                atual = atual->direita;
                            }
                        }

                    } else {
                        while (auxl->direita->coluna < j && auxl->direita->coluna != 0) {
                            auxl = auxl->direita;
                        }

                        while (auxc->abaixo->linha < i && auxc->abaixo->linha != 0) {
                            auxc = auxc->abaixo;
                        }
                        
                        Node* novo = new Node(value, auxl->direita, auxc->abaixo, i, j);
                        auxl->direita = novo;
                        auxc->abaixo = novo;
                    }
                }

            }
        };

        double get(int i, int j){
            if (indice_invalido(i, j)) {
                cout << "impressao no indice errado" << endl;
                return 0.0;
            } else {
                Node* auxl = m_head;
                for (int k = 1; k <= n_lin; k++) {
                    if (auxl->linha == i) {
                        break;
                    } else {
                        auxl = auxl->abaixo;
                    }
                }

                Node* auxc = m_head;
                for (int k = 1; k <= n_col; k++) {
                    if (auxc->coluna == j) {
                        break;
                    } else {
                        auxc = auxc->direita;
                    }
                }

                Node* atual_linha = auxl;
                for (int at = 0; at <= n_col; at++) {
                    if (atual_linha->coluna < j) {
                        atual_linha = atual_linha->direita;
                    } else if (atual_linha->coluna == j) {
                        return atual_linha->valor;
                    } else {
                        return 0.0; // Elemento não encontrado, valor padrão 0.0
                    }
                }
            }

            return 0.0; // Elemento não encontrado, valor padrão 0.0
        };


        // Printa a matriz A no terminal
        // Inclusive os elementos iguais a 0
        void print(){
            Node* auxl = m_head->abaixo; // First auxl (excluding the head node)

            // Traverse each auxl
            while (auxl != m_head) {
            Node* atual = auxl->direita; // First node in the auxl (excluding the head node)

             // Traverse each node in the auxl
            for (int j = 1; j <= n_col; j++) {
                if (atual != auxl && atual->coluna == j) {
                    cout << atual->valor << " ";
                    atual = atual->direita;
                } else {
                    cout << "0 ";
                }
            }   

            cout << endl;
            auxl = auxl->abaixo;
            }
        };
};


#endif

// início: 29/05
// conclusão 02/06
