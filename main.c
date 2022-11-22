#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
  int caloriaDia, cardapio;
}
Alimentacao;

typedef struct {
  int id, idade;
  char cpf[50], nome[50], email[50], sexo;
  float altura, peso, imc;
  Alimentacao Alimentacao;
}
Cliente;

typedef struct {
  int idade, telefone;
  char cpf[50], nome[50], email[50], sexo;
  float salario;
}
Funcionario;

void Cabecalho() {
  printf("---------------------------------------------------------------------------------------------------------------------\n");
  printf("                                                 Fast Diet                                                     \n");
  printf("---------------------------------------------------------------------------------------------------------------------\n");
}

Cliente CadastroCliente() {
  fflush(stdin);
  char cpfNovo[50], nomeNovo[50], emailNovo[50];
  Cliente clienteNovo;
  system("cls");
  Cabecalho();
  printf("### Menu de Cadastro Cliente ###\n");
  printf("Insira suas informa��es de acordo com o pedido: \n");
  printf("------------------------------------------------\n");
  printf("Informe seu cpf |sem pontuacoes|: \n");
  gets(cpfNovo);
  strncpy(clienteNovo.cpf, cpfNovo, 50);
  fflush(stdin);
  printf("Informe seu nome: \n");
  fflush(stdin);
  gets(nomeNovo);
  strncpy(clienteNovo.nome, nomeNovo, 50);
  printf("Informe sua idade: \n");
  scanf("%d", & clienteNovo.idade);
  while (clienteNovo.idade <= 0 || clienteNovo.idade > 130) {
    printf("Idade inv�lida informada, informe novamente: \n");
    scanf("%d", & clienteNovo.idade);
  }
  fflush(stdin);
  printf("Informe seu email: \n");
  gets(emailNovo);
  strncpy(clienteNovo.email, emailNovo, 50);
  fflush(stdin);
  printf("informe seu sexo |'M' ou 'F'|: \n");
  scanf("%c", & clienteNovo.sexo);
  clienteNovo.sexo = toupper(clienteNovo.sexo);
  while (clienteNovo.sexo != 'M' && clienteNovo.sexo != 'F') {
    printf("Sexo invalido informado, informe novamente: \n");
    scanf("%c", & clienteNovo.sexo);
    fflush(stdin);
  }
  fflush(stdin);
  printf("Informe seu peso: \n");
  scanf("%f", & clienteNovo.peso);
  while (clienteNovo.peso <= 0) {
    printf("Peso inv�lido informado, informe novamente: ");
    scanf("%f", & clienteNovo.peso);
  }
  printf("Informe sua altura |em cm|: \n");
  scanf("%f", & clienteNovo.altura);
  while (clienteNovo.altura <= 0 || clienteNovo.altura > 300) {
    printf("Altura inv�lida, informe novamente em m: ");
    scanf("%f", & clienteNovo.altura);
    clienteNovo.altura = clienteNovo.altura / 100;
  }
  clienteNovo.id = 1;
  fflush(stdin);
  clienteNovo.imc = clienteNovo.peso / pow(1.73, 2);
  printf("IMC Definido como: %.2f \n", clienteNovo.imc);
  Pause();
  Cabecalho();
  if (clienteNovo.imc < 18.5) {
    printf("----------------------------------------------------------------------------\n");
    printf("Voce esta se sentindo bem? mas cuidado. Voce se encontra abaixo do peso! \n");
    printf("Seu cardapio foi definido como tipo 1 \n");
    clienteNovo.Alimentacao.cardapio = 1;

  } else if (clienteNovo.imc < 30) {
    printf("----------------------------------------------------------------------------\n");
    printf("Parebenssss, voce esta em seu peso ideal. Mas nao deixe de se cuidar! \n");
    printf("Seu cardapio foi definido como tipo 2 \n");
    clienteNovo.Alimentacao.cardapio = 2;
  } else {
    printf("----------------------------------------------------------------------------\n");
    printf("Voce esta se sentindo bem? Cuidado, voce se encontra acima do peso! \n");
    printf("Seu cardapio foi definido como tipo 3 \n");
    clienteNovo.Alimentacao.cardapio = 3;
  }
  if (clienteNovo.sexo == 'M') {
    clienteNovo.Alimentacao.caloriaDia = (66.5 + ((clienteNovo.altura * 100) * 5) + (13.8 * clienteNovo.peso) - (6.8 * clienteNovo.idade)) / 100;
    clienteNovo.Alimentacao.caloriaDia = clienteNovo.Alimentacao.caloriaDia * 1.55;
    printf("----------------------------------------------------------------------------\n");
    printf("Sua taxa de consumo foi calculada e definica como: %d kcal por dia\n", clienteNovo.Alimentacao.caloriaDia);
    printf("Para manter-se em forma, coma o quanto voce gasta (taxa calculada) diariamente.\n");
    printf("Caso queira emagrecer coma 300g a menos, e se quiser engordar 300g a mais.\n");
    printf("# LEMBRETE # Nosso app n�o substitui um acompanhamento profissional, mas ajuda a iniciar um processo de vida saudavel!\n");
    printf("----------------------------------------------------------------------------\n");
  } else if (clienteNovo.sexo == 'F') {
    clienteNovo.Alimentacao.caloriaDia = (665.1 + (1.8 * (clienteNovo.altura * 100)) + (9.5 * clienteNovo.peso) - (4.7 * clienteNovo.idade)) / 100;
    clienteNovo.Alimentacao.caloriaDia = clienteNovo.Alimentacao.caloriaDia * 1.55;
    printf("----------------------------------------------------------------------------\n");
    printf("Sua taxa de consumo foi calculada e definica como: %d kcal por dia\n", clienteNovo.Alimentacao.caloriaDia);
    printf("Para manter-se em forma, coma o quanto voce gasta (taxa calculada) diariamente.\n");
    printf("Caso queira emagrecer coma 300g a menos, e se quiser engordar 300g a mais.\n");
    printf("# LEMBRETE # Nosso app n�o substitui um acompanhamento profissional, mas ajuda a iniciar um processo de vida saudavel!c\n");
    printf("----------------------------------------------------------------------------\n");
  }
  return clienteNovo;
}

