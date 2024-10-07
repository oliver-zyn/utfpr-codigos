drop TABLE IF EXISTS Emprestimo_Cliente;
drop TABLE IF EXISTS Emprestimos;
drop TABLE IF EXISTS Tipo_Emprestimo;
drop TABLE IF EXISTS Conta_Cliente;
drop TABLE IF EXISTS Conta;
drop TABLE IF EXISTS Tipo_Conta;
drop TABLE IF EXISTS Telefone;
drop TABLE IF EXISTS Clientes;
drop TABLE IF EXISTS Agencia;
drop TABLE IF EXISTS Bancos;
drop TABLE IF EXISTS Cidade;
drop TABLE IF EXISTS Estado;

create TABLE Estado (
	cod_estado int CONSTRAINT pk_cod_estado PRIMARY KEY IDENTITY(1, 1),
  	nome char(2) CONSTRAINT nn_nome_estado NOT NULL,
);

create TABLE Cidade (
	cod_cidade int CONSTRAINT pk_cod_cidade PRIMARY KEY IDENTITY(1, 1),
  	nome varchar(100) CONSTRAINT nn_nome_cidade NOT NULL,
  	cod_estado int CONSTRAINT nn_cod_estado NOT NULL CONSTRAINT fk_cod_estado foreign key references Estado (cod_estado),
);

create TABLE Bancos (
	cod_banco int CONSTRAINT pk_cod_banco PRIMARY KEY IDENTITY(1, 1),
  	nome varchar(100) CONSTRAINT nn_nome_banco NOT NULL,
  	rua varchar(100) CONSTRAINT nn_rua NOT NULL,
  	numero int CONSTRAINT nn_numero NOT NULL,
  	bairro varchar(100) CONSTRAINT nn_bairro NOT NULL,
  	complemento varchar(100),
  	cod_cidade int CONSTRAINT nn_cod_cidade NOT NULL CONSTRAINT fk_cod_cidade_bancos foreign key references Cidade (cod_cidade),
);


create TABLE Agencia (
	num_agencia int CONSTRAINT pk_num_agencia PRIMARY KEY IDENTITY(1, 1),
  	rua varchar(100) CONSTRAINT nn_rua NOT NULL,
  	numero int CONSTRAINT nn_numero NOT NULL,
  	bairro varchar(100) CONSTRAINT nn_bairro NOT NULL,
  	complemento varchar(100),
  	cod_cidade int CONSTRAINT nn_cod_cidade NOT NULL CONSTRAINT fk_cod_cidade_agencia foreign key references Cidade (cod_cidade),
  	cod_banco int CONSTRAINT nn_cod_banco NOT NULL CONSTRAINT fk_cod_banco foreign key references Bancos (cod_banco),
);

create TABLE Clientes (
	cpf bigint CONSTRAINT pk_cpf PRIMARY KEY,
  	nome varchar(100) CONSTRAINT nn_nome_cliente NOT NULL,
  	rua varchar(100) CONSTRAINT nn_rua NOT NULL,
  	numero int CONSTRAINT nn_numero NOT NULL,
  	bairro varchar(100) CONSTRAINT nn_bairro NOT NULL,
  	complemento varchar(100),
  	cod_cidade int CONSTRAINT nn_cod_cidade NOT NULL CONSTRAINT fk_cod_cidade_clientes foreign key references Cidade (cod_cidade),
);

create TABLE Telefone (
	cod_telefone int CONSTRAINT pk_cod_telefone PRIMARY KEY IDENTITY(1, 1),
  	DDD int CONSTRAINT nn_ddd NOT NULL,
  	numero int CONSTRAINT nn_numero NOT NULL,
  	cpf bigint CONSTRAINT nn_cpf NOT NULL CONSTRAINT fk_cpf foreign key references Clientes (cpf),
);

create TABLE Tipo_Conta (
	cod_tipo int CONSTRAINT pk_cod_tipo_conta PRIMARY KEY IDENTITY(1, 1),
  	nome varchar(100) CONSTRAINT nn_nome_tipo_conta NOT NULL,
);

create TABLE Conta (
	num_conta int CONSTRAINT pk_num_conta PRIMARY KEY IDENTITY(1, 1),
  	saldo money CONSTRAINT nn_saldo NOT NULL,
  	cod_tipo int CONSTRAINT fk_cod_tipo_conta foreign key references Tipo_Conta (cod_tipo),
  	num_agencia int CONSTRAINT fk_num_agencia_conta foreign key references Agencia (num_agencia),
);

create TABLE Conta_Cliente (
	num_conta int,
  	cpf bigint,
  	Constraint pk_num_conta_cpf Primary Key(num_conta, cpf), 
    Constraint fk_num_conta Foreign key (num_conta) references Conta(num_conta),
  	Constraint fk_cpf_conta_cliente Foreign key (cpf) references Clientes(cpf),
);

create TABLE Tipo_Emprestimo (
	cod_tipo int CONSTRAINT pk_cod_tipo_emprestimo PRIMARY KEY IDENTITY(1, 1),
  	nome varchar(100) CONSTRAINT nn_nome_tipo_emprestimo NOT NULL,
);

