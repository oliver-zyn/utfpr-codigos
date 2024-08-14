USE TRIGGERS_EXEMPLOS

DROP TABLE IF EXISTS GARAGENS;
go
DROP TABLE IF EXISTS NEGOCIOS;
go
DROP TABLE IF EXISTS CONSUMIDORES;
go
DROP TABLE IF EXISTS REVENDEDORAS;
go
DROP TABLE IF EXISTS AUTOMOVEIS;
go

CREATE TABLE AUTOMOVEIS (
    CodAutomovel INT PRIMARY KEY IDENTITY(1,1),
    Ano INT NOT NULL,
    Fabricante VARCHAR(50) NOT NULL,
    Modelo VARCHAR(50) NOT NULL,
    Pais VARCHAR(50) NOT NULL,
    PrecoTabela DECIMAL(10, 2) NOT NULL
);
go

CREATE TABLE REVENDEDORAS (
    CNPJ CHAR(14) PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Proprietario VARCHAR(100) NOT NULL,
    Cidade VARCHAR(50) NOT NULL,
    Estado CHAR(2) NOT NULL
);
go

CREATE TABLE CONSUMIDORES (
    CPF CHAR(11) PRIMARY KEY,
    Nome VARCHAR(50) NOT NULL,
    Sobrenome VARCHAR(50) NOT NULL
);
go

CREATE TABLE NEGOCIOS (
	CodNegocios INT PRIMARY KEY IDENTITY(1,1),
    CPFComprador CHAR(11) NOT NULL,
    CNPJRevendedora CHAR(14) NOT NULL,
    CodAutomovel INT NOT NULL,
    AnoAuto INT NOT NULL,
    Data DATETIME NOT NULL,
    Preco DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (CPFComprador) REFERENCES CONSUMIDORES(CPF),
    FOREIGN KEY (CNPJRevendedora) REFERENCES REVENDEDORAS(CNPJ),
    FOREIGN KEY (CodAutomovel) REFERENCES AUTOMOVEIS(CodAutomovel)
);
go

CREATE TABLE GARAGENS (
	CodGaragens INT PRIMARY KEY IDENTITY(1,1),
    CNPJRevendedora CHAR(14) NOT NULL,
    CodAutomovel INT NOT NULL,
    AnoAutomovel INT NOT NULL,
    Quantidade INT NOT NULL,
    FOREIGN KEY (CNPJRevendedora) REFERENCES REVENDEDORAS(CNPJ),
    FOREIGN KEY (CodAutomovel) REFERENCES AUTOMOVEIS(CodAutomovel)
);
go

--INSERTS
INSERT INTO AUTOMOVEIS (Ano, Fabricante, Modelo, Pais, PrecoTabela)
VALUES (2020, 'Toyota', 'Corolla', 'Japão', 90000),
       (2021, 'Toyota', 'Corolla', 'Japão', 95000),
       (2022, 'Toyota', 'Corolla', 'Japão', 100000);

INSERT INTO REVENDEDORAS (CNPJ, Nome, Proprietario, Cidade, Estado)
VALUES ('12345678000199', 'Revenda A', 'Proprietário A', 'Cidade A', 'SP'),
       ('98765432000188', 'Revenda B', 'Proprietário B', 'Cidade B', 'RJ');

INSERT INTO CONSUMIDORES (CPF, Nome, Sobrenome)
VALUES ('11122233344', 'Cliente', 'Um'),
       ('55566677788', 'Cliente', 'Dois');

INSERT INTO NEGOCIOS (CPFComprador, CNPJRevendedora, CodAutomovel, AnoAuto, Data, Preco)
VALUES ('11122233344', '12345678000199', 1, 2020, '2024-01-10', 90000),
       ('11122233344', '12345678000199', 2, 2020, '2024-02-10', 95000),
       ('11122233344', '12345678000199', 3, 2019, '2024-03-10', 85000),
       ('11122233344', '12345678000199', 1, 2020, '2024-04-10', 90000),
       ('11122233344', '12345678000199', 2, 2020, '2024-05-10', 95000),
       ('11122233344', '12345678000199', 3, 2019, '2024-06-10', 85000),
       ('11122233344', '12345678000199', 1, 2020, '2024-07-10', 90000),
       ('11122233344', '12345678000199', 2, 2020, '2024-08-10', 95000),
       ('11122233344', '12345678000199', 3, 2019, '2024-09-10', 85000),
       ('11122233344', '12345678000199', 1, 2020, '2024-10-10', 90000);