void FazerLogin() {
  char login[15] = "admin", login1[15], senha[15] = "admin", senha1[15];
  do {
    Cabecalho();
    printf("\n ### Login Fast Diet ### \n");
    printf("\nUsu�rio: ");
    scanf("%s", login1);
    printf("Senha: ");
    scanf("%s", senha1);
    if (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0) {
      system("cls");
      Cabecalho();
      printf("\nLogin ou Senha inv�lido, tente novamente!");
      printf("\n## Tente Novamente ##\n");
      Pause();
    } else {
      printf("\nLogin efetuado com sucesso! \n\n");
    }
  } while (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0);
  Pause();
}

void Pause() {
  system("pause");
  system("cls");
}

void main() {
  setlocale(LC_ALL, "Portuguese");
  int escolha, op, i;
  Cliente ListaClientes[20];
  Funcionario ListaFuncionarios[10];
  do {
    Cabecalho();
    printf("Bem vindo a Fast Diet\n");
    system("pause");
    system("cls");
    fflush(stdin);
    FazerLogin();
    Cabecalho();
    printf("Escolha a area que deseja utilizar: \n");
    printf("[0]Fechar \n[1]Funcionarios \n[2]Clientes \n");
    scanf("%d", & escolha);
    while (escolha < 0 || escolha > 2) {
      printf("Op��o invalida, escolha entre [0], [1] ou [2]: \n");
      scanf("%d", & escolha);
    }
    switch (escolha) {
    case 1:
      do {
        printf("## FUNCIONARIO ##");
        Pause();
        //seu swicht
        //tudo dentro do while
        //op 0 para sair
      } while (op != 0);
      break;
    case 2:
      do {
        system("cls");
        fflush(stdin);
        Cabecalho();
        printf(" ### Menu inicial Cliente ### \n");
        printf("O que voce gostaria de realizar: \n");
        printf("[0]Voltar \n[1]Cadastrar Cliente \n[2]Localizar Cliente \n");
        printf("[3]Editar Cliente \n[4]Relatorio de Clientes \n[5]Ver Cardapio\n");
        printf("[6]Relatorio de dados (clientes) \n");
        scanf("%d", & op);
        while (op < 0 || op > 6) {
          printf("Opcao invalida, insira outro valor: ");
          scanf("%d", & op);
        }
        switch (op) {
        case 0:
          printf("Voltando ao menu anterior!");
          system("pause");
          break;
        case 1:
          ;
          Cliente clienteCadastrado;
          clienteCadastrado = CadastroCliente();
          for (int i = 0; i < 10; i++) {
            if (ListaClientes[i].id != 1) {
              ListaClientes[i] = clienteCadastrado;
              i = 1002;
            }
          }
          printf("Cliente cadastrado com sucesso.\n");
          Pause();
          break;
        case 2:
          fflush(stdin);
          system("cls");
          Cabecalho();
          char cpf[50];
          int i, achou = 0;
          printf("Informe o 'CPF' do Cliente que deseja encontrar: \n");
          gets(cpf);
          fflush(stdin);
          for (i = 0; i <= 10; i++) {
            if (strcmp(ListaClientes[i].cpf, cpf) == 0) {
              fflush(stdin);
              printf("### Cliente encontrado ### \n");
              printf("Nome: %s\n", & ListaClientes[i].nome);
              printf("CPF: %s\n", & ListaClientes[i].cpf);
              printf("Sexo: %s\n", & ListaClientes[i].sexo);
              printf("Email: %s\n", & ListaClientes[i].email);
              printf("Idade: %d\n", ListaClientes[i].idade);
              achou = 1;
              Pause();
            }
          }
          if (achou == 0) {
            printf("Cliente n�o cadastrado/encontrado, tente novamente: \n");
            Pause();
          }
          break;
        case 3:
          fflush(stdin);
          system("cls");
          Cabecalho();
          char cpf1[50];
          int opc;
          achou = 0;
          printf("Informe o 'CPF' do Cliente que deseja encontrar e editar: \n");
          gets(cpf1);
          fflush(stdin);
          for (i = 0; i <= 10; i++) {
            if (strcmp(ListaClientes[i].cpf, cpf1) == 0) {
              fflush(stdin);
              printf("### Cliente encontrado ### \n");
              printf("Nome: %s\n", & ListaClientes[i].nome);
              printf("CPF: %s\n", & ListaClientes[i].cpf);
              printf("Sexo: %s\n", & ListaClientes[i].sexo);
              printf("Email: %s\n", & ListaClientes[i].email);
              printf("Idade: %d\n", ListaClientes[i].idade);
              achou = 1;
              printf("Deseja alterar qual dado do cliente: \n[1]Nenhum \n[2]Nome \n[3]Email \n[4]Idade \n");
              scanf("%d", & opc);
              while (opc < 1 || opc > 4) {
                printf("Valor inv�lido digitado, informe um valor entre [1] e [4] \n");
                scanf("%d", & opc);
              }
              if (opc == 2) {
                fflush(stdin);
                system("cls");
                Cabecalho();
                printf("### Alterar Nome ### \n");
                char nome[50];
                printf("Informe o novo nome do cliente: \n");
                gets(ListaClientes[i].nome);
                printf("Nome alterado com sucesso!!\n");
              } else if (opc == 3) {
                fflush(stdin);
                system("cls");
                Cabecalho();
                printf("### Alterar Email ### \n");
                char email[50];
                printf("Informe o novo nome do cliente: \n");
                gets(ListaClientes[i].email);
                printf("Email alterado com sucesso!!\n");
              } else if (opc == 4) {
                fflush(stdin);
                system("cls");
                Cabecalho();
                printf("### Alterar Idade ### \n");
                int novaIdade;
                printf("Informe o novo nome do cliente: \n");
                scanf("%d", & ListaClientes[i].idade);
                printf("Idade alterada com sucesso!!\n");
              } else {
                fflush(stdin);
                system("cls");
                Cabecalho();
                printf("Muito obrigado, voltaremos ao menu!\n");
              }
              Pause();
            }
          }
          if (achou == 0) {
            system("cls");
            Cabecalho();
            printf("Cliente n�o cadastrado/encontrado, tente novamente: \n");
            Pause();
          }
          break;
          break;
        case 4:
          system("cls");
          fflush(stdin);
          Cabecalho();
          i = 0;
          int clientes = 0;
          printf("Lista de todos clientes: \n");
          fflush(stdin);
          while (ListaClientes[i].id == 1) {
            printf("Nome: %s\n", & ListaClientes[i].nome);
            printf("Idade: %d\n", ListaClientes[i].idade);
            printf("Email: %s\n", & ListaClientes[i].email);
            printf("-----------------------------------\n");
            i++;
            clientes = 1;
          }
          if (clientes == 0) {
            printf("N�o existem clientes cadastrados no momomento, \n");
          }
          Pause();
          break;
        case 5:
          fflush(stdin);
          system("cls");
          Cabecalho();
          printf("## Encontrar seu CARDAPIO ## \n");
          char cpfCardapio[50];
          achou = 0;
          printf("Informe o 'CPF' do Cliente que deseja encontrar: \n");
          gets(cpfCardapio);
          fflush(stdin);
          for (i = 0; i <= 10; i++) {
            if (strcmp(ListaClientes[i].cpf, cpfCardapio) == 0) {
              fflush(stdin);
              printf("### Cliente encontrado ### \n");
              printf("Nome: %s\n", & ListaClientes[i].nome);
              printf("Email: %s\n", & ListaClientes[i].email);
              printf("Calorias diarias: %d\n", ListaClientes[i].Alimentacao.caloriaDia);
              if (ListaClientes[i].Alimentacao.cardapio == 1) {
                printf("\n");
                printf("### Seu cardapio � do tipo 1 ### \n");
                printf("Ingredientes que indicamos: \n");
                printf("- Batata Doce | 200g/dia \n");
                printf("- Peixe Empanado | 300g/dia \n");
                printf("- Carne Vermelha | 500g/dia \n");
                printf("---------------------------------\n");
                printf("Ingredientes Contraindicados: \n");
                printf("- Amendoim (no geral) \n");
                printf("- Industrializados em excesso \n");
                printf("- Sucos 'de saquinho' \n");
                printf("---------------------------------\n");
              } else if (ListaClientes[i].Alimentacao.cardapio == 2) {
                printf("\n");
                printf("### Seu cardapio � do tipo 2 ###\n");
                printf("Ingredientes que indicamos: \n");
                printf("- Massas | 400g/dia \n");
                printf("- Vegetais no geral | 200g/dia \n");
                printf("- Carne Vermelha | 500g/dia \n");
                printf("---------------------------------\n");
                printf("Ingredientes Contraindicados: \n");
                printf("- Miojos \n");
                printf("- Alcool (em excesso) \n");
                printf("- Sucos 'de saquinho' \n");
                printf("---------------------------------\n");
              } else if (ListaClientes[i].Alimentacao.cardapio == 3) {
                printf("\n");
                printf("### Seu cardapio � do tipo 3 ###\n");
                printf("Ingredientes que indicamos: \n");
                printf("- Frutas (todas) | SemTotal/dia \n");
                printf("- Vegetais no geral | 200g/dia \n");
                printf("- Carne Vermelha | 250g/dia \n");
                printf("---------------------------------\n");
                printf("Ingredientes Contraindicados: \n");
                printf("- Miojos \n");
                printf("- Alcool (em excesso) \n");
                printf("- Industrializados \n");
                printf("---------------------------------\n");
              }
              achou = 1;
              i = 200;
              Pause();
            }
          }
          if (achou == 0) {
            printf("Cliente n�o cadastrado/encontrado, tente novamente! \n");
            Pause();
          }
          break;
        case 6:
          system("cls");
          Cabecalho();
          int qtdMulheres = 0, QtdHomens = 0, totalclientes = 0, idadeMedia = 0;
          float imcMedio = 0;
          i = 0;
          while (ListaClientes[i].id == 1) {
            idadeMedia = ListaClientes[i].idade + idadeMedia;
            imcMedio = ListaClientes[i].imc + imcMedio;
            if (ListaClientes[i].sexo == 'F') {
              qtdMulheres++;
            }
            if (ListaClientes[i].sexo == 'M') {
              QtdHomens++;
            }
            totalclientes++;
            i++;
          }
          if (idadeMedia == 0) {
            printf("N�o existem clientes cadastrados!! \n");
            system("pause");
          } else {
            printf("------------------------------------------------------------------------\n");
            printf("O total de clientes (cadastrados) � de %d cliente(s) \n", totalclientes);
            printf("------------------------------------------------------------------------\n");
            printf("A media de idade dos clientes �: %d \n", idadeMedia / totalclientes);
            printf("------------------------------------------------------------------------\n");
            printf("A media de IMC dos clientes �: %.2f \n", imcMedio / totalclientes);
            printf("------------------------------------------------------------------------\n");
            printf("Sendo aproximadamente %d� mulhere(s) \n", qtdMulheres);
            printf("------------------------------------------------------------------------\n");
            printf("Sendo aproximadamente %d� homen(s) \n", QtdHomens);
            printf("------------------------------------------------------------------------\n");
            Pause();
          }
          break;
        default:
          break;
        }
      } while (op != 0);
      break;
    default:
      printf("O programa ira finalizar!");
      Pause();
      break;
    }
  } while (escolha != 0);
}
