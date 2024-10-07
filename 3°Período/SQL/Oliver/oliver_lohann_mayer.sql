--OLIVER LOHANN MAYER - 2562502

--a) Crie um comando de seleção que liste os bois que nasceram entre o dia 01 de janeiro e a data de hoje, o select deve exibir dos bois: nome, data de nascimento, cor e raça e as informações dos seus genitores: nome, cor e raça, se não houver genitores, o boi deve ser exibido

SELECT 
	G.NOME, 
	G.DATA_NASCIMENTO, 
	C.DESCRICAO AS COR, 
	R.DESCRICAO AS RACA, 
	GNT.NOME AS NOME_GENITOR,
	CGNT.DESCRICAO AS COR_GENITOR, 
	RGNT.DESCRICAO AS RACA_GENITOR,
	GNTA.NOME AS NOME_GENITORA,
	CGNTA.DESCRICAO AS COR_GENITORA, 
	RGNTA.DESCRICAO AS RACA_GENITORA
FROM GADO G
INNER JOIN COR C ON C.IDCOR = G.IDCOR
INNER JOIN RACA R ON R.IDRACA = G.IDRACA
LEFT JOIN GADO GNT ON GNT.IDGADO = G.IDGENITOR
LEFT JOIN COR CGNT ON CGNT.IDCOR = GNT.IDCOR
LEFT JOIN RACA RGNT ON RGNT.IDRACA = GNT.IDRACA
LEFT JOIN GADO GNTA ON GNTA.IDGADO = G.IDGENITORA
LEFT JOIN COR CGNTA ON CGNTA.IDCOR = GNTA.IDCOR
LEFT JOIN RACA RGNTA ON RGNTA.IDRACA = GNTA.IDRACA
WHERE G.DATA_NASCIMENTO between '2024-01-01' and GETDATE();

--b) exiba o nome, data de nascimento de todos os animais que nunca estiveram no pasto "BLUE"

SELECT NOME, DATA_NASCIMENTO FROM GADO G
INNER JOIN GADO_PASTO GP ON GP.IDGADO = G.IDGADO
INNER JOIN PASTO P ON P.IDPASTO = GP.IDPASTO
WHERE GP.IDGADO NOT IN (SELECT IDGADO FROM GADO_PASTO WHERE IDPASTO = 1)

--c) Mostre a média de peso no abate por raça, e ordene o resultado pela média. Exiba somente raças cuja média seja maior que 350 quilos

SELECT R.DESCRICAO AS RACA, avg(PESO_ABATE) AS MEDIA_PESO_ABATE FROM GADO
INNER JOIN RACA R ON R.IDRACA = GADO.IDRACA
GROUP BY R.DESCRICAO
HAVING avg(PESO_ABATE) > 350
ORDER BY MEDIA_PESO_ABATE;

--d) Exiba todos os atributos da tabela pasto, porém apenas pastos que fiquem na 'FLORESTA MÁGICA'

SELECT IDPASTO, NOMEPASTO, LOCALIZACAO, CAPACIDADE FROM PASTO
WHERE LOCALIZACAO = 'FLORESTA MÁGICA';

--e) Exiba o nome do animal e o número total de pastos que este animal já esteve

SELECT NOME, count(DISTINCT IDPASTO) from GADO G
INNER JOIN GADO_PASTO GP ON GP.IDGADO = G.IDGADO
GROUP BY NOME;

--f) Exiba os animais e a idade dos animais em dias, mas exiba somente aqueles que tenham nascido há mais de 100 dias

SELECT NOME, DATEDIFF(DAY, DATA_NASCIMENTO, GETDATE()) AS IDADE_EM_DIAS FROM GADO
WHERE DATEDIFF(DAY, DATA_NASCIMENTO, GETDATE()) > 100;

--g) Exiba uma listagem contendo o nome de todos os animais que são genitor ou genitora de outros animais. Utilize operadores de conjuntos para resolver a questão. Não devem ser exibidos genitores duplicadores/repetidos

SELECT DISTINCT G.NOME AS 'GENITOR(A)' FROM GADO G
INNER JOIN GADO GNT ON GNT.IDGENITOR = G.IDGADO
UNION
SELECT DISTINCT G.NOME AS 'GENITOR(A)' FROM GADO G
INNER JOIN GADO GNTA ON GNTA.IDGENITORA = G.IDGADO;

--h) Lista nome, cor e raça, bem como os dados das vacinas, como nome, data aplicação, data da próxima vacina. O nome, a cor e a raça devem ser retornados em um mesmo campo, no seguinte formato: 'NOME - COR - RAÇA', e este 
--deve ser apelidado de Animal. Ordene pelo campo Animal e pela data de aplicação da vacina de forma decrescente

SELECT CONCAT(G.NOME, ' - ', C.DESCRICAO, ' - ', R.DESCRICAO) AS ANIMAL, V.NOME AS NOME_VACINA, GV.DATA_APLICACAO, GV.DATA_PROXIMA FROM GADO G
INNER JOIN COR C ON C.IDCOR = G.IDCOR
INNER JOIN RACA R ON R.IDRACA = G.IDRACA
INNER JOIN GADO_VACINA GV ON GV.IDGADO = G.IDGADO
INNER JOIN VACINA V ON V.IDVACINA = GV.IDVACINA
ORDER BY ANIMAL, GV.DATA_APLICACAO DESC;

--i) Exiba o nome, raça, cor de todos os animais que estiveram no pasto 'GREY' e que nunca estiveram no pasto 'GREEN'

SELECT G.NOME, R.DESCRICAO AS RACA, C.DESCRICAO AS COR, P.NOMEPASTO FROM GADO G
INNER JOIN COR C ON C.IDCOR = G.IDCOR
INNER JOIN RACA R ON R.IDRACA = G.IDRACA
INNER JOIN GADO_PASTO GP ON GP.IDGADO = G.IDGADO
INNER JOIN PASTO P ON P.IDPASTO = GP.IDPASTO
WHERE GP.IDGADO NOT IN (SELECT IDGADO FROM GADO_PASTO WHERE IDPASTO = 2) AND GP.IDPASTO = 3

SELECT * FROM PASTO

--j) Elabore um select que exiba se existem animais gêmeos, considere que para ser gêmenos eles devem ter nascido no mesmo dia e possuir os mesmos genitores

SELECT G.NOME, G2.NOME FROM GADO G
INNER JOIN GADO G2 ON G2.DATA_NASCIMENTO = G.DATA_NASCIMENTO 
	AND G2.IDGADO <> G.IDGADO 
	AND G2.IDGENITOR = G.IDGENITOR 
	AND G2.IDGENITORA = G.IDGENITORA;