--TRIGGER EX 1
go
CREATE TRIGGER TG_limite_compras_cliente
ON NEGOCIOS
FOR INSERT, UPDATE
AS
BEGIN
    DECLARE @CPFComprador VARCHAR(11)
    DECLARE @Ano INT

    SELECT @CPFComprador = inserted.CPFComprador, @Ano = YEAR(inserted.Data)
    FROM inserted

    IF (
        SELECT COUNT(*)
        FROM NEGOCIOS
        WHERE CPFComprador = @CPFComprador AND YEAR(Data) = @Ano
    ) > 10
    BEGIN
        PRINT ('O cliente não pode comprar mais que 10 carros em um ano!')
        ROLLBACK
    END
END;

INSERT INTO NEGOCIOS (CPFComprador, CNPJRevendedora, CodAutomovel, AnoAuto, Data, Preco)
VALUES ('11122233344', '12345678000199', 2, 2020, '2024-11-10', 95000);

UPDATE NEGOCIOS SET CPFComprador = '11122233344' WHERE AnoAuto = 2020

--TRIGGER EX 2
go
CREATE TRIGGER TG_modelo_preco_menor
ON AUTOMOVEIS
FOR INSERT, UPDATE
AS
BEGIN
    DECLARE @Modelo VARCHAR(50)
    DECLARE @Ano INT
	DECLARE @Preco DECIMAL(10, 2)

    SELECT @Modelo = inserted.Modelo, @Ano = inserted.Ano, @Preco = inserted.PrecoTabela
    FROM inserted

    IF (
        SELECT COUNT(*)
        FROM AUTOMOVEIS
        WHERE PrecoTabela > @Preco AND Ano < @Ano AND Modelo = @Modelo
    ) >= 1
    BEGIN
        PRINT ('O automóvel não pode ter um preço menor que o mesmo modelo nos anos anteriores!')
        ROLLBACK
    END
END;

INSERT INTO AUTOMOVEIS (Ano, Fabricante, Modelo, Pais, PrecoTabela)
VALUES (2023, 'Toyota', 'Corolla', 'Japão', 85000);

UPDATE AUTOMOVEIS
SET PrecoTabela = 85000
WHERE CodAutomovel = 3;

--TRIGGER EX 3
go
CREATE TRIGGER TG_negociacao_menor_preco_tabela
ON NEGOCIOS
FOR INSERT, UPDATE
AS
BEGIN
    DECLARE @CodAutomovel INT
    DECLARE @PrecoNegociacao DECIMAL(10, 2)
    DECLARE @PrecoTabela DECIMAL(10, 2)

    SELECT @CodAutomovel = inserted.CodAutomovel, @PrecoNegociacao = inserted.Preco
    FROM inserted

    SELECT @PrecoTabela = PrecoTabela
    FROM AUTOMOVEIS
    WHERE CodAutomovel = @CodAutomovel

    IF @PrecoNegociacao < 0.85 * @PrecoTabela
    BEGIN
        PRINT ('O preço da negociação não pode ser menor que 85%% do preço de tabela.')
        ROLLBACK
    END
END;

INSERT INTO NEGOCIOS (CPFComprador, CNPJRevendedora, CodAutomovel, AnoAuto, Data, Preco)
VALUES ('55566677788', '12345678000199', 1, 2020, '2024-02-10', 75000); -- 75000 é 83.33% de 90000, inválido

--TRIGGER EX 4
go
CREATE TRIGGER TG_verifica_data_negocios
ON NEGOCIOS
FOR INSERT
AS
BEGIN
    DECLARE @DataMaisRecente DATE

    SELECT @DataMaisRecente = MAX(Data)
    FROM NEGOCIOS

	IF @DataMaisRecente IS NULL
    BEGIN
        SET @DataMaisRecente = '1900-01-01 00:00:00.000'
    END

	UPDATE NEGOCIOS
    SET NEGOCIOS.Data = @DataMaisRecente
    FROM NEGOCIOS
    INNER JOIN inserted ON NEGOCIOS.CodNegocios = inserted.CodNegocios
    WHERE inserted.Data < @DataMaisRecente;
END;

INSERT INTO NEGOCIOS (CPFComprador, CNPJRevendedora, CodAutomovel, AnoAuto, Data, PreCo)
VALUES ('55566677788', '12345678000199', 1, 2020, '2023-06-11 00:00:00.000', 90000),
       ('55566677788', '12345678000199', 2, 2020, '2023-07-11 00:00:00.000', 95000);