create TABLE Emprestimos (
	num_emp int CONSTRAINT pk_num_emp PRIMARY KEY IDENTITY(1, 1),
  	quantia int CONSTRAINT nn_quantia NOT NULL CONSTRAINT df_quantia DEFAULT 0,
  	cod_tipo int CONSTRAINT fk_cod_tipo_emprestimos foreign key references Tipo_Emprestimo (cod_tipo),
  	num_agencia int CONSTRAINT fk_num_agencia_emprestimos foreign key references Agencia (num_agencia),
);

create TABLE Emprestimo_Cliente (
	num_emp int,
  	cpf bigint,
  	Constraint pk_num_emp_cpf Primary Key(num_emp, cpf),
  	Constraint fk_num_emp Foreign key (num_emp) references Emprestimos(num_emp),
  	Constraint fk_cpf_emprestimo_cliente Foreign key (cpf) references Clientes(cpf),
);

INSERT INTO Estado (nome) VALUES ('SP');
INSERT INTO Estado (nome) VALUES ('RJ');
INSERT INTO Estado (nome) VALUES ('MG');

INSERT INTO Cidade (nome, cod_estado) VALUES ('São Paulo', 1);
INSERT INTO Cidade (nome, cod_estado) VALUES ('Rio de Janeiro', 2);
INSERT INTO Cidade (nome, cod_estado) VALUES ('Belo Horizonte', 3);

INSERT INTO Bancos (nome, rua, numero, bairro, complemento, cod_cidade) VALUES ('Banco do Brasil', 'Av. Paulista', 100, 'Centro', 'Sala 101', 1);
INSERT INTO Bancos (nome, rua, numero, bairro, complemento, cod_cidade) VALUES ('Itaú', 'Av. Presidente Vargas', 500, 'Centro', NULL, 2);
INSERT INTO Bancos (nome, rua, numero, bairro, complemento, cod_cidade) VALUES ('Bradesco', 'Rua da Bahia', 300, 'Funcionários', NULL, 3);

INSERT INTO Agencia (rua, numero, bairro, complemento, cod_cidade, cod_banco) VALUES ('Rua A', 50, 'Centro', NULL, 1, 1);
INSERT INTO Agencia (rua, numero, bairro, complemento, cod_cidade, cod_banco) VALUES ('Rua B', 20, 'Copacabana', 'Sala 102', 2, 2);
INSERT INTO Agencia (rua, numero, bairro, complemento, cod_cidade, cod_banco) VALUES ('Rua C', 150, 'Savassi', NULL, 3, 3);

INSERT INTO Clientes (cpf, nome, rua, numero, bairro, complemento, cod_cidade) VALUES (12345678900, 'João Silva', 'Av. Brasil', 200, 'Centro', NULL, 1);
INSERT INTO Clientes (cpf, nome, rua, numero, bairro, complemento, cod_cidade) VALUES (98765432100, 'Maria Souza', 'Rua Barata Ribeiro', 150, 'Copacabana', NULL, 2);
INSERT INTO Clientes (cpf, nome, rua, numero, bairro, complemento, cod_cidade) VALUES (11122233344, 'José Santos', 'Av. Afonso Pena', 300, 'Funcionários', NULL, 3);

INSERT INTO Telefone (DDD, numero, cpf) VALUES (11, 999999999, 12345678900);
INSERT INTO Telefone (DDD, numero, cpf) VALUES (21, 888888888, 98765432100);
INSERT INTO Telefone (DDD, numero, cpf) VALUES (31, 777777777, 11122233344);

INSERT INTO Tipo_Conta (nome) VALUES ('Corrente');
INSERT INTO Tipo_Conta (nome) VALUES ('Poupança');

INSERT INTO Conta (saldo, cod_tipo, num_agencia) VALUES (1000.00, 1, 1);
INSERT INTO Conta (saldo, cod_tipo, num_agencia) VALUES (500.00, 2, 2);
INSERT INTO Conta (saldo, cod_tipo, num_agencia) VALUES (2000.00, 1, 3);

INSERT INTO Conta_Cliente (num_conta, cpf) VALUES (1, 12345678900);
INSERT INTO Conta_Cliente (num_conta, cpf) VALUES (2, 98765432100);
INSERT INTO Conta_Cliente (num_conta, cpf) VALUES (3, 11122233344);

INSERT INTO Tipo_Emprestimo (nome) VALUES ('Pessoal');
INSERT INTO Tipo_Emprestimo (nome) VALUES ('Empresarial');

INSERT INTO Emprestimos (quantia, cod_tipo, num_agencia) VALUES (5000, 1, 1);
INSERT INTO Emprestimos (quantia, cod_tipo, num_agencia) VALUES (10000, 2, 2);
INSERT INTO Emprestimos (quantia, cod_tipo, num_agencia) VALUES (20000, 1, 3);

INSERT INTO Emprestimo_Cliente (num_emp, cpf) VALUES (1, 12345678900);
INSERT INTO Emprestimo_Cliente (num_emp, cpf) VALUES (2, 98765432100);
INSERT INTO Emprestimo_Cliente (num_emp, cpf) VALUES (3, 11122233344);

SELECT * FROM Estado;

SELECT * FROM Cidade;

SELECT * FROM Bancos;

SELECT * FROM Agencia;

SELECT * FROM Clientes;

SELECT * FROM Telefone;

SELECT * FROM Tipo_Conta;

SELECT * FROM Conta;

SELECT * FROM Conta_Cliente;

SELECT * FROM Tipo_Emprestimo;

SELECT * FROM Emprestimos;

SELECT * FROM Emprestimo_Cliente;


