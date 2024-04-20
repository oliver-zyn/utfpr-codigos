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
DROP TABLE IF EXISTS SITUACOES;
DROP TABLE IF EXISTS USUARIOS;
DROP TABLE IF EXISTS TRANSPORTADORA;

-- CREATES

CREATE TABLE TRANSPORTADORA (
	cnpj BIGINT CONSTRAINT pk_transportadora PRIMARY KEY,
	nome VARCHAR(100) CONSTRAINT nn_nome_transportadora NOT NULL,
	razao_social VARCHAR(100) CONSTRAINT nn_razao_social NOT NULL,
	cep BIGINT CONSTRAINT nn_cep_transportadora NOT NULL,
	telefone VARCHAR(20) CONSTRAINT nn_telefone NOT NULL
);

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
);

CREATE TABLE PACOTES (
	pacote_id INT IDENTITY(1,1) CONSTRAINT pk_pacotes PRIMARY KEY,
	destinatario_id INT CONSTRAINT fk_pac_destinatarios FOREIGN KEY REFERENCES DESTINATARIOS(destinatario_id) CONSTRAINT nn_destinatario_id NOT NULL,
	numero_pedido INT CONSTRAINT nn_numero_pedido NOT NULL,
	cpf_recebedor BIGINT,
	foto_pacote BINARY,
);

CREATE TABLE PACOTES_SITUACOES (
	pacote_situacao_id INT IDENTITY(1,1) CONSTRAINT pk_pac_situacoes PRIMARY KEY,
	pacote_id INT CONSTRAINT fk_sit_pacotes FOREIGN KEY REFERENCES PACOTES(pacote_id) CONSTRAINT nn_pacote_id NOT NULL,
	situacao_anterior_id INT CONSTRAINT fk_sit_anterior FOREIGN KEY REFERENCES SITUACOES(situacao_id),
	situacao_atual_id INT CONSTRAINT fk_sit_atual FOREIGN KEY REFERENCES SITUACOES(situacao_id) CONSTRAINT nn_situacao_atual_id NOT NULL,
	data_alteracao DATETIME CONSTRAINT nn_sit_data_alteracao NOT NULL,
);

CREATE TABLE ENTREGADORES (
	entregador_id INT IDENTITY(1,1) CONSTRAINT pk_entregador PRIMARY KEY,
	usuario_id INT CONSTRAINT fk_entreg_usuarios FOREIGN KEY REFERENCES USUARIOS(usuario_id) CONSTRAINT nn_usuario_id NOT NULL,
	cpf BIGINT NOT NULL UNIQUE,
	nome VARCHAR(100) CONSTRAINT nn_nome_entregadores NOT NULL,
	telefone VARCHAR(25) NOT NULL,
	foto_perfil BINARY,
);

CREATE TABLE PACOTES_ENTREGADORES (
	pacote_entregador_id INT IDENTITY(1,1) CONSTRAINT pk_pct_entg PRIMARY KEY,
	pacote_id INT CONSTRAINT fk_entreg_pacotes FOREIGN KEY REFERENCES PACOTES(pacote_id) CONSTRAINT nn_entreg_pacote_id NOT NULL,
	entregador_anterior_id INT CONSTRAINT fk_entreg_anterior FOREIGN KEY REFERENCES ENTREGADORES(entregador_id),
	entregador_atual_id INT CONSTRAINT fk_entreg_atual FOREIGN KEY REFERENCES ENTREGADORES(entregador_id) CONSTRAINT nn_entreg_atual_id NOT NULL,
	data_alteracao DATETIME CONSTRAINT nn_entreg_usuario_id NOT NULL,
);

-- INSERTS

-- Insert para TRANSPORTADORA
-- A dona do app de gerenciamento.
INSERT INTO TRANSPORTADORA (cnpj, nome, razao_social, cep, telefone)
VALUES 
(89861037000118, 'Transportadora Comercial', 'Transportals', 12345678, '123456789');

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

-- Inserts para DESTINATARIOS
INSERT INTO DESTINATARIOS (nome, cpf, telefone, rua, bairro, numero, complemento, cep)
VALUES 
('Destinatario A', 12345678900, '111234567890', 'Rua A', 'Bairro A', 123, 'Complemento A', 12345678),
('Destinatario B', 23456789011, '222345678901', 'Rua B', 'Bairro B', 234, 'Complemento B', 23456789),
('Destinatario C', 34567890122, '333456789012', 'Rua C', 'Bairro C', 345, 'Complemento C', 34567890),
('Destinatario D', 45678901233, '444567890123', 'Rua D', 'Bairro D', 456, 'Complemento D', 45678901),
('Destinatario E', 56789012344, '555678901234', 'Rua E', 'Bairro E', 567, 'Complemento E', 56789012);

-- Inserts para PACOTES
INSERT INTO PACOTES (destinatario_id, numero_pedido, cpf_recebedor, foto_pacote)
VALUES 
(1, 123456, 12345678900, NULL),
(2, 234567, 23456789011, NULL),
(3, 345678, 34567890122, NULL),
(4, 456789, 45678901233, NULL),
(5, 567890, 56789012344, NULL);

-- Inserts para PACOTESSITUACOES
INSERT INTO PACOTES_SITUACOES (pacote_id, situacao_anterior_id, situacao_atual_id, data_alteracao)
VALUES 
(1, NULL, 1, GETDATE()),
(1, 1, 2, GETDATE()),
(2, 1, 3, GETDATE()),
(3, 1, 4, GETDATE()),
(2, 3, 1, GETDATE());

-- Inserts para ENTREGADORES
INSERT INTO ENTREGADORES (usuario_id, cpf, nome, telefone, foto_perfil)
VALUES 
(1, 12345678900, 'Entregador A', '111234567890', NULL),
(2, 23456789011, 'Entregador B', '222345678901', NULL),
(3, 34567890122, 'Entregador C', '333456789012', NULL),
(4, 45678901233, 'Entregador D', '444567890123', NULL),
(5, 56789012344, 'Entregador E', '555678901234', NULL);

-- Inserts para PACOTESENTREGADORES
INSERT INTO PACOTES_ENTREGADORES (pacote_id, entregador_anterior_id, entregador_atual_id, data_alteracao)
VALUES 
(1, NULL, 1, GETDATE()),
(1, 1, 2, GETDATE()),
(2, NULL, 4, GETDATE()),
(2, 4, 5, GETDATE()),
(3, NULL, 3, GETDATE());

-- Select para TRANSPORTADORA
SELECT cnpj, nome, razao_social, cep, telefone FROM TRANSPORTADORA;

-- Select para USUARIOS
SELECT usuario_id, cpf, senha, usuario_admin FROM USUARIOS;

-- Select para SITUACOES
SELECT situacao_id, descricao FROM SITUACOES;

-- Select para DESTINATARIOS
SELECT destinatario_id, nome, cpf, telefone, rua, bairro, numero, complemento, cep FROM DESTINATARIOS;

-- Select para PACOTES
SELECT pacote_id, destinatario_id, numero_pedido, cpf_recebedor, foto_pacote FROM PACOTES;

-- Select para PACOTES_SITUACOES
SELECT pacote_situacao_id, pacote_id, situacao_anterior_id, situacao_atual_id, data_alteracao FROM PACOTES_SITUACOES;

-- Select para ENTREGADORES
SELECT entregador_id, usuario_id, cpf, nome, telefone, foto_perfil FROM ENTREGADORES;

-- Select para PACOTES_ENTREGADORES
SELECT pacote_entregador_id, pacote_id, entregador_anterior_id, entregador_atual_id, data_alteracao FROM PACOTES_ENTREGADORES;
