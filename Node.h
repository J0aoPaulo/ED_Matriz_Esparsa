// classe Node.h criada em 29/05 por Hermeson Bastos
/*
    Pontos importantes:
        - A estrutra do projeto foi criada com base nas atividades anteriores de listas simplesmente encadeadas e na motivação do problema disponibilizado pelo professor no Moodle.
*/

#ifndef NODE_H
#define NODE_H

using Item = double;

class Node {

    private:
        Node *direita;
        Node *abaixo;
        int linha;
        int coluna;
        Item valor;
    public:
        Node(const Item& val, Node *right = nullptr, Node *down = nullptr){
            valor = val;
            direita = right;
            abaixo = down;
        };
};


#endif
