import java.io.File;
import java.util.List;
import java.util.Scanner;

import classes.Cliente;
import classes.ControleArquivos;

public class App {
	public static void main(String[] args) {
		ControleArquivos controleArquivos = new ControleArquivos();
		File arq = new File("./src/arquivos/operacoes.dat");
		File arqClientes = new File("./src/arquivos/clientes.dat");
		File arqTxt = new File("./src/arquivos/opCliente.txt");
		Scanner scanner = new Scanner(System.in);
		
		while (true) {
			System.out.println("1. Criar novo cliente");
			System.out.println("2. Realizar operacao de compra ou venda");
			System.out.println("3. Ver todas as operacoes");
			System.out.println("4. Ver o total de operacoes por cliente");
			System.out.println("5. Ver as operacoes de um cliente especifico");
			System.out.println("6. Sair");
			System.out.print("Escolha uma opção: ");
			int opcao = scanner.nextInt();
			scanner.nextLine();

			switch (opcao) {
				case 1:
					System.out.print("Digite o nome do cliente: ");
					String nomeCliente = scanner.nextLine();
					Cliente novoCliente = new Cliente(nomeCliente);
					controleArquivos.gravarArquivoClientes(arqClientes, novoCliente);
					System.out.println("\nNovo cliente criado com o codigo: " + novoCliente.getCodigoCliente() + "\n");
					break;
				case 2:
					System.out.print("Digite o codigo do cliente: ");
					int codigoCliente = scanner.nextInt();
					scanner.nextLine();
				
					if (!controleArquivos.clienteExisteArquivo(arqClientes, codigoCliente)) {
							System.out.println("\nCliente nao encontrado!\n");
							break;
					}

					System.out.print("Deseja comprar (C) ou vender (V) um veiculo? ");
					String tipoOperacao = scanner.nextLine();
					tipoOperacao = tipoOperacao.toUpperCase();

					if (!tipoOperacao.equals("C") && !tipoOperacao.equals("V")) {
						System.out.println("Opcao invalida!");
						break;
					}

					System.out.print("Digite o nome do veiculo: ");
					String nomeVeiculo = scanner.nextLine();

					System.out.print("Digite o valor da operacao: ");
					double valorOperacao = scanner.nextDouble();
					scanner.nextLine();

					controleArquivos.gravarArquivoOperacoes(arq, codigoCliente, nomeVeiculo, tipoOperacao, valorOperacao);

					System.out.println("\nOperacao realizada com sucesso!\n");
					break;
				case 3:
					System.out.println("\nLista de operacoes:\n");
					System.out.println(controleArquivos.lerArquivoOperacoes(arq));
					break;
				case 4:
					List<Integer> codigosClientes = controleArquivos.retCodigosClientes(arqClientes);

					for(int cod : codigosClientes) {
						System.out.println("\nCliente: " + cod);

						System.out.println("\nQuantidade compras: ");
						System.out.println(controleArquivos.totalOperacoesCliente(arqClientes, cod, "C"));

						System.out.println("\nQuantidade vendas: ");
						System.out.println(controleArquivos.totalOperacoesCliente(arqClientes, cod, "V"));
					}
					break;
				case 5:
					System.out.print("Digite o codigo do cliente: ");
					String conteudo;
					int codigoClienteOp = scanner.nextInt();
					scanner.nextLine();
				
					if (!controleArquivos.clienteExisteArquivo(arqClientes, codigoClienteOp)) {
						System.out.println("\nCliente nao encontrado!\n");
						break;
					}

					conteudo = controleArquivos.lerArquivoOperacoesCliente(arq, codigoClienteOp);

					System.out.println("\nLista de operacoes do cliente: " + codigoClienteOp);
					System.out.println(conteudo);

					controleArquivos.gravaArqTexto(arqTxt, conteudo);
					System.err.println("Arquivo de texto gerado com as informacoes do cliente");
					break;
				case 6:
					System.out.println("Encerrando o programa...");
					scanner.close();
					return;
				default:
					System.out.println("Opção inválida.");
			}
		}
	}
}
