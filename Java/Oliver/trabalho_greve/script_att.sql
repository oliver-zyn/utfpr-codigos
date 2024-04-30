CREATE TABLE participantes (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
	cpf varchar(11) NOT NULL,
	telefone varchar(20)
);

CREATE TABLE palestrantes (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    descricao TEXT NOT NULL,
	area_atuacao VARCHAR(255) NOT NULL
);

CREATE TABLE locais (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    endereco VARCHAR(255) NOT NULL,
    cidade VARCHAR(255) NOT NULL,
    capacidade INT NOT NULL
);

CREATE TABLE eventos (
    id SERIAL PRIMARY KEY,
    titulo VARCHAR(255) NOT NULL,
    descricao TEXT,
    max_participantes INT NOT NULL,
	data_evento TIMESTAMP NOT NULL,
    palestrante_id INT NOT NULL,
	local_id INT NOT NULL,
    CONSTRAINT FK_evento_palestrante FOREIGN KEY (palestrante_id) REFERENCES palestrantes(id),
	CONSTRAINT FK_evento_local FOREIGN KEY (local_id) REFERENCES locais(id)
);

CREATE TABLE ingressos (
    id SERIAL PRIMARY KEY,
    preco FLOAT NOT NULL,
    quantidade INT NOT NULL,
    tipo VARCHAR(255) NOT NULL,
	evento_id INT NOT NULL,
	CONSTRAINT FK_ingressos_evento FOREIGN KEY (evento_id) REFERENCES eventos(id)
);

CREATE TABLE ingressos_participantes (
    id SERIAL PRIMARY KEY,
    participante_id INT NOT NULL,
    ingresso_id INT NOT NULL,
    CONSTRAINT FK_ingressosParticipantes_participante FOREIGN KEY (participante_id) REFERENCES participantes(id),
    CONSTRAINT FK_ingressosParticipantes_ingresso FOREIGN KEY (ingresso_id) REFERENCES ingressos(id)
);

CREATE TABLE check_ins (
    id SERIAL PRIMARY KEY,
    ingresso_id INT NOT NULL,
	data_check_in TIMESTAMP,
    CONSTRAINT FK_checkIn_ingresso FOREIGN KEY (ingresso_id) REFERENCES ingressos(id)
);

select * from participantes
