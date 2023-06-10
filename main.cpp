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

std::string matrixExist(std::vector<SparseMatrix*> vector_matrix) {
   if(vector_matrix.empty()) {
      throw std::runtime_error("\n*Nao foi encontrada nenhuma matriz para ser manipulada.*");
   }
   return "\n--- Verificando se matriz existe... ---\n\n--- Matriz verificada e existente! ---\n";
}

int main() {
   // desalocar endereços de memoria
   // complexidade relatorio insert
   std::vector<SparseMatrix*> vec_matrix;
   std::string arquivo_matriz = "matrix.txt";
   int it = 0; // pode melhorar 
   
   int resposta;
   while (resposta != 4) {
      std::cout << "\n ------ Menu de criacao e manipulacao de Matriz Esparsa ------\n";
      std::cout << "\n ----- Selecione uma das alternativas abaixo -----\n";
      std::cout << "1. Criar uma matriz.\n";
      std::cout << "2. Inserir elementos na sua matriz.\n";
      std::cout << "3. Imprimir matriz(es).\n";
      std::cout << "4. Somar matrizes. *em andamento*\n";
      std::cout << "5. Multiplicar matrizes. *em andamento*\n";
      std::cout << "6. Sair. *digite 4 para sair*\n";
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
            delete sparseMatrix;

            cout << "\n--- Matriz criada com sucesso! ---\n";
            break;
         }
         case 2: {
            try { // captura de exceção
               std::cout << matrixExist(vec_matrix);
            } catch(const std::runtime_error& e) {
               std::cout << e.what() << std::endl; // descricao da exceção
               break; // Interrompe o case 3 se a matriz não existir
            }

            int lin, col;
            double value;
            std::cout << "\nDigite a linha que voce ira inserir: ";
            cin >> lin;
            std::cout << "Digite a coluna que voce ira inserir: ";
            std::cin >> col;
            std::cout << "Digite o valor que voce quer inserir na sua matriz: ";
            std::cin >> value;
            vec_matrix[it]->insert(lin, col, value);
            std::cout << "\n--- Elementos inseridos com sucesso na matriz! ---\n";
            it++; // pode ser melhorado || quebra galho
            break;
         }
         case 3: {
            try { // captura de exceção
               std::cout << matrixExist(vec_matrix);
            } catch(const std::runtime_error& e) {
               std::cout << e.what() << std::endl; // descricao da exceção
               break; // Interrompe o case 3 se a matriz não existir
            }

            int x; // variavel com nome fodase,sera mudada depois
            cout << "\nVoce deseja imprimir somente uma matriz ou todas?\n";
            cout << "1. Imprima somente uma.\n";
            cout << "2. Imprima todas as matrizes disponiveis.\n";
            cout << "3. Voltar para o menu.\n";
            cout << "digite sua resposta: ";
            cin >> x;

            if(x == 1) {
               int escolha;
               cout << "Qual matriz voce deseja imprimir? (escolha por ordem de criacao)\n";
               cout << "Matriz: ";
               cin >> escolha;

               if(escolha >= 0 && escolha <= vec_matrix.size()) {
                  // Escolha é diminuida em 1 para entrar nos padroes de indice do vector.
                  escolha--; 
                  std::cout << "\n";
                  vec_matrix[escolha]->print();
               } else {
                  std::cout << "*Matriz invalida ou inexistente.*\n";
               }
               break;
            } else if(x == 2) { 
               std::cout << "\n";
               for (auto &&matrix : vec_matrix) {
                  matrix->print();
                  std::cout << "\n";
               }
               break;
            } else 
               break;
         }
      }
   }
}
