//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923             //
//                                                             //
//-------------------------------------------------------------//

#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>

SparseMatrix* readSparseMatrix(std::string matrix) {
   std::ifstream input_arquivo("matrix.txt");

   if(!input_arquivo.is_open()) {
      std::cout << "Erro ao abrir o arquivo de entrada, tente novamente." << std::endl;
      return nullptr;
   }

   int numLin, numCol;
   input_arquivo >> numLin >> numCol;

   SparseMatrix* read_matrix = new SparseMatrix(numLin, numCol);

   int lin, col, value;
   while (input_arquivo >> lin >> col >> value) {
      read_matrix->insert(lin, col, value);
   }
   
   input_arquivo.close();

   return read_matrix;
}

int main() {
   std::vector<SparseMatrix*> vec_matrix;
   std::string arquivo_matriz = "matrix.txt";

   
   int resposta;
   while (resposta != 4) {
      std::cout << "\n ----- Selecione uma das alternativas abaixo -----\n";
      std::cout << "1. Criar uma matriz\n";
      std::cout << "2. Inserir elementos na sua matriz\n";
      std::cout << "3. Imprimir uma matriz\n";
      std::cout << "4. Imprimir matriz(es)\n";
      std::cout << "5. Sair\n";
      std::cout << "digite sua resposta: ";
      std::cin >> resposta;

      switch (resposta) {
         case 1: {
            int numLin, numCol;
            cout << "\nInforme o numero de linhas da sua matriz: ";
            cin >> numLin;
            cout << "Agora informe o numero de colunas da sua matriz: ";
            cin >> numCol;

            if(numLin == 0 || numCol == 0) {
               cout << "\n-- Matriz invalida, por favor tente novamente. --\n";
               cout << "\nDica: A definicao de uma matriz requer pelo menos uma linha e uma coluna para ter algum tipo de conteudo. Uma matriz sem elementos nao faz sentido, pois nao existem dados para armazenar ou acessar.\n";
               break;
            }
            SparseMatrix *sparseMatrix = new SparseMatrix(numLin, numCol);
            vec_matrix.push_back(sparseMatrix);

            cout << "\n--- Matriz criada com sucesso! ---\n";
            break;
         }
         case 2: {
            int lin, col;
            double value;
            std::cout << "Digite a linha que voce ira inserir: ";
            cin >> lin;
            std::cout << "Digite a coluna que voce ira inserir: ";
            std::cin >> col;
            std::cout << "Digite o valor que voce quer inserir na sua matriz:";
            std::cin >> value;
            vec_matrix[0]->insert(lin, col, value);
            std::cout << "\n--- Elementos inseridos com sucesso na matriz! ---\n";
            break;
         }
         case 3: {
            vec_matrix[0]->insert(3, 3, 9); //
            vec_matrix[0]->insert(2, 4, 9); //
            vec_matrix[0]->insert(1, 3, 9); //
            vec_matrix[0]->insert(1, 1, 9); //
            vec_matrix[0]->insert(1, 2, 9); //
            vec_matrix[0]->insert(2, 3, 0); //
            vec_matrix[0]->insert(3, 4, 9); //
            vec_matrix[0]->insert(3, 2, 9); //
            vec_matrix[0]->insert(1, 4, 9); //
            vec_matrix[0]->insert(2, 1, 9); //
            vec_matrix[0]->insert(2, 2, 9); //
            vec_matrix[0]->insert(3, 1, 9); //

            cout << vec_matrix[0]->get(1, 1);
            cout << vec_matrix[0]->get(1, 2); //
            cout << vec_matrix[0]->get(1, 3); //
            cout << vec_matrix[0]->get(1, 4) << endl; //
            cout << vec_matrix[0]->get(2, 1); //
            cout << vec_matrix[0]->get(2, 2); //
            cout << vec_matrix[0]->get(2, 3);
            cout << vec_matrix[0]->get(2, 4) << endl;
            cout << vec_matrix[0]->get(3, 1); //
            cout << vec_matrix[0]->get(3, 2); //
            cout << vec_matrix[0]->get(3, 3); //
            cout << vec_matrix[0]->get(3, 4); //
         }
      }
   }
}