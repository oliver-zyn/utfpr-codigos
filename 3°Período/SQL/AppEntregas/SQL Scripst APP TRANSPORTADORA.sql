USE TransportApp;
go

-- Alunos: Pedro Henrique Sauthier - 2562510
-- Oliver Lohann Mayer - 2562502

-- EXCLUSAO

DROP TABLE IF EXISTS PACOTES_ENTREGADORES;
DROP TABLE IF EXISTS PACOTES_SITUACOES;
DROP TABLE IF EXISTS PACOTES;
DROP TABLE IF EXISTS ENTREGADORES;
DROP TABLE IF EXISTS DESTINATARIOS;
DROP TABLE IF EXISTS CIDADES;
DROP TABLE IF EXISTS ESTADOS;
DROP TABLE IF EXISTS SITUACOES;
DROP TABLE IF EXISTS USUARIOS;

-- CREATES

CREATE TABLE USUARIOS (
	usuario_id INT IDENTITY(1,1) CONSTRAINT pk_usuarios PRIMARY KEY,
	cpf BIGINT CONSTRAINT nn_cpf_usuarios NOT NULL UNIQUE,
	senha VARCHAR(100) CONSTRAINT nn_senha_usuarios NOT NULL,
	usuario_admin TINYINT CONSTRAINT nn_usuario_admin NOT NULL,
);

CREATE TABLE SITUACOES (
	situacao_id INT IDENTITY(1,1) CONSTRAINT pk_situacoes PRIMARY KEY,
	descricao VARCHAR(10) CONSTRAINT nn_descricao NOT NULL, 
);

CREATE TABLE ESTADOS (
	estado_id INT IDENTITY(1,1) CONSTRAINT pk_estados PRIMARY KEY,
	nome VARCHAR(50) CONSTRAINT nn_nomeEs NOT NULL,
);

CREATE TABLE CIDADES (
	cidade_id INT IDENTITY(1,1) CONSTRAINT pk_cidades PRIMARY KEY,
	nome VARCHAR(50) CONSTRAINT nn_nomeCi NOT NULL,
	estado_id INT CONSTRAINT fk_estado_cidade FOREIGN KEY REFERENCES ESTADOS(estado_id) CONSTRAINT nn_estado_id NOT NULL,
);

CREATE TABLE DESTINATARIOS (
	destinatario_id INT IDENTITY(1,1) CONSTRAINT pk_destinatarios PRIMARY KEY,
	nome VARCHAR(100) CONSTRAINT nn_nome_destinatarios NOT NULL,
	cpf BIGINT CONSTRAINT nn_cpf_destinatarios NOT NULL UNIQUE,
	telefone VARCHAR(25) CONSTRAINT nn_telefone_destinatarios NOT NULL,
	rua VARCHAR(100) CONSTRAINT nn_rua_destinatarios NOT NULL,
	bairro VARCHAR(100) CONSTRAINT nn_bairro_destinatarios NOT NULL,
	numero INT CONSTRAINT nn_numero_destinatarios NOT NULL,
	complemento VARCHAR(100),
	cep BIGINT CONSTRAINT nn_cep_destinatarios NOT NULL,
	cidade_id INT CONSTRAINT fk_dest_cidade FOREIGN KEY REFERENCES CIDADES(cidade_id) CONSTRAINT nn_cidade_id NOT NULL,
);

CREATE TABLE PACOTES (
	pacote_id INT IDENTITY(1,1) CONSTRAINT pk_pacotes PRIMARY KEY,
	destinatario_id INT CONSTRAINT fk_pac_destinatarios FOREIGN KEY REFERENCES DESTINATARIOS(destinatario_id) CONSTRAINT nn_destinatario_id NOT NULL,
	numero_pedido INT CONSTRAINT nn_numero_pedido NOT NULL,
	cpf_recebedor BIGINT,
	tipo_do_pacote VARCHAR(50) CONSTRAINT nn_tipo_do_pacote NOT NULL,
	peso FLOAT CONSTRAINT nn_peso NOT NULL,
	foto_pacote BINARY,
);

CREATE TABLE PACOTES_SITUACOES (
	pacote_situacao_id INT IDENTITY(1,1) CONSTRAINT pk_pac_situacoes PRIMARY KEY,
	pacote_id INT CONSTRAINT fk_sit_pacotes FOREIGN KEY REFERENCES PACOTES(pacote_id) CONSTRAINT nn_pacote_id NOT NULL,
	situacao_id INT CONSTRAINT fk_sit_atual FOREIGN KEY REFERENCES SITUACOES(situacao_id) CONSTRAINT nn_situacao_a_id NOT NULL,
	data_alteracao DATETIME CONSTRAINT nn_sit_data_alteracao NOT NULL,
	alteracao_entregadores TINYINT CONSTRAINT nn_alteracao_etreg NOT NULL,
);

