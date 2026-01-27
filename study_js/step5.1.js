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
