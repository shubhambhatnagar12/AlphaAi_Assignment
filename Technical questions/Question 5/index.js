const express=require('express');
const app=express();
const path=require('path');
//mongo connection
const mongoose = require('mongoose');
mongoose.connect('mongodb+srv://mongouser:mongouser@cluster0.vyvot.mongodb.net/myFirstDatabase?retryWrites=true&w=majority', {useNewUrlParser: true, useUnifiedTopology: true})
.then(()=>{
    console.log("connection open")
})
.catch(err=>{
    console.log(err);
})
// schema for database
const coordinateSchema=new mongoose.Schema({
    Xcord:Number,
    Ycord:Number,
    timesta:String
});

// using schema to create click collection in mongo atlas
const Click=mongoose.model('Click',coordinateSchema);


app.use(express.static(path.join(__dirname,'public')));
app.use(express.json()) // for parsing application/json
app.use(express.urlencoded({ extended: true })) // for parsing application/x-www-form-urlencoded

app.set('view engine','ejs');
app.set('views',path.join(__dirname, '/views'));



app.get('/',(req,res)=>{
    res.render('web');
})

app.post('/',(req,res)=>{
    const {Xcor,Ycor,timest}=req.body;
    const clickinfo=new Click({Xcord:Xcor,Ycord:Ycor,timesta:timest});
    clickinfo.save();
    res.render('web');
})

app.listen(3000,()=>{
    console.log("listening on port 3000");
})