CREATE TABLE ENTREGADORES (
	entregador_id INT IDENTITY(1,1) CONSTRAINT pk_entregador PRIMARY KEY,
	usuario_id INT CONSTRAINT fk_entreg_usuarios FOREIGN KEY REFERENCES USUARIOS(usuario_id) CONSTRAINT nn_usuario_id NOT NULL,
	nome VARCHAR(100) CONSTRAINT nn_nome_entregadores NOT NULL,
	telefone VARCHAR(25) NOT NULL,
	foto_perfil BINARY,
);

CREATE TABLE PACOTES_ENTREGADORES (
	pacote_entregador_id INT IDENTITY(1,1) CONSTRAINT pk_pct_entg PRIMARY KEY,
	pacote_id INT CONSTRAINT fk_entreg_pacotes FOREIGN KEY REFERENCES PACOTES(pacote_id) CONSTRAINT nn_entreg_pacote_id NOT NULL,
	entregador_id INT CONSTRAINT fk_entreg_atual FOREIGN KEY REFERENCES ENTREGADORES(entregador_id) CONSTRAINT nn_entreg_a_id NOT NULL,
	data_alteracao DATETIME CONSTRAINT nn_entreg_usuario_id NOT NULL,
);

-- INSERTS

-- Inserts para USUARIOS
INSERT INTO USUARIOS (cpf, senha, usuario_admin)
VALUES 
(12345678900, 'senha123', 1),
(23456789011, 'senha456', 0),
(34567890122, 'senha789', 0),
(45678901233, 'senha101', 0),
(56789012344, 'senha112', 0);

-- Inserts para SITUACOES
INSERT INTO SITUACOES (descricao)
VALUES 
('Aguardando'),
('Entregue'),
('Devolvido'),
('Extraviado');

-- Inserts para ESTADOS
INSERT INTO ESTADOS (nome)
VALUES 
('Estado A'),
('Estado B'),
('Estado C'),
('Estado D'),
('Estado E');

-- Inserts para CIDADES
INSERT INTO CIDADES (nome, estado_id)
VALUES 
('Cidade A', 1),
('Cidade B', 2),
('Cidade C', 3),
('Cidade D', 4),
('Cidade E', 5);
go

-- Inserts para DESTINATARIOS

INSERT INTO DESTINATARIOS (nome, cpf, telefone, rua, bairro, numero, complemento, cep, cidade_id)
VALUES 
('Destinatario A', 12345678900, '111234567890', 'Rua A', 'Bairro A', 123, 'Complemento A', 12345678, 1),
('Destinatario B', 23456789011, '222345678901', 'Rua B', 'Bairro B', 234, 'Complemento B', 23456789, 2),
('Destinatario C', 34567890122, '333456789012', 'Rua C', 'Bairro C', 345, 'Complemento C', 34567890, 3),
('Destinatario D', 45678901233, '444567890123', 'Rua D', 'Bairro D', 456, 'Complemento D', 45678901, 4),
('Destinatario E', 56789012344, '555678901234', 'Rua E', 'Bairro E', 567, 'Complemento E', 56789012, 5);

-- Inserts para PACOTES
INSERT INTO PACOTES (destinatario_id, numero_pedido, cpf_recebedor, tipo_do_pacote, peso, foto_pacote)
VALUES 
(1, 123456, 12345678900, 'Eletrônicos', 2.5, NULL),
(2, 234567, 23456789011, 'Roupas', 1.0, NULL),
(3, 345678, 34567890122, 'Livros', 0.8, NULL),
(4, 456789, 45678901233, 'Móveis', 15.0, NULL),
(5, 567890, 56789012344, 'Alimentos', 5.2, NULL);

-- Inserts para PACOTES_ENTREGADORES
INSERT INTO PACOTES_ENTREGADORES (pacote_id, entregador_id, data_alteracao)
VALUES 
(1, 1, GETDATE()),
(1, 2, GETDATE()),
(2, 4, GETDATE()),
(2, 5, GETDATE()),
(3, 3, GETDATE());



/* trigger de insert em pacotes situações com base no pacotes entregadores:





*/



-- Inserts para PACOTES_SITUACOES
INSERT INTO PACOTES_SITUACOES (pacote_id, situacao_id, data_alteracao, alteracao_entregadores)
VALUES 
(1, 1, GETDATE(), 0),
(1, 2, GETDATE(), 0),
(2, 3, GETDATE(), 0),
(3, 4, GETDATE(), 0),
(2, 1, GETDATE(), 0);

-- Inserts para ENTREGADORES
INSERT INTO ENTREGADORES (usuario_id, nome, telefone, foto_perfil)
VALUES 
(1, 'Entregador A', '111234567890', NULL),
(2, 'Entregador B', '222345678901', NULL),
(3, 'Entregador C', '333456789012', NULL),
(4, 'Entregador D', '444567890123', NULL),
(5, 'Entregador E', '555678901234', NULL);



