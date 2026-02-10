const weather = "";

if (weather === "rainy") {
  console.log("возьмите зонт");
} else if (weather === "sunny") {
  console.log("возьмите очки");
} else if (weather === "cold") {
  console.log("одевайтесь теплее");
} else {
  console.log("хорошего вам дня");
}

const size = " Маленькая";

if (size === null || size === undefined) {
  console.log("Вы не выбрали размер!");
} else if (size.trim().toLocaleLowerCase() === "маленькая") {
  console.log("Маленькая пицца стоит 800 руб.");
} else if (size.trim().toLocaleLowerCase() === "средняя") {
  console.log("Средняя пицца стоит 1200 руб.");
} else if (size.trim().toLocaleLowerCase() === "большая") {
  console.log("Большая пицца стоит 1500 руб.");
} else {
  console.log("Такого размера у нас нет!");
}

const animal = "";

switch (animal) {
  case "кошка":
  case "собака":
  case "хомяк":
    console.log("Это домашнее животное.");
    break;
  case "рыба":
  case "птица":
  case "черепаха":
  case "ящерица":
    console.log("Это экзотический питомец.");
    break;
  default:
    console.log("Это мне неизвестно.");
    break;
}
const arr = [[5, 32, 15, 9], [83, -22, 7], [], [81, 10, 0]];
let sum = 0;
for (let i = 0; i < arr.length; i++) {
  for (let j = 0; j < arr[i].length; j++) {
    if (arr[i][j] > 0) {
      sum += arr[i][j];
    }
  }
}
console.log(sum);

function generateChessBoard(x) {
  const arr = [];
  for (let i = 0; i < x; i++) {
    let innderArr = [];
    for (let j = 0; j < x; j++) {
      if ((i + j) % 2 === 0) {
        innderArr.push(".");
      } else {
        innderArr.push("#");
      }
    }
    arr.push(innderArr);
  }
  return arr;
}

console.log(generateChessBoard(3));
console.log(generateChessBoard(4));
console.log(generateChessBoard(5));

for (let i = 0; i < 5; i++) {
  if (i % 2 === 0) {
    // если число четное 
    continue;
  }
  console.log("Тест");
}
