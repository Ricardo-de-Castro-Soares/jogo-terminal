#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int zumbiAtaque1(int forca_zumbi1)
{
	int ataque_zumbi1{};
	
	ataque_zumbi1 = forca_zumbi1 + (rand() % 6) + 1;
	
	return ataque_zumbi1;
}

int main()
{
	srand(time(0));
	
	string nome_personagem;
	const int classeArmadura_personagem = 10, classeArmadura_zumbi1 = 8, forca_zumbi1 = 14, destreza_zumbi1 = 4;
	bool inicioDojogo = false;
	int opcao{}, vida_personagem = 10, vida_zumbi1 = 8, progresso{}, escolha{};
	int dano_zumbi1 = zumbiAtaque1(forca_zumbi1);
	char opcao2;
	double forca_personagem{}, destreza_personagem{}, defesa_personagem{};
	
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
		
		switch(opcao){// switch com 2 opções, entrar no jogo e sair do jogo
			case 1:
				cin.ignore();
				system("cls");
				
				vida_zumbi1 = 8;
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
						case 1:// Distribui 2 atributos aleatorios sendo que o usuario possui 3 tentativas 
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
												
				if(inicioDojogo == true){// Entra no jogo e montra os atributos gerados aleatorios aceito pelo usuario
					cout<<"\n======= ESSES SERÃO SEU NOME E ATRIBUTOS =======\n";
					cout<<"\nNome do personagem: "<<nome_personagem;
					cout<<"\nForça: "<<forca_personagem;
					cout<<"\nDestreza: "<<destreza_personagem;
					cout<<"\nClasse de Armadura: "<<classeArmadura_personagem; cout<<"\n\n";
					
					system("pause");
					system("cls");
					
					while(vida_personagem > 0){// aqui é onde vai sempre verificar se a vida do personagem estar abaixo de 0 sendo sua vida maxima 10
						if(progresso == 0){
							cout<<"Você esta no portão da cidade e tem dois caminhos...\n\n";
							system("pause");
							system("cls");
							
							cout<<"Escolha um caminho [1 Floresta/ 2 Planíce]: ";
							cin>>escolha;
							
							if(escolha == 1) progresso = 1;
							if(escolha == 2) progresso = 2;
							
						}else if(progresso == 1){
							cout<<"Você chegou na floresta, e de repente aparece 2 zumbi e não a mais como voltar atrás, um dos zumbi te da um golpe...\n\n";
							
							while(vida_zumbi1 > 0 && vida_personagem > 0){
								defesa_personagem = classeArmadura_personagem + (rand() % 20) + 1;
								dano_zumbi1 = zumbiAtaque1(forca_zumbi1);
								
								if(dano_zumbi1 > defesa_personagem){
									vida_personagem = vida_personagem - dano_zumbi1;
									if(vida_personagem < 0) vida_personagem = 0;
								
									cout<<"VOCÊ TOMOU DANO... - "<<vida_personagem<<" DE VIDA";
									
									system("pause");
									
									//if()//apenas para saber de onde vou continuar o codigo
								}else{
									system("cls");
								
									cout<<"\nO zumbi errou...";
								
									cout<<"\nde um contra ataque";//(cin) apenas para parar o loop
									cin>>escolha;
								}
							}
						}
					}
				}
				break;
				
			case 2:
				system("cls");
				cout<<"\nAté !!\n\n";
				system("pause");
				break;		
			}
	}while(opcao != 2);
	
		
	return 0;
}
