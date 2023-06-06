//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923
//                                                             //
//-------------------------------------------------------------//


#ifndef NODE_H
#define NODE_H
class Node {

    friend SparseMatrix;
    private:
        Node *direita; // ponteiro para o nó à direita
        Node *abaixo; // ponteiro para o nó abaixo
        int linha; // linha de referência
        int coluna; // coluna de referência
        double valor; // valor guardado no nó

    public:
        Node(const double& val, Node *right = nullptr, Node *down = nullptr, int l, int c){
            valor = val;
            direita = right;
            abaixo = down;
            linha = l;
            coluna = c;
        }

        // Quando for o nó cabeça ou sentinela
        Node(Node *right = nullptr, Node *down = nullptr, int l, int c){
            direita = right;
            abaixo = down;
            linha = l;
            coluna = c;
        }
};


#endif
