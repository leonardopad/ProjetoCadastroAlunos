#include "funcoes.h"

char menu () {	
	char escolha = ' ';
	std::cout << "\n==SELECIONE UMA OPCAO ABAIXO==";
	std::cout << "\n=========DIGITE A LETRA=======";
	std::cout << "\n========== C - Cadastra Aluno===========";
	std::cout << "\n========== L - Ler o Arquivo de Alunos Aprovados===========";
	std::cout << "\n========== A - Criar arquivo com alunos aprovados===========";
	std::cout << "\n==========F - FINALIZA========\n";
	std::cin >> escolha;
	system("cls");
	return escolha;
}
bool criaArquivoDP1 (Aluno aluno){
	std::ofstream arquivo4;
	arquivo4.open("DepedenciaSegundoSemestre.csv", std::fstream::app);
	
	if(!arquivo4.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}
	
	arquivo4 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << "\n";
			arquivo4.close();
			return true;
	
}
bool criaArquivoDP2 (Aluno aluno){
	std::ofstream arquivo5;
	arquivo5.open("DepedenciaPrimeiroSemestre.csv", std::fstream::app);
	
	if(!arquivo5.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}
	
	arquivo5 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << "\n";
			arquivo5.close();
			return true;
	
}



bool criaArquivoAprovados (Aluno aluno){
	std::ofstream arquivo2;
	arquivo2.open("Aprovados.csv", std::fstream::app);
	
	if(!arquivo2.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}
	
	arquivo2 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
			arquivo2.close();
			return true;
	
}

bool criaArquivoDependencia (Aluno aluno){
	std::ofstream arquivo3;
	arquivo3.open("Dependencia.csv", std::fstream::app);
	
	if(!arquivo3.is_open()){
		std:: cout << "Houve um erro ao abrir o arquivo de criacao da tabela de aprovados";
		return false;
	}
	
	arquivo3 << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
			arquivo3.close();
			return true;
}

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}

void perguntaAluno(Aluno aluno){
	std:: cin.get();//limpar o buffer
	std:: cout << "Digite o nome do aluno: \n";
//	std::getline (std::cin, aluno.nome);
	std:: getline(std::cin, aluno.nome);
	std:: cout << "Digite a matricula do aluno: \n";
	std:: cin >> aluno.matricula;
	std:: cout << "Digite a aep do aluno: \n";
	std:: cin >> aluno.aep1;
	std:: cout << "Digite a prova do primeiro semestre do aluno: \n";
	std:: cin >> aluno.prova1;
	std:: cout << "Digite a aep do segundo semestre do aluno: \n";
	std:: cin >> aluno.aep2;
	std:: cout << "Digite a prova do segundo semestre do aluno: \n";
	std:: cin >> aluno.prova2;
	aluno.media = ((aluno.aep1 + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2)/2);
	if (aluno.media < 6){
		std:: cout << "Digite a nota da substitutiva: \n";
		std:: cin >> aluno.sub;
	}else if(aluno.media >= 6){
		aluno.sub = 0;
		aluno.status = "Aprovado";
	}
	if(aluno.media < 6){
		if ((aluno.prova1 + aluno.aep1) > (aluno.prova2 + aluno.aep2)){
			criaArquivoDP2(aluno);
			aluno.media =((aluno.aep1 + aluno.prova1)/2) + ((aluno.sub + aluno.prova2)/2);
		}else if((aluno.prova2 + aluno.aep2) > (aluno.prova1 + aluno.aep1)){
			aluno.media = ((aluno.sub + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2)/2);
			criaArquivoDP1(aluno);
		}else if((aluno.prova1 + aluno.aep1)  == (aluno.prova2 + aluno.aep2)){
			aluno.media =((aluno.aep1 + aluno.sub)/2) + ((aluno.sub + aluno.prova2)/2);
			criaArquivoDP1(aluno);
		}
	if(aluno.media >= 6){
		aluno.status = "Aprovado";
	}else {
		aluno.status = "Em dependecia";
	}
	}
	if(aluno.media >=6){
		criaArquivoAprovados(aluno);	
	}else if (aluno.media < 6) {
		criaArquivoDependencia(aluno);
	}
	
	//Cria o Arquivo
	if (cadastraAluno(aluno)){
		std::cout << "Aluno cadastrado\n";
	} else {
		std::cout << "Erro ao cadastrar aluno teste\n";
	}
}
bool realizaLeitura(){
		std::ifstream arquivo;
		arquivo.open("database.csv");
		if(!arquivo.is_open()){
			std:: cout << "Falha ao abrir o arquivo!\n";
			return false;
		}
		std:: string linha;
		int indexAlunos = 0;
		while (std::getline(arquivo, linha)){
			int coluna = 0;
			int controleColuna = 0;
			std:: string conteudoLinha = "";
			
			for(int i = 0; i <= linha.size(); i++){
				if(coluna == 1 && controleColuna == 0) {
					alunos[indexAlunos].nome = conteudoLinha;
					conteudoLinha = "";
					controleColuna = 1;
				}
				else if(coluna == 2 && controleColuna == 1){
					alunos[indexAlunos].matricula = conteudoLinha;
					controleColuna = 2;
				}
//				else if(coluna == 3 && controleColuna == 2){
//					alunos[indexAlunos].aep1 = conteudoLinha;
//					controleColuna = 3;
//				}
				if(linha[i] == ';'){
					coluna++;
					continue;
				}
				
			}
			indexAlunos++;
		}
		arquivo.close();
	//tentativa1	
	for (int i = 0; i < 100; i++) {
	std::cout << "Aluno n-" << i+1 << "\n";
	std::cout << "Nome: " << alunos[i].nome << "\n";
	std::cout << "Matricula: " << alunos[i].matricula << "\n";
	std:: cout << "AEP1: " << alunos[i].aep1 << "\n";
	}	
	return true;
}
	



