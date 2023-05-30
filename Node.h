//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923
//                                                             //
//-------------------------------------------------------------//



// > Classe Node.h criada em 29/05 por Hermeson Bastos
//
// PONTOS INPORTANTES:
//      - A estrutra do projeto foi criada com base nas
//        atividades anteriores de listas simplesmente 
//        encadeadas e na motivação do problema         
//        disponibilizado pelo professor no Moodle.


#ifndef NODE_H
#define NODE_H
class Node {

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
        };
};


#endif
