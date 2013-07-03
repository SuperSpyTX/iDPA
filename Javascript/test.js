// variables
var name = "Jim";
var num = 5;
var doubleNum = 1.6;
doubleNum = "LOL";

// output
document.write("Hello World")

// array
var array = ["this","that"]

// input
var num = prompt("Enter a number", "Enter number here:")

// function
function doSomething()
{
	console.log("write stuff");
}

var elseG = function()
{
	console.log("wat");
}

doSomething();

// objects
function Dog(nameIn, ageIn) {
	this.name = nameIn;
	this.age = ageIn;
	this.speak = function()
	{
		alert("woof");
	}
	this.getAge = function()
	{
		return this.age;
	}
}

var sparky = new Dog("Sparky", 2);
sparky.speak();

// add new function
Dog.prototype.sayHello = function()
{
	alert ('hello');
}