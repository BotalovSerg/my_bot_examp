const nameConst = "Const";
let name_1 = "Vars";

const myName = "Sergey";
const age = 39;
const isProgrammer = true;
const cars = ["kia"];
const infoPet = {
  dog1: "Kina",
  dog2: "Pena",
};
const person = {
  myName,
  age,
  isProgrammer,
  cars,
};
console.log(person);

function getUsername() {
  return "BotaSerg";
}

const getName = () => {
  return `My name ${myName}`;
};

console.log(getName());

const tetsFunc = (arg1, arg2) => {
  console.log(arg1, arg2);
};

tetsFunc("One", "Two");

const showPerson = (dataPerson) => {
  console.log(`Name ${dataPerson.myName}`);
  console.log(`Age ${dataPerson.age}`);
  console.log(`Programmer ${dataPerson.isProgrammer}`);
  console.log(dataPerson.cars);
};

showPerson(person);

function getStatus(person) {
  if (person.age > 18) {
    console.log("Cool");
  }
}

const getStatusTernar = (age) => {
  return age < 14 ? "Children" : "Adult";
};

console.log(getStatusTernar(15));
