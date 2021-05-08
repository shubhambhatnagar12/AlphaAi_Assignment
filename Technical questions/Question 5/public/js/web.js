    const xcor=document.getElementById("Xcor");
    const ycor=document.getElementById("Ycor");
    const timest=document.getElementById("timest");

    document.addEventListener('click', click);
    function click(ob){
        
        //for changing color of screen on click
        const randomColor=randomcolorgen();
        document.body.style.backgroundColor=randomColor;
        
        datevalues=new Date();
        xcor.value=ob.screenX;
        ycor.value=ob.screenY;
        timest.value=datevalues;
        
        console.log("x cordinate = ",ob.screenX);
        console.log("y cordinate = ",ob.screenY);
        console.log("timestamp = ",datevalues)

        //submitting form on clicking
        document.getElementById("valueForm").submit();

    }

    function randomcolorgen (){
        const r = Math.floor(Math.random()*256);
        const g = Math.floor(Math.random()*256);
        const b = Math.floor(Math.random()*256);
        return `rgb(${r}, ${g}, ${b})`;
    
    }