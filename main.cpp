#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	
	string nome_personagem;
	bool inicioDojogo = false;
	int opcao{}, vida_personagem = 10, perdendo_vida{};
	char opcao2;
	double forca_personagem{}, destreza_personagem{};
	
	do{
		cout<<"\n=== MENU ===\n";
		cout<<"\n[1] Iniciar Jogo";
		cout<<"\n[2] Sair";
		cout<<"\nEscolha uma opção: ";
		cin>>opcao;
		
		system("cls");
		if(opcao < 1 || opcao > 2){
			cout<<"\nOpcão invalida!! Digite entre [1 e 2]\n";
		}
		
		switch(opcao){
			case 1:
				cin.ignore();
				system("cls");
				
				vida_personagem = 10;
				inicioDojogo = false;
				
				cout<<"Bem vindo, ao meu primeiro jogo via terminal, esse jogo é um rpg baseado em D&D onde você só podera jogar como guerreiro.\n\n";
				system("pause");
				system("cls");
				
				cout<<"Digite o nome do seu personagem: ";
				getline(cin, nome_personagem);
				system("cls");
				
				for(int i = 1; i <= 3 && inicioDojogo == false; i++){
				cout<<"\n===== DISTRIBUIÇÃO DE ATRIBUTOS =====\n\n"; cout<<"["<<i<<" de "<<" 3]\n";
				forca_personagem = (rand() % 16) + 3;
				destreza_personagem = (rand() % 16) + 3;
				
				cout<<"\nForça: "<<forca_personagem;
				cout<<"\nDestreza: "<<destreza_personagem;
				
					switch(i){
						case 1:
							cout<<"\n\nDeseja continuar com esses atributos? [S/N]: ";
							cin>>opcao2;
							if(opcao2 == 'S' || opcao2 == 's'){
								inicioDojogo = true;
								system("pause");
								break;
							}else{
								continue;
							}
							break;
						case 2:
							cout<<"\n\nDeseja continuar com esses atributos? A PROXIMA RODADA DE DADOS SERÁ A ULTIMA [S/N]: ";
							cin>>opcao2;
							if(opcao2 == 'S' || opcao2 == 's'){
								inicioDojogo = true;
								system("pause");
								break;
							}else{
								continue;
							}
							break;
						case 3:
							if(inicioDojogo == false){
								inicioDojogo = true;
								cout<<"\n\n";
								system("pause");
								break;	
							}
						}	
					}
					
					system("cls");
												
				if(inicioDojogo == true){
					cout<<"\n======= ESSES SERÃO SEU NOME E ATRIBUTOS =======\n";
					cout<<"\nNome do personagem: "<<nome_personagem;
					cout<<"\nForça: "<<forca_personagem;
					cout<<"\nDestreza: "<<destreza_personagem; cout<<"\n\n";
					
					system("pause");
					system("cls");
					
					while(vida_personagem > 0){
						cout<<"Escolha um caminho [1 Floresta/ 2 Cidade]: ";
						cin>>perdendo_vida;
						switch(perdendo_vida){//esse blocofoi apenas um teste
							case 1:
								vida_personagem = 0;
								cout<<"Você morreu!!\n\n";
								system("pause");							
								break;
							case 2:
								cout<<"Você chegou na cidade\n\n";
								system("pause");
							break;
						}
					}
				}
				break;
				
			case 2:
				system("cls");
				cout<<"\nAté logo!!\n\n";
				system("pause");
				break;		
			}
	}while(opcao != 2);
	
		
	return 0;
}
