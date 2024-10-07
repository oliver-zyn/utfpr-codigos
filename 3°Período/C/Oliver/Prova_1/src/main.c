#include <stdio.h>
#include "../include/itemFilaEnc.h"

int exibeMenuUsuario() {
  int opcao = 0;

  printf("\nMenu:\n");
  printf("1. Inserir nova corrida\n");
  printf("2. Remover corrida\n");
  printf("3. Visualizar corridas\n");
  printf("4. Visualizar total de quilometros percorridos\n");
  printf("5. Visualizar total de quilometros percorridos por mes\n");
  printf("6. Sair\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);

  return opcao;
}

void insereCorrida(Fila *f) {
  int idAtleta, dia, mes, ano;
  char dataRegistro[100], rota[100];
  float kmPercorridos;

  printf("\nDigite o numero de identificacao do atleta: ");
  scanf("%d", &idAtleta);
  fflush(stdin);

  printf("Digite o dia do registro: ");
  scanf("%d", &dia);
  fflush(stdin);
  
  printf("Digite o mes do registro (1 - 12): ");
  scanf("%d", &mes);
  fflush(stdin);

  printf("Digite o ano do registro: ");
  scanf("%d", &ano);
  fflush(stdin);

  printf("Digite a quilometragem percorrida: ");
  scanf("%f", &kmPercorridos);
  fflush(stdin);

  printf("Digite a rota realizada: ");
  gets(rota);
  fflush(stdin);

  enfileira(f, idAtleta, dia, mes, ano, kmPercorridos, rota);

  printf("\nCorrida inserida com sucesso!\n");
}

char* retNomeMes(int mes) {
  switch (mes) {
    case 1:
      return "Janeiro";
    case 2:
      return "Fevereiro";
    case 3:
      return "Marco";
    case 4:
      return "Abril";
    case 5:
      return "Maio";
    case 6:
      return "Junho";
    case 7:
      return "Julho";
    case 8:
      return "Agosto";
    case 9:
      return "Setembro";
    case 10:
      return "Outubro";
    case 11:
      return "Novembro";
    case 12:
      return "Dezembro";
    default:
      return "[Nao encontrado]";
  }
}

int main() {
  Fila *f = criaFilaVazia();
  int opcao = 0, mes = 0;
  float kmTotal = 0;

  do {
    opcao = exibeMenuUsuario();

    switch (opcao) {
    case 1:
      insereCorrida(f);
      break;
    case 2:
      desenfileira(f);
      printf("\nCorrida excluida com sucesso!\n");
      break;
    case 3:
      printf("\nCorridas cadastradas: \n");
      imprimeFila(f);
      break;
    case 4:
      kmTotal = calculaTotalKmPercorridosMes(f, 0);

      printf("\nTotal de kms percorridos: %.2f\n", kmTotal);
      break;
    case 5:
      printf("Deseja visualizar o total de corridas de qual mes? (1 - 12): ");
      scanf("%d", &mes);
      fflush(stdin);

      kmTotal = calculaTotalKmPercorridosMes(f, mes);

      if (kmTotal == 0) {
        printf("\nNenhum km foi percorrido no mes de %s\n", retNomeMes(mes));
        break;
      }

      printf("\nTotal de kms percorridos no mes de %s: %.2f\n", retNomeMes(mes), kmTotal);
      break;
    case 6:
      printf("\nSaindo...\n");
      break;
    default:
      printf("\nOpcao invalida!\n");
      break;
    }

  } while (opcao != 6);

  liberaFila(f);

  return 0;
}
