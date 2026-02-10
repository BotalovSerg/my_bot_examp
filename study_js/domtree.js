const myLink = document.querySelector("a");

console.log(myLink);
console.log(myLink.href);
console.log(myLink.textContent);
myLink.textContent = "Личный кабинет";
myLink.classList.add("selected");
// myLink.classList.remove('selected');

const allItems = document.querySelectorAll(".item");
console.log(allItems);

for (const element of allItems) {
  element.classList.add("selected");
}
const newBtn = document.createElement("button");
newBtn.textContent = "Click me";
document.body.append(newBtn);

const newBtndiv = document.createElement("button");
newBtndiv.textContent = "Click me div";

const newsBlock = document.querySelector(".news");

newsBlock.append(newBtndiv);

const specialItem = document.querySelector("#special-offer");

specialItem.classList.add("selected");
