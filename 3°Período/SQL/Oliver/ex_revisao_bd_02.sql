drop TABLE IF EXISTS Empregado_Projeto;
drop TABLE IF EXISTS Empregado;
drop TABLE IF EXISTS Dependentes;
drop TABLE IF EXISTS Departamento_Projeto;
drop TABLE IF EXISTS Departamento;
drop TABLE IF EXISTS Projeto;

create TABLE Departamento (
  	num_depto int CONSTRAINT pk_num_depto PRIMARY KEY IDENTITY(1, 1),
	nome varchar(100) CONSTRAINT nn_nome_depto NOT NULL,
  	rg_gerente bigint CONSTRAINT nn_rg_gerente_depto NOT NULL,
);

CREATE TABLE Projeto (
  	num_projeto int CONSTRAINT pk_num_projeto PRIMARY KEY,
	nome varchar(100) CONSTRAINT nn_nome_projeto NOT NULL,
  	localizacao varchar(100) CONSTRAINT nn_localizacao NOT NULL,
);

CREATE TABLE Departamento_Projeto (
  	num_depto int,
  	num_projeto int,
  	Constraint pk_num_depto_projeto Primary Key(num_depto, num_projeto), 
    Constraint fk_num_depto Foreign key (num_depto) references Departamento(num_depto),
  	Constraint fk_num_projeto Foreign key (num_projeto) references Projeto(num_projeto),
);

create TABLE Dependentes (
	rg_responsavel bigint,
  	nome_dependente varchar(100),
  	relacao varchar(100) CONSTRAINT nn_relacao NOT NULL,
  	sexo varchar(100) CONSTRAINT nn_sexo NOT NULL,
   	Constraint pk_rg_nome_dependente Primary Key(rg_responsavel, nome_dependente),
);

create TABLE Empregado (
	rg bigint CONSTRAINT pk_rg_empregado PRIMARY KEY,
  	nome varchar(100) CONSTRAINT nn_nome_empregado NOT NULL,
  	cpf bigint CONSTRAINT nn_cpf_empregado NOT NULL,
  	depto int CONSTRAINT nn_depto_empregado NOT NULL CONSTRAINT fk_depto_empregado foreign key references Departamento (num_depto),
  	rg_supervisor bigint,
  	salario money NOT NULL,
);

CREATE TABLE Empregado_Projeto (
	rg_empregado bigint CONSTRAINT pk_rg_empregado_projeto PRIMARY KEY,
  	num_projeto int CONSTRAINT nn_num_projeto NOT NULL CONSTRAINT fk_num_projeto_empregado_projeto foreign key references Projeto (num_projeto),
  	horas int CONSTRAINT nn_horas NOT NULL,
);


