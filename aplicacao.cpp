#include "funcoes.cpp"

int main () {
	char opcao = ' ';
	int QTSALUNOS = 1;
	char continuar = ' ';
	Aluno aluno[50];
	do {
	   opcao = menu();	
	   switch (opcao) {
//	   		case 'T':
//	   			teste();
//	   		break;
	   		case 'C':
	   			for(int i = 0; i <= QTSALUNOS; i++){
	   					perguntaAluno(aluno[i]);
				    std:: cout << "Deseja continuar?/nDigite S para sim e N para nao!\n";
					std:: cin >> continuar;
					if(continuar == 'S'){
						QTSALUNOS + 1;
					}else if(continuar == 'N'){
						break;
					}else{
						std:: cout << "Digite uma opcao valida!";
					}	
				   } 
	   		break;
	   		case 'F':
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		case 'L':
	   			realizaLeitura();
	   			break;
	   		// demais funcoes dever�o ser chamadas aqui
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != 'F');	
}