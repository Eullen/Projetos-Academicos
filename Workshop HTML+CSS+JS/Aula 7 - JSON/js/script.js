
//pegar elemento
var botao = document.querySelector("#btnConsultar");

function requestEndereco(cep){

    fetch("https://viacep.com.br/ws/"+cep+"/json")
    .then((response)=>response.json())
    .then((json)=> {
        // formatarHTML(json);
        var tabelaHead = document.querySelector("#tblEndereco thead tr"); 
        var tabelaBody = document.querySelector("#tblEndereco tbody tr"); 
        tabelaHead.innerHTML="";
        tabelaBody.innerHTML="";
        for (var key in json) {
            var valor = json[key];
            //cria tag via js
            var th = document.createElement("th");
            th.innerText = propriedade;
            
            var td = document.createElement("td");
            td.innerText =conteudo;
              
            //inserir no  documento
            tabelaHead.appendChild("th");
            tabelaBody.appendChild("td");

            console.log("A chave é: "+key);
            console.log("O valor é:"+json[key]);
            console.log("----------");
        }
    });
}

// jito pedreiro
function formatarHTML(json){
    
    var respostas = document.querySelector(".formResposta");
    respostas.style.display="block";
    
    var log = document.querySelector("#logradouro");
    var comp = document.querySelector("#complemento");
    var bairro = document.querySelector("#bairro");
    var local = document.querySelector("#localidade");
    var uf = document.querySelector("#uf");

    log.value = json["logradouro"];
    comp.value = json["complemento"];
    bairro.value =json["bairro"];
    local.value = json["localidade"];
    uf.value = json["uf"];

}

function handleSubmit(ev){
    ev.preventDefault();
    var cep = document.querySelector("#CEP");
    requestEndereco(cep.value);
}

//pegar evento
botao.onclick = handleSubmit;