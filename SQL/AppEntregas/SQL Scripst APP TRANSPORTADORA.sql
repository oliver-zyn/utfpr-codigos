USE Transportapp;
go

-- EXCLUSAO

DROP TABLE IF EXISTS PACOTESENTREGADORES;
DROP TABLE IF EXISTS PACOTESSITUACOES;
DROP TABLE IF EXISTS PACOTES;
DROP TABLE IF EXISTS ENTREGADORES;
DROP TABLE IF EXISTS DESTINATARIOS;
DROP TABLE IF EXISTS SITUACOES;
DROP TABLE IF EXISTS USUARIOS;
DROP TABLE IF EXISTS TRANSPORTADORA;

-- CREATES

CREATE TABLE TRANSPORTADORA (
	cnpj BIGINT IDENTITY(1,1) CONSTRAINT pk_Transport PRIMARY KEY NOT NULL,
	nome VARCHAR(100) NOT NULL,
	razao_social VARCHAR(100) NOT NULL,
	cep BIGINT NOT NULL,
	telefone VARCHAR(20) NOT NULL
);

CREATE TABLE USUARIOS (
	usuario_id INT IDENTITY(1,1) CONSTRAINT pk_usuario PRIMARY KEY NOT NULL,
	cpf BIGINT NOT NULL UNIQUE,
	senha VARCHAR(100) NOT NULL,
	admin_Us TINYINT NOT NULL,
);

CREATE TABLE SITUACOES (
	situacao_id INT IDENTITY(1,1) CONSTRAINT pk_situacoes PRIMARY KEY NOT NULL,
	desccricao VARCHAR(10) NOT NULL, 
);

CREATE TABLE DESTINATARIOS (
	destinatario_id INT IDENTITY(1,1) CONSTRAINT pk_dest PRIMARY KEY NOT NULL,
	nome VARCHAR(100) NOT NULL,
	cpf BIGINT NOT NULL UNIQUE,
	telefone VARCHAR(25) NOT NULL,
	rua VARCHAR(100) NOT NULL,
	bairro VARCHAR(100) NOT NULL,
	numero INT NOT NULL,
	complemento VARCHAR(50),
	cep BIGINT NOT NULL,
);

CREATE TABLE PACOTES (
	pacote_id INT IDENTITY(1,1) CONSTRAINT pk_pacotes PRIMARY KEY NOT NULL,
	destinatario_id INT CONSTRAINT fk_dest_id FOREIGN KEY REFERENCES DESTINATARIOS(destinatario_id) NOT NULL,
	numero_pedido INT NOT NULL,
	cpf_recebedor BIGINT,
	foto_pacote BINARY,
);

CREATE TABLE PACOTESSITUACOES (
	pacote_situacao_id INT IDENTITY(1,1) CONSTRAINT pk_pct_sit PRIMARY KEY NOT NULL,
	pacote_id INT CONSTRAINT fk_pacote_id_SIT FOREIGN KEY REFERENCES PACOTES(pacote_id) NOT NULL,
	situacao_anterior_id INT CONSTRAINT fk_sitAnt_id FOREIGN KEY REFERENCES SITUACOES(situacao_id) NOT NULL,
	situacao_atual_id INT CONSTRAINT fk_sitAtu_id FOREIGN KEY REFERENCES SITUACOES(situacao_id) NOT NULL,
	data_alteracao DATETIME NOT NULL,
);

CREATE TABLE ENTREGADORES (
	entregador_id INT IDENTITY(1,1) CONSTRAINT pk_entregador PRIMARY KEY NOT NULL,
	usuario_id INT CONSTRAINT fk_usuario_id FOREIGN KEY REFERENCES USUARIOS(usuario_id) NOT NULL,
	cpf BIGINT NOT NULL UNIQUE,
	nome VARCHAR(100) NOT NULL,
	telefone VARCHAR(25) NOT NULL,
	foto_perfil BINARY,
);

