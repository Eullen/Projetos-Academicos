class Heroe{

    constructor(nome,poder,item){
        this.nome = nome;
        this.poder = poder;
        this.item = item;
        this.vida = 100;
    }
    atacar(){
        this.vida = 0;
        console.log("Morreu");
    }
}

var heroe = new Heroe("SuperTrouxa","Ficar na Frindone",["Chocolate","Flores","Mochila da menina"]);
heroe.atacar();

class Mago extends Heroe{
       
    constructor(magias){
        super();
        this.magias= magias;
        this.init();
        
    }
    init(){
        var botao = document.querySelector("#sumonar");
        // //evento de click - similar botao.onclick
        // botao.addEventListener("click",()=>{
        //     console.log("BURN BABYLON");
        // });

        botao.addEventListener("click",this.sumonar);
    }
    sumonar(){
        var box = document.querySelector('.box');
        box.classList.add('animada');
        window.setTimeout(()=>{
            box.classList.remove('animada')
        },3000);
    }
}

var mago = new Mago(['FireBall']);
