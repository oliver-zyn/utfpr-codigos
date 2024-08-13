const btSalvar = document.getElementById('btSave');
console.log(btSalvar);

btSalvar.addEventListener('click', function(e){
    e.preventDefault();
    
    let nome = document.getElementById('name').value;
    let preco = document.getElementById('price').value;
    
    const produto = {
        nomeProd: nome,
        precoProd: preco,
        quantidade: 1 
    }
    
})