CREATE TABLE PACOTESENTREGADORES (
	pacote_entregador_id INT IDENTITY(1,1) CONSTRAINT pk_pct_entg PRIMARY KEY NOT NULL,
	pacote_id INT CONSTRAINT fk_pacote_id_ENTG FOREIGN KEY REFERENCES PACOTES(pacote_id) NOT NULL,
	entregador_anterior_id INT CONSTRAINT fk_entgAnt_id FOREIGN KEY REFERENCES SITUACOES(situacao_id) NOT NULL,
	entregador_atual_id INT CONSTRAINT fk_entgAtu_id FOREIGN KEY REFERENCES SITUACOES(situacao_id) NOT NULL,
	data_alteracao DATETIME NOT NULL,
);

-- INSERTS

-- Inserts para TRANSPORTADORA
INSERT INTO TRANSPORTADORA (nome, razao_social, cep, telefone)
VALUES 
('Transportadora A', 'Raz�o Social A', 12345678, '123456789'),
('Transportadora B', 'Raz�o Social B', 23456789, '234567890'),
('Transportadora C', 'Raz�o Social C', 34567890, '345678901'),
('Transportadora D', 'Raz�o Social D', 45678901, '456789012'),
('Transportadora E', 'Raz�o Social E', 56789012, '567890123');

-- Inserts para USUARIOS
INSERT INTO USUARIOS (cpf, senha, admin_Us)
VALUES 
(12345678900, 'senha123', 1),
(23456789011, 'senha456', 0),
(34567890122, 'senha789', 0),
(45678901233, 'senha101', 0),
(56789012344, 'senha112', 0);

-- Inserts para SITUACOES
INSERT INTO SITUACOES (desccricao)
VALUES 
('Entregue'),
('Devolvido'),
('Pendente'),
('Extraviado');

-- Inserts para DESTINATARIOS
INSERT INTO DESTINATARIOS (nome, cpf, telefone, rua, bairro, numero, complemento, cep)
VALUES 
('Destinat�rio A', 12345678900, '111234567890', 'Rua A', 'Bairro A', 123, 'Complemento A', 12345678),
('Destinat�rio B', 23456789011, '222345678901', 'Rua B', 'Bairro B', 234, 'Complemento B', 23456789),
('Destinat�rio C', 34567890122, '333456789012', 'Rua C', 'Bairro C', 345, 'Complemento C', 34567890),
('Destinat�rio D', 45678901233, '444567890123', 'Rua D', 'Bairro D', 456, 'Complemento D', 45678901),
('Destinat�rio E', 56789012344, '555678901234', 'Rua E', 'Bairro E', 567, 'Complemento E', 56789012);

-- Inserts para PACOTES
INSERT INTO PACOTES (destinatario_id, numero_pedido, cpf_recebedor, foto_pacote)
VALUES 
(1, 123456, 12345678900, NULL),
(2, 234567, 23456789011, NULL),
(3, 345678, 34567890122, NULL),
(4, 456789, 45678901233, NULL),
(5, 567890, 56789012344, NULL);

-- Inserts para PACOTESSITUACOES
INSERT INTO PACOTESSITUACOES (pacote_id, situacao_anterior_id, situacao_atual_id, data_alteracao)
VALUES 
(1, 1, 2, GETDATE()),
(2, 1, 2, GETDATE()),
(3, 1, 2, GETDATE()),
(4, 1, 2, GETDATE()),
(5, 1, 2, GETDATE());

-- Inserts para ENTREGADORES
INSERT INTO ENTREGADORES (usuario_id, cpf, nome, telefone, foto_perfil)
VALUES 
(1, 12345678900, 'Entregador A', '111234567890', NULL),
(2, 23456789011, 'Entregador B', '222345678901', NULL),
(3, 34567890122, 'Entregador C', '333456789012', NULL),
(4, 45678901233, 'Entregador D', '444567890123', NULL),
(5, 56789012344, 'Entregador E', '555678901234', NULL);

-- Inserts para PACOTESENTREGADORES
INSERT INTO PACOTESENTREGADORES (pacote_id, entregador_anterior_id, entregador_atual_id, data_alteracao)
VALUES 
(1, 1, 2, GETDATE()),
(2, 1, 2, GETDATE()),
(3, 1, 2, GETDATE()),
(4, 1, 2, GETDATE()),
(5, 1, 2, GETDATE());

