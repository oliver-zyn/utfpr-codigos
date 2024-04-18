drop table if exists cliente;

create table Cliente (
	cod_cliente int primary key,
	nome varchar(100) not null,
	rg varchar(20) not null,
	cpf varchar(20) not null,
	salario money not null,
	estado_civil char(1) not null,
	sexo char(1) not null,
);

insert into Cliente
values(1,'Zequinha','77777777',' 77777777',17000.00,'C','M');
insert into Cliente
values(2,'Joaozinho','55555555',' 55555555',3000.00,'S','M');
insert into Cliente
values(3,'Mariazinha','33333333',' 33333333 ',18000.00,'C','F');
insert into Cliente
values(4,'Terezinha','99999999','99999999',5000.00,'S','F');

--EXERCICIOS

--Crie uma view chamada v_Cliente para a tabela Cliente, ocultando o atributo salario

DROP VIEW IF EXISTS v_Cliente
GO
CREATE VIEW v_Cliente AS
SELECT cod_cliente, nome, rg, cpf, estado_civil, sexo
FROM Cliente

--Consulte a view que você acabou de criar.

select * from v_Cliente

--Elabore uma consulta em v_Cliente que retorne todos os clientes solteiros e do sexo masculino

select * from v_Cliente where estado_civil = 'S' and sexo = 'M'

--Elabore uma consulta em v_Cliente que retorne todos os clientes com renda maior que R$13.500

--?

--Elabore uma consulta em v_Cliente que retorne a quantidade de homens casados

select count(estado_civil) AS homens_casados from v_Cliente where estado_civil = 'C' and sexo = 'M'

--Atualize o estado civil da V_cliente se o codcliente = 1

update v_Cliente set estado_civil = 'S' where cod_cliente